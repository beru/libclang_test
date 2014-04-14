
#include <stdio.h>
#include <vector>
#include <string>

#include "clang-c\Index.h"
#pragma comment(lib, "libclang.lib")

std::vector<CXString> argNames;

const char* getArgNameCString(char* buff, const CXString& name, int idx)
{
	const char* nameStr = clang_getCString(name);
	if (strlen(nameStr) == 0) {
		sprintf(buff, "arg%d", idx);
		nameStr = buff;
	}
	return nameStr;
}

enum CXChildVisitResult
	visitor(
		CXCursor cursor,
		CXCursor parent,
		CXClientData client_data
	)
{
	enum CXCursorKind kind = clang_getCursorKind(cursor);
#if 0
	CXString str = clang_getCursorKindSpelling(kind);
	printf("%s\n", getCString(str));
	disposeString(str);
#endif
	if (kind != CXCursor_FunctionDecl) {
		return CXChildVisit_Recurse;
	}

	CXString str;
	CXType retType = clang_getCursorResultType(cursor);
	str = clang_getTypeSpelling(retType);
	printf("%s\n", clang_getCString(str));
	clang_disposeString(str);

	CXString funcSpelling = clang_getCursorSpelling(cursor);
	const char* funcSpellingCStr = clang_getCString(funcSpelling);
	const char* prefix = (const char*) client_data;
	size_t prefixLen = strlen(prefix);
	if (strncmp(prefix, funcSpellingCStr, prefixLen) == 0) {
		funcSpellingCStr += prefixLen;
	}
	printf("\t%s(\n", funcSpellingCStr);

	int nArgs = clang_Cursor_getNumArguments(cursor);
	argNames.resize(nArgs);
	char nameBuff[32];
	for (int i=0; i<nArgs; ++i) {
		CXCursor arg = clang_Cursor_getArgument(cursor, i);
		CXType type = clang_getCursorType(arg);
		CXString typeSpelling = clang_getTypeSpelling(type);
		CXString name = clang_getCursorDisplayName(arg);
		argNames[i] = name;
		const char* nameStr = getArgNameCString(nameBuff, name, i);
		printf("\t\t%s %s", clang_getCString(typeSpelling), nameStr);
		clang_disposeString(typeSpelling);
		if (i+1 != nArgs) {
			printf(",");
		}
		printf("\n");
	}
	printf("\t)\n");
	printf("{\n");
	printf("\t");
	if (retType.kind != CXType_Void) {
		printf("return ");
	}
	printf("%s(", funcSpelling);

	for (int i=0; i<nArgs; ++i) {
		const char* nameStr = getArgNameCString(nameBuff, argNames[i], i);
		printf("%s", nameStr);
		if (i+1 != nArgs) {
			printf(", ");
		}
		clang_disposeString(argNames[i]);
	}

	printf(");\n");
	printf("}\n");
	clang_disposeString(funcSpelling);
	return CXChildVisit_Continue;
}

/*
	ƒRƒ}ƒ“ƒhˆø”‚Ì—á

	..\test.ast clang_ >> test.result.h

*/

int main(int argc, char* argv[])
{

	CXString version = clang_getClangVersion();
	printf("%s\n", clang_getCString(version));
	clang_disposeString(version);

	CXIndex index = clang_createIndex(1, 1);
	CXTranslationUnit tu = clang_createTranslationUnit(index, argv[1]);
	if (tu) {
		clang_visitChildren(clang_getTranslationUnitCursor(tu), visitor, argv[2]);
		clang_disposeTranslationUnit(tu);
	}

	clang_disposeIndex(index);

	return 0;

}
