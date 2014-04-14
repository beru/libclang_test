
#include <stdio.h>
#include <vector>
#include <string>

#pragma comment(lib, "libclang.lib")

#include "libclang_cpp/libclang_cpp.h"
using namespace libclang_cpp;

std::vector<CXString> argNames;

// 引数名が空の事があるので、名前を用意
const char* getArgNameCString(char* buff, const CXString& name, int idx)
{
	const char* nameStr = getCString(name);
	if (strlen(nameStr) == 0) {
		sprintf(buff, "arg%d", idx);
		nameStr = buff;
	}
	return nameStr;
}

// 接頭辞を取り除く
// 関数ポインタは何やら未対応っぽい
enum CXChildVisitResult
	visitor(
		CXCursor cursor,
		CXCursor parent,
		CXClientData client_data
	)
{
	enum CXCursorKind kind = getCursorKind(cursor);
#if 0
	CXString str = getCursorKindSpelling(kind);
	printf("%s\n", getCString(str));
	disposeString(str);
#endif
	if (kind != CXCursor_FunctionDecl) {
		return CXChildVisit_Recurse;
	}

	CXString str;
	CXType retType = getCursorResultType(cursor);
	str = getTypeSpelling(retType);
	printf("%s\n", getCString(str));
	disposeString(str);

	CXString funcSpelling = getCursorSpelling(cursor);
	const char* funcSpellingCStr = getCString(funcSpelling);
	const char* prefix = (const char*) client_data;
	size_t prefixLen = strlen(prefix);
	if (strncmp(prefix, funcSpellingCStr, prefixLen) == 0) {
		funcSpellingCStr += prefixLen;
	}
	printf("\t%s(\n", funcSpellingCStr);

	int nArgs = Cursor_getNumArguments(cursor);
	argNames.resize(nArgs);
	char nameBuff[32];
	for (int i=0; i<nArgs; ++i) {
		CXCursor arg = Cursor_getArgument(cursor, i);
		CXType type = getCursorType(arg);
		CXString typeSpelling = getTypeSpelling(type);
		CXString name = getCursorDisplayName(arg);
		argNames[i] = name;
		const char* nameStr = getArgNameCString(nameBuff, name, i);
		printf("\t\t%s %s", getCString(typeSpelling), nameStr);
		disposeString(typeSpelling);
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
		disposeString(argNames[i]);
	}

	printf(");\n");
	printf("}\n");
	disposeString(funcSpelling);
	return CXChildVisit_Continue;
}

/*
	コマンド引数の例

	..\test.ast clang_ >> test.result.h

*/
int main(int argc, char* argv[])
{

	CXString version = getClangVersion();
	printf("%s\n", getCString(version));
	disposeString(version);

	CXIndex index = createIndex(1, 1);
	CXTranslationUnit tu = createTranslationUnit(index, argv[1]);
	if (tu) {
		visitChildren(getTranslationUnitCursor(tu), visitor, argv[2]);
		disposeTranslationUnit(tu);
	}
	disposeIndex(index);
	return 0;

}

