#include "clang-c\Index.h"

#pragma comment(lib, "libclang.lib")

// LibClang ÇÃ C++ óp wrapper
// íPÇ…ê⁄ì™é´ÇÃ clang_ ÇéÊÇËèúÇ¢ÇƒÇ¢ÇÈÇæÇØ

namespace libclang_cpp {

const char *
	getCString(
		CXString string
	)
{
	return clang_getCString(string);
}
void
	disposeString(
		CXString string
	)
{
	clang_disposeString(string);
}
CXIndex
	createIndex(
		int excludeDeclarationsFromPCH,
		int displayDiagnostics
	)
{
	return clang_createIndex(excludeDeclarationsFromPCH, displayDiagnostics);
}
void
	disposeIndex(
		CXIndex index
	)
{
	clang_disposeIndex(index);
}
void
	CXIndex_setGlobalOptions(
		CXIndex arg0,
		unsigned int options
	)
{
	clang_CXIndex_setGlobalOptions(arg0, options);
}
unsigned int
	CXIndex_getGlobalOptions(
		CXIndex arg0
	)
{
	return clang_CXIndex_getGlobalOptions(arg0);
}
CXString
	getFileName(
		CXFile SFile
	)
{
	return clang_getFileName(SFile);
}
time_t
	getFileTime(
		CXFile SFile
	)
{
	return clang_getFileTime(SFile);
}
int
	getFileUniqueID(
		CXFile file,
		CXFileUniqueID * outID
	)
{
	return clang_getFileUniqueID(file, outID);
}
unsigned int
	isFileMultipleIncludeGuarded(
		CXTranslationUnit tu,
		CXFile file
	)
{
	return clang_isFileMultipleIncludeGuarded(tu, file);
}
CXFile
	getFile(
		CXTranslationUnit tu,
		const char * file_name
	)
{
	return clang_getFile(tu, file_name);
}
CXSourceLocation
	getNullLocation(
	)
{
	return clang_getNullLocation();
}
unsigned int
	equalLocations(
		CXSourceLocation loc1,
		CXSourceLocation loc2
	)
{
	return clang_equalLocations(loc1, loc2);
}
CXSourceLocation
	getLocation(
		CXTranslationUnit tu,
		CXFile file,
		unsigned int line,
		unsigned int column
	)
{
	return clang_getLocation(tu, file, line, column);
}
CXSourceLocation
	getLocationForOffset(
		CXTranslationUnit tu,
		CXFile file,
		unsigned int offset
	)
{
	return clang_getLocationForOffset(tu, file, offset);
}
int
	Location_isInSystemHeader(
		CXSourceLocation location
	)
{
	return clang_Location_isInSystemHeader(location);
}
int
	Location_isFromMainFile(
		CXSourceLocation location
	)
{
	return clang_Location_isFromMainFile(location);
}
CXSourceRange
	getNullRange(
	)
{
	return clang_getNullRange();
}
CXSourceRange
	getRange(
		CXSourceLocation begin,
		CXSourceLocation end
	)
{
	return clang_getRange(begin, end);
}
unsigned int
	equalRanges(
		CXSourceRange range1,
		CXSourceRange range2
	)
{
	return clang_equalRanges(range1, range2);
}
int
	Range_isNull(
		CXSourceRange range
	)
{
	return clang_Range_isNull(range);
}
void
	getExpansionLocation(
		CXSourceLocation location,
		CXFile * file,
		unsigned int * line,
		unsigned int * column,
		unsigned int * offset
	)
{
	clang_getExpansionLocation(location, file, line, column, offset);
}
void
	getPresumedLocation(
		CXSourceLocation location,
		CXString * filename,
		unsigned int * line,
		unsigned int * column
	)
{
	clang_getPresumedLocation(location, filename, line, column);
}
void
	getInstantiationLocation(
		CXSourceLocation location,
		CXFile * file,
		unsigned int * line,
		unsigned int * column,
		unsigned int * offset
	)
{
	clang_getInstantiationLocation(location, file, line, column, offset);
}
void
	getSpellingLocation(
		CXSourceLocation location,
		CXFile * file,
		unsigned int * line,
		unsigned int * column,
		unsigned int * offset
	)
{
	clang_getSpellingLocation(location, file, line, column, offset);
}
void
	getFileLocation(
		CXSourceLocation location,
		CXFile * file,
		unsigned int * line,
		unsigned int * column,
		unsigned int * offset
	)
{
	clang_getFileLocation(location, file, line, column, offset);
}
CXSourceLocation
	getRangeStart(
		CXSourceRange range
	)
{
	return clang_getRangeStart(range);
}
CXSourceLocation
	getRangeEnd(
		CXSourceRange range
	)
{
	return clang_getRangeEnd(range);
}
unsigned int
	getNumDiagnosticsInSet(
		CXDiagnosticSet Diags
	)
{
	return clang_getNumDiagnosticsInSet(Diags);
}
CXDiagnostic
	getDiagnosticInSet(
		CXDiagnosticSet Diags,
		unsigned int Index
	)
{
	return clang_getDiagnosticInSet(Diags, Index);
}
CXDiagnosticSet
	loadDiagnostics(
		const char * file,
		enum CXLoadDiag_Error * error,
		CXString * errorString
	)
{
	return clang_loadDiagnostics(file, error, errorString);
}
void
	disposeDiagnosticSet(
		CXDiagnosticSet Diags
	)
{
	clang_disposeDiagnosticSet(Diags);
}
CXDiagnosticSet
	getChildDiagnostics(
		CXDiagnostic D
	)
{
	return clang_getChildDiagnostics(D);
}
unsigned int
	getNumDiagnostics(
		CXTranslationUnit Unit
	)
{
	return clang_getNumDiagnostics(Unit);
}
CXDiagnostic
	getDiagnostic(
		CXTranslationUnit Unit,
		unsigned int Index
	)
{
	return clang_getDiagnostic(Unit, Index);
}
CXDiagnosticSet
	getDiagnosticSetFromTU(
		CXTranslationUnit Unit
	)
{
	return clang_getDiagnosticSetFromTU(Unit);
}
void
	disposeDiagnostic(
		CXDiagnostic Diagnostic
	)
{
	clang_disposeDiagnostic(Diagnostic);
}
CXString
	formatDiagnostic(
		CXDiagnostic Diagnostic,
		unsigned int Options
	)
{
	return clang_formatDiagnostic(Diagnostic, Options);
}
unsigned int
	defaultDiagnosticDisplayOptions(
	)
{
	return clang_defaultDiagnosticDisplayOptions();
}
enum CXDiagnosticSeverity
	getDiagnosticSeverity(
		CXDiagnostic arg0
	)
{
	return clang_getDiagnosticSeverity(arg0);
}
CXSourceLocation
	getDiagnosticLocation(
		CXDiagnostic arg0
	)
{
	return clang_getDiagnosticLocation(arg0);
}
CXString
	getDiagnosticSpelling(
		CXDiagnostic arg0
	)
{
	return clang_getDiagnosticSpelling(arg0);
}
CXString
	getDiagnosticOption(
		CXDiagnostic Diag,
		CXString * Disable
	)
{
	return clang_getDiagnosticOption(Diag, Disable);
}
unsigned int
	getDiagnosticCategory(
		CXDiagnostic arg0
	)
{
	return clang_getDiagnosticCategory(arg0);
}
CXString
	getDiagnosticCategoryText(
		CXDiagnostic arg0
	)
{
	return clang_getDiagnosticCategoryText(arg0);
}
unsigned int
	getDiagnosticNumRanges(
		CXDiagnostic arg0
	)
{
	return clang_getDiagnosticNumRanges(arg0);
}
CXSourceRange
	getDiagnosticRange(
		CXDiagnostic Diagnostic,
		unsigned int Range
	)
{
	return clang_getDiagnosticRange(Diagnostic, Range);
}
unsigned int
	getDiagnosticNumFixIts(
		CXDiagnostic Diagnostic
	)
{
	return clang_getDiagnosticNumFixIts(Diagnostic);
}
CXString
	getDiagnosticFixIt(
		CXDiagnostic Diagnostic,
		unsigned int FixIt,
		CXSourceRange * ReplacementRange
	)
{
	return clang_getDiagnosticFixIt(Diagnostic, FixIt, ReplacementRange);
}
CXString
	getTranslationUnitSpelling(
		CXTranslationUnit CTUnit
	)
{
	return clang_getTranslationUnitSpelling(CTUnit);
}
CXTranslationUnit
	createTranslationUnitFromSourceFile(
		CXIndex CIdx,
		const char * source_filename,
		int num_clang_command_line_args,
		const char *const * clang_command_line_args,
		unsigned int num_unsaved_files,
		struct CXUnsavedFile * unsaved_files
	)
{
	return clang_createTranslationUnitFromSourceFile(CIdx, source_filename, num_clang_command_line_args, clang_command_line_args, num_unsaved_files, unsaved_files);
}
CXTranslationUnit
	createTranslationUnit(
		CXIndex arg0,
		const char * ast_filename
	)
{
	return clang_createTranslationUnit(arg0, ast_filename);
}
unsigned int
	defaultEditingTranslationUnitOptions(
	)
{
	return clang_defaultEditingTranslationUnitOptions();
}
CXTranslationUnit
	parseTranslationUnit(
		CXIndex CIdx,
		const char * source_filename,
		const char *const * command_line_args,
		int num_command_line_args,
		struct CXUnsavedFile * unsaved_files,
		unsigned int num_unsaved_files,
		unsigned int options
	)
{
	return clang_parseTranslationUnit(CIdx, source_filename, command_line_args, num_command_line_args, unsaved_files, num_unsaved_files, options);
}
unsigned int
	defaultSaveOptions(
		CXTranslationUnit TU
	)
{
	return clang_defaultSaveOptions(TU);
}
int
	saveTranslationUnit(
		CXTranslationUnit TU,
		const char * FileName,
		unsigned int options
	)
{
	return clang_saveTranslationUnit(TU, FileName, options);
}
void
	disposeTranslationUnit(
		CXTranslationUnit arg0
	)
{
	clang_disposeTranslationUnit(arg0);
}
unsigned int
	defaultReparseOptions(
		CXTranslationUnit TU
	)
{
	return clang_defaultReparseOptions(TU);
}
int
	reparseTranslationUnit(
		CXTranslationUnit TU,
		unsigned int num_unsaved_files,
		struct CXUnsavedFile * unsaved_files,
		unsigned int options
	)
{
	return clang_reparseTranslationUnit(TU, num_unsaved_files, unsaved_files, options);
}
const char *
	getTUResourceUsageName(
		enum CXTUResourceUsageKind kind
	)
{
	return clang_getTUResourceUsageName(kind);
}
CXTUResourceUsage
	getCXTUResourceUsage(
		CXTranslationUnit TU
	)
{
	return clang_getCXTUResourceUsage(TU);
}
void
	disposeCXTUResourceUsage(
		CXTUResourceUsage usage
	)
{
	clang_disposeCXTUResourceUsage(usage);
}
CXCursor
	getNullCursor(
	)
{
	return clang_getNullCursor();
}
CXCursor
	getTranslationUnitCursor(
		CXTranslationUnit arg0
	)
{
	return clang_getTranslationUnitCursor(arg0);
}
unsigned int
	equalCursors(
		CXCursor arg0,
		CXCursor arg1
	)
{
	return clang_equalCursors(arg0, arg1);
}
int
	Cursor_isNull(
		CXCursor cursor
	)
{
	return clang_Cursor_isNull(cursor);
}
unsigned int
	hashCursor(
		CXCursor arg0
	)
{
	return clang_hashCursor(arg0);
}
enum CXCursorKind
	getCursorKind(
		CXCursor arg0
	)
{
	return clang_getCursorKind(arg0);
}
unsigned int
	isDeclaration(
		enum CXCursorKind arg0
	)
{
	return clang_isDeclaration(arg0);
}
unsigned int
	isReference(
		enum CXCursorKind arg0
	)
{
	return clang_isReference(arg0);
}
unsigned int
	isExpression(
		enum CXCursorKind arg0
	)
{
	return clang_isExpression(arg0);
}
unsigned int
	isStatement(
		enum CXCursorKind arg0
	)
{
	return clang_isStatement(arg0);
}
unsigned int
	isAttribute(
		enum CXCursorKind arg0
	)
{
	return clang_isAttribute(arg0);
}
unsigned int
	isInvalid(
		enum CXCursorKind arg0
	)
{
	return clang_isInvalid(arg0);
}
unsigned int
	isTranslationUnit(
		enum CXCursorKind arg0
	)
{
	return clang_isTranslationUnit(arg0);
}
unsigned int
	isPreprocessing(
		enum CXCursorKind arg0
	)
{
	return clang_isPreprocessing(arg0);
}
unsigned int
	isUnexposed(
		enum CXCursorKind arg0
	)
{
	return clang_isUnexposed(arg0);
}
enum CXLinkageKind
	getCursorLinkage(
		CXCursor cursor
	)
{
	return clang_getCursorLinkage(cursor);
}
enum CXAvailabilityKind
	getCursorAvailability(
		CXCursor cursor
	)
{
	return clang_getCursorAvailability(cursor);
}
int
	getCursorPlatformAvailability(
		CXCursor cursor,
		int * always_deprecated,
		CXString * deprecated_message,
		int * always_unavailable,
		CXString * unavailable_message,
		CXPlatformAvailability * availability,
		int availability_size
	)
{
	return clang_getCursorPlatformAvailability(cursor, always_deprecated, deprecated_message, always_unavailable, unavailable_message, availability, availability_size);
}
void
	disposeCXPlatformAvailability(
		CXPlatformAvailability * availability
	)
{
	clang_disposeCXPlatformAvailability(availability);
}
enum CXLanguageKind
	getCursorLanguage(
		CXCursor cursor
	)
{
	return clang_getCursorLanguage(cursor);
}
CXTranslationUnit
	Cursor_getTranslationUnit(
		CXCursor arg0
	)
{
	return clang_Cursor_getTranslationUnit(arg0);
}
CXCursorSet
	createCXCursorSet(
	)
{
	return clang_createCXCursorSet();
}
void
	disposeCXCursorSet(
		CXCursorSet cset
	)
{
	clang_disposeCXCursorSet(cset);
}
unsigned int
	CXCursorSet_contains(
		CXCursorSet cset,
		CXCursor cursor
	)
{
	return clang_CXCursorSet_contains(cset, cursor);
}
unsigned int
	CXCursorSet_insert(
		CXCursorSet cset,
		CXCursor cursor
	)
{
	return clang_CXCursorSet_insert(cset, cursor);
}
CXCursor
	getCursorSemanticParent(
		CXCursor cursor
	)
{
	return clang_getCursorSemanticParent(cursor);
}
CXCursor
	getCursorLexicalParent(
		CXCursor cursor
	)
{
	return clang_getCursorLexicalParent(cursor);
}
void
	getOverriddenCursors(
		CXCursor cursor,
		CXCursor ** overridden,
		unsigned int * num_overridden
	)
{
	clang_getOverriddenCursors(cursor, overridden, num_overridden);
}
void
	disposeOverriddenCursors(
		CXCursor * overridden
	)
{
	clang_disposeOverriddenCursors(overridden);
}
CXFile
	getIncludedFile(
		CXCursor cursor
	)
{
	return clang_getIncludedFile(cursor);
}
CXCursor
	getCursor(
		CXTranslationUnit arg0,
		CXSourceLocation arg1
	)
{
	return clang_getCursor(arg0, arg1);
}
CXSourceLocation
	getCursorLocation(
		CXCursor arg0
	)
{
	return clang_getCursorLocation(arg0);
}
CXSourceRange
	getCursorExtent(
		CXCursor arg0
	)
{
	return clang_getCursorExtent(arg0);
}
CXType
	getCursorType(
		CXCursor C
	)
{
	return clang_getCursorType(C);
}
CXString
	getTypeSpelling(
		CXType CT
	)
{
	return clang_getTypeSpelling(CT);
}
CXType
	getTypedefDeclUnderlyingType(
		CXCursor C
	)
{
	return clang_getTypedefDeclUnderlyingType(C);
}
CXType
	getEnumDeclIntegerType(
		CXCursor C
	)
{
	return clang_getEnumDeclIntegerType(C);
}
long long
	getEnumConstantDeclValue(
		CXCursor C
	)
{
	return clang_getEnumConstantDeclValue(C);
}
unsigned long long
	getEnumConstantDeclUnsignedValue(
		CXCursor C
	)
{
	return clang_getEnumConstantDeclUnsignedValue(C);
}
int
	getFieldDeclBitWidth(
		CXCursor C
	)
{
	return clang_getFieldDeclBitWidth(C);
}
int
	Cursor_getNumArguments(
		CXCursor C
	)
{
	return clang_Cursor_getNumArguments(C);
}
CXCursor
	Cursor_getArgument(
		CXCursor C,
		unsigned int i
	)
{
	return clang_Cursor_getArgument(C, i);
}
unsigned int
	equalTypes(
		CXType A,
		CXType B
	)
{
	return clang_equalTypes(A, B);
}
CXType
	getCanonicalType(
		CXType T
	)
{
	return clang_getCanonicalType(T);
}
unsigned int
	isConstQualifiedType(
		CXType T
	)
{
	return clang_isConstQualifiedType(T);
}
unsigned int
	isVolatileQualifiedType(
		CXType T
	)
{
	return clang_isVolatileQualifiedType(T);
}
unsigned int
	isRestrictQualifiedType(
		CXType T
	)
{
	return clang_isRestrictQualifiedType(T);
}
CXType
	getPointeeType(
		CXType T
	)
{
	return clang_getPointeeType(T);
}
CXCursor
	getTypeDeclaration(
		CXType T
	)
{
	return clang_getTypeDeclaration(T);
}
CXString
	getDeclObjCTypeEncoding(
		CXCursor C
	)
{
	return clang_getDeclObjCTypeEncoding(C);
}
CXString
	getTypeKindSpelling(
		enum CXTypeKind K
	)
{
	return clang_getTypeKindSpelling(K);
}
enum CXCallingConv
	getFunctionTypeCallingConv(
		CXType T
	)
{
	return clang_getFunctionTypeCallingConv(T);
}
CXType
	getResultType(
		CXType T
	)
{
	return clang_getResultType(T);
}
int
	getNumArgTypes(
		CXType T
	)
{
	return clang_getNumArgTypes(T);
}
CXType
	getArgType(
		CXType T,
		unsigned int i
	)
{
	return clang_getArgType(T, i);
}
unsigned int
	isFunctionTypeVariadic(
		CXType T
	)
{
	return clang_isFunctionTypeVariadic(T);
}
CXType
	getCursorResultType(
		CXCursor C
	)
{
	return clang_getCursorResultType(C);
}
unsigned int
	isPODType(
		CXType T
	)
{
	return clang_isPODType(T);
}
CXType
	getElementType(
		CXType T
	)
{
	return clang_getElementType(T);
}
long long
	getNumElements(
		CXType T
	)
{
	return clang_getNumElements(T);
}
CXType
	getArrayElementType(
		CXType T
	)
{
	return clang_getArrayElementType(T);
}
long long
	getArraySize(
		CXType T
	)
{
	return clang_getArraySize(T);
}
long long
	Type_getAlignOf(
		CXType T
	)
{
	return clang_Type_getAlignOf(T);
}
CXType
	Type_getClassType(
		CXType T
	)
{
	return clang_Type_getClassType(T);
}
long long
	Type_getSizeOf(
		CXType T
	)
{
	return clang_Type_getSizeOf(T);
}
long long
	Type_getOffsetOf(
		CXType T,
		const char * S
	)
{
	return clang_Type_getOffsetOf(T, S);
}
enum CXRefQualifierKind
	Type_getCXXRefQualifier(
		CXType T
	)
{
	return clang_Type_getCXXRefQualifier(T);
}
unsigned int
	Cursor_isBitField(
		CXCursor C
	)
{
	return clang_Cursor_isBitField(C);
}
unsigned int
	isVirtualBase(
		CXCursor arg0
	)
{
	return clang_isVirtualBase(arg0);
}
enum CX_CXXAccessSpecifier
	getCXXAccessSpecifier(
		CXCursor arg0
	)
{
	return clang_getCXXAccessSpecifier(arg0);
}
unsigned int
	getNumOverloadedDecls(
		CXCursor cursor
	)
{
	return clang_getNumOverloadedDecls(cursor);
}
CXCursor
	getOverloadedDecl(
		CXCursor cursor,
		unsigned int index
	)
{
	return clang_getOverloadedDecl(cursor, index);
}
CXType
	getIBOutletCollectionType(
		CXCursor arg0
	)
{
	return clang_getIBOutletCollectionType(arg0);
}
unsigned int
	visitChildren(
		CXCursor parent,
		CXCursorVisitor visitor,
		CXClientData client_data
	)
{
	return clang_visitChildren(parent, visitor, client_data);
}
CXString
	getCursorUSR(
		CXCursor arg0
	)
{
	return clang_getCursorUSR(arg0);
}
CXString
	constructUSR_ObjCClass(
		const char * class_name
	)
{
	return clang_constructUSR_ObjCClass(class_name);
}
CXString
	constructUSR_ObjCCategory(
		const char * class_name,
		const char * category_name
	)
{
	return clang_constructUSR_ObjCCategory(class_name, category_name);
}
CXString
	constructUSR_ObjCProtocol(
		const char * protocol_name
	)
{
	return clang_constructUSR_ObjCProtocol(protocol_name);
}
CXString
	constructUSR_ObjCIvar(
		const char * name,
		CXString classUSR
	)
{
	return clang_constructUSR_ObjCIvar(name, classUSR);
}
CXString
	constructUSR_ObjCMethod(
		const char * name,
		unsigned int isInstanceMethod,
		CXString classUSR
	)
{
	return clang_constructUSR_ObjCMethod(name, isInstanceMethod, classUSR);
}
CXString
	constructUSR_ObjCProperty(
		const char * property,
		CXString classUSR
	)
{
	return clang_constructUSR_ObjCProperty(property, classUSR);
}
CXString
	getCursorSpelling(
		CXCursor arg0
	)
{
	return clang_getCursorSpelling(arg0);
}
CXSourceRange
	Cursor_getSpellingNameRange(
		CXCursor arg0,
		unsigned int pieceIndex,
		unsigned int options
	)
{
	return clang_Cursor_getSpellingNameRange(arg0, pieceIndex, options);
}
CXString
	getCursorDisplayName(
		CXCursor arg0
	)
{
	return clang_getCursorDisplayName(arg0);
}
CXCursor
	getCursorReferenced(
		CXCursor arg0
	)
{
	return clang_getCursorReferenced(arg0);
}
CXCursor
	getCursorDefinition(
		CXCursor arg0
	)
{
	return clang_getCursorDefinition(arg0);
}
unsigned int
	isCursorDefinition(
		CXCursor arg0
	)
{
	return clang_isCursorDefinition(arg0);
}
CXCursor
	getCanonicalCursor(
		CXCursor arg0
	)
{
	return clang_getCanonicalCursor(arg0);
}
int
	Cursor_getObjCSelectorIndex(
		CXCursor arg0
	)
{
	return clang_Cursor_getObjCSelectorIndex(arg0);
}
int
	Cursor_isDynamicCall(
		CXCursor C
	)
{
	return clang_Cursor_isDynamicCall(C);
}
CXType
	Cursor_getReceiverType(
		CXCursor C
	)
{
	return clang_Cursor_getReceiverType(C);
}
unsigned int
	Cursor_getObjCPropertyAttributes(
		CXCursor C,
		unsigned int reserved
	)
{
	return clang_Cursor_getObjCPropertyAttributes(C, reserved);
}
unsigned int
	Cursor_getObjCDeclQualifiers(
		CXCursor C
	)
{
	return clang_Cursor_getObjCDeclQualifiers(C);
}
unsigned int
	Cursor_isObjCOptional(
		CXCursor C
	)
{
	return clang_Cursor_isObjCOptional(C);
}
unsigned int
	Cursor_isVariadic(
		CXCursor C
	)
{
	return clang_Cursor_isVariadic(C);
}
CXSourceRange
	Cursor_getCommentRange(
		CXCursor C
	)
{
	return clang_Cursor_getCommentRange(C);
}
CXString
	Cursor_getRawCommentText(
		CXCursor C
	)
{
	return clang_Cursor_getRawCommentText(C);
}
CXString
	Cursor_getBriefCommentText(
		CXCursor C
	)
{
	return clang_Cursor_getBriefCommentText(C);
}
CXComment
	Cursor_getParsedComment(
		CXCursor C
	)
{
	return clang_Cursor_getParsedComment(C);
}
CXModule
	Cursor_getModule(
		CXCursor C
	)
{
	return clang_Cursor_getModule(C);
}
CXFile
	Module_getASTFile(
		CXModule Module
	)
{
	return clang_Module_getASTFile(Module);
}
CXModule
	Module_getParent(
		CXModule Module
	)
{
	return clang_Module_getParent(Module);
}
CXString
	Module_getName(
		CXModule Module
	)
{
	return clang_Module_getName(Module);
}
CXString
	Module_getFullName(
		CXModule Module
	)
{
	return clang_Module_getFullName(Module);
}
unsigned int
	Module_getNumTopLevelHeaders(
		CXTranslationUnit arg0,
		CXModule Module
	)
{
	return clang_Module_getNumTopLevelHeaders(arg0, Module);
}
CXFile
	Module_getTopLevelHeader(
		CXTranslationUnit arg0,
		CXModule Module,
		unsigned int Index
	)
{
	return clang_Module_getTopLevelHeader(arg0, Module, Index);
}
enum CXCommentKind
	Comment_getKind(
		CXComment Comment
	)
{
	return clang_Comment_getKind(Comment);
}
unsigned int
	Comment_getNumChildren(
		CXComment Comment
	)
{
	return clang_Comment_getNumChildren(Comment);
}
CXComment
	Comment_getChild(
		CXComment Comment,
		unsigned int ChildIdx
	)
{
	return clang_Comment_getChild(Comment, ChildIdx);
}
unsigned int
	Comment_isWhitespace(
		CXComment Comment
	)
{
	return clang_Comment_isWhitespace(Comment);
}
unsigned int
	InlineContentComment_hasTrailingNewline(
		CXComment Comment
	)
{
	return clang_InlineContentComment_hasTrailingNewline(Comment);
}
CXString
	TextComment_getText(
		CXComment Comment
	)
{
	return clang_TextComment_getText(Comment);
}
CXString
	InlineCommandComment_getCommandName(
		CXComment Comment
	)
{
	return clang_InlineCommandComment_getCommandName(Comment);
}
enum CXCommentInlineCommandRenderKind
	InlineCommandComment_getRenderKind(
		CXComment Comment
	)
{
	return clang_InlineCommandComment_getRenderKind(Comment);
}
unsigned int
	InlineCommandComment_getNumArgs(
		CXComment Comment
	)
{
	return clang_InlineCommandComment_getNumArgs(Comment);
}
CXString
	InlineCommandComment_getArgText(
		CXComment Comment,
		unsigned int ArgIdx
	)
{
	return clang_InlineCommandComment_getArgText(Comment, ArgIdx);
}
CXString
	HTMLTagComment_getTagName(
		CXComment Comment
	)
{
	return clang_HTMLTagComment_getTagName(Comment);
}
unsigned int
	HTMLStartTagComment_isSelfClosing(
		CXComment Comment
	)
{
	return clang_HTMLStartTagComment_isSelfClosing(Comment);
}
unsigned int
	HTMLStartTag_getNumAttrs(
		CXComment Comment
	)
{
	return clang_HTMLStartTag_getNumAttrs(Comment);
}
CXString
	HTMLStartTag_getAttrName(
		CXComment Comment,
		unsigned int AttrIdx
	)
{
	return clang_HTMLStartTag_getAttrName(Comment, AttrIdx);
}
CXString
	HTMLStartTag_getAttrValue(
		CXComment Comment,
		unsigned int AttrIdx
	)
{
	return clang_HTMLStartTag_getAttrValue(Comment, AttrIdx);
}
CXString
	BlockCommandComment_getCommandName(
		CXComment Comment
	)
{
	return clang_BlockCommandComment_getCommandName(Comment);
}
unsigned int
	BlockCommandComment_getNumArgs(
		CXComment Comment
	)
{
	return clang_BlockCommandComment_getNumArgs(Comment);
}
CXString
	BlockCommandComment_getArgText(
		CXComment Comment,
		unsigned int ArgIdx
	)
{
	return clang_BlockCommandComment_getArgText(Comment, ArgIdx);
}
CXComment
	BlockCommandComment_getParagraph(
		CXComment Comment
	)
{
	return clang_BlockCommandComment_getParagraph(Comment);
}
CXString
	ParamCommandComment_getParamName(
		CXComment Comment
	)
{
	return clang_ParamCommandComment_getParamName(Comment);
}
unsigned int
	ParamCommandComment_isParamIndexValid(
		CXComment Comment
	)
{
	return clang_ParamCommandComment_isParamIndexValid(Comment);
}
unsigned int
	ParamCommandComment_getParamIndex(
		CXComment Comment
	)
{
	return clang_ParamCommandComment_getParamIndex(Comment);
}
unsigned int
	ParamCommandComment_isDirectionExplicit(
		CXComment Comment
	)
{
	return clang_ParamCommandComment_isDirectionExplicit(Comment);
}
enum CXCommentParamPassDirection
	ParamCommandComment_getDirection(
		CXComment Comment
	)
{
	return clang_ParamCommandComment_getDirection(Comment);
}
CXString
	TParamCommandComment_getParamName(
		CXComment Comment
	)
{
	return clang_TParamCommandComment_getParamName(Comment);
}
unsigned int
	TParamCommandComment_isParamPositionValid(
		CXComment Comment
	)
{
	return clang_TParamCommandComment_isParamPositionValid(Comment);
}
unsigned int
	TParamCommandComment_getDepth(
		CXComment Comment
	)
{
	return clang_TParamCommandComment_getDepth(Comment);
}
unsigned int
	TParamCommandComment_getIndex(
		CXComment Comment,
		unsigned int Depth
	)
{
	return clang_TParamCommandComment_getIndex(Comment, Depth);
}
CXString
	VerbatimBlockLineComment_getText(
		CXComment Comment
	)
{
	return clang_VerbatimBlockLineComment_getText(Comment);
}
CXString
	VerbatimLineComment_getText(
		CXComment Comment
	)
{
	return clang_VerbatimLineComment_getText(Comment);
}
CXString
	HTMLTagComment_getAsString(
		CXComment Comment
	)
{
	return clang_HTMLTagComment_getAsString(Comment);
}
CXString
	FullComment_getAsHTML(
		CXComment Comment
	)
{
	return clang_FullComment_getAsHTML(Comment);
}
CXString
	FullComment_getAsXML(
		CXComment Comment
	)
{
	return clang_FullComment_getAsXML(Comment);
}
unsigned int
	CXXMethod_isPureVirtual(
		CXCursor C
	)
{
	return clang_CXXMethod_isPureVirtual(C);
}
unsigned int
	CXXMethod_isStatic(
		CXCursor C
	)
{
	return clang_CXXMethod_isStatic(C);
}
unsigned int
	CXXMethod_isVirtual(
		CXCursor C
	)
{
	return clang_CXXMethod_isVirtual(C);
}
enum CXCursorKind
	getTemplateCursorKind(
		CXCursor C
	)
{
	return clang_getTemplateCursorKind(C);
}
CXCursor
	getSpecializedCursorTemplate(
		CXCursor C
	)
{
	return clang_getSpecializedCursorTemplate(C);
}
CXSourceRange
	getCursorReferenceNameRange(
		CXCursor C,
		unsigned int NameFlags,
		unsigned int PieceIndex
	)
{
	return clang_getCursorReferenceNameRange(C, NameFlags, PieceIndex);
}
CXTokenKind
	getTokenKind(
		CXToken arg0
	)
{
	return clang_getTokenKind(arg0);
}
CXString
	getTokenSpelling(
		CXTranslationUnit arg0,
		CXToken arg1
	)
{
	return clang_getTokenSpelling(arg0, arg1);
}
CXSourceLocation
	getTokenLocation(
		CXTranslationUnit arg0,
		CXToken arg1
	)
{
	return clang_getTokenLocation(arg0, arg1);
}
CXSourceRange
	getTokenExtent(
		CXTranslationUnit arg0,
		CXToken arg1
	)
{
	return clang_getTokenExtent(arg0, arg1);
}
void
	tokenize(
		CXTranslationUnit TU,
		CXSourceRange Range,
		CXToken ** Tokens,
		unsigned int * NumTokens
	)
{
	clang_tokenize(TU, Range, Tokens, NumTokens);
}
void
	annotateTokens(
		CXTranslationUnit TU,
		CXToken * Tokens,
		unsigned int NumTokens,
		CXCursor * Cursors
	)
{
	clang_annotateTokens(TU, Tokens, NumTokens, Cursors);
}
void
	disposeTokens(
		CXTranslationUnit TU,
		CXToken * Tokens,
		unsigned int NumTokens
	)
{
	clang_disposeTokens(TU, Tokens, NumTokens);
}
CXString
	getCursorKindSpelling(
		enum CXCursorKind Kind
	)
{
	return clang_getCursorKindSpelling(Kind);
}
void
	getDefinitionSpellingAndExtent(
		CXCursor arg0,
		const char ** startBuf,
		const char ** endBuf,
		unsigned int * startLine,
		unsigned int * startColumn,
		unsigned int * endLine,
		unsigned int * endColumn
	)
{
	clang_getDefinitionSpellingAndExtent(arg0, startBuf, endBuf, startLine, startColumn, endLine, endColumn);
}
void
	enableStackTraces(
	)
{
	clang_enableStackTraces();
}
void
	executeOnThread(
		void (*fn)(void *),
		void * user_data,
		unsigned int stack_size
	)
{
	clang_executeOnThread(fn, user_data, stack_size);
}
enum CXCompletionChunkKind
	getCompletionChunkKind(
		CXCompletionString completion_string,
		unsigned int chunk_number
	)
{
	return clang_getCompletionChunkKind(completion_string, chunk_number);
}
CXString
	getCompletionChunkText(
		CXCompletionString completion_string,
		unsigned int chunk_number
	)
{
	return clang_getCompletionChunkText(completion_string, chunk_number);
}
CXCompletionString
	getCompletionChunkCompletionString(
		CXCompletionString completion_string,
		unsigned int chunk_number
	)
{
	return clang_getCompletionChunkCompletionString(completion_string, chunk_number);
}
unsigned int
	getNumCompletionChunks(
		CXCompletionString completion_string
	)
{
	return clang_getNumCompletionChunks(completion_string);
}
unsigned int
	getCompletionPriority(
		CXCompletionString completion_string
	)
{
	return clang_getCompletionPriority(completion_string);
}
enum CXAvailabilityKind
	getCompletionAvailability(
		CXCompletionString completion_string
	)
{
	return clang_getCompletionAvailability(completion_string);
}
unsigned int
	getCompletionNumAnnotations(
		CXCompletionString completion_string
	)
{
	return clang_getCompletionNumAnnotations(completion_string);
}
CXString
	getCompletionAnnotation(
		CXCompletionString completion_string,
		unsigned int annotation_number
	)
{
	return clang_getCompletionAnnotation(completion_string, annotation_number);
}
CXString
	getCompletionParent(
		CXCompletionString completion_string,
		enum CXCursorKind * kind
	)
{
	return clang_getCompletionParent(completion_string, kind);
}
CXString
	getCompletionBriefComment(
		CXCompletionString completion_string
	)
{
	return clang_getCompletionBriefComment(completion_string);
}
CXCompletionString
	getCursorCompletionString(
		CXCursor cursor
	)
{
	return clang_getCursorCompletionString(cursor);
}
unsigned int
	defaultCodeCompleteOptions(
	)
{
	return clang_defaultCodeCompleteOptions();
}
CXCodeCompleteResults *
	codeCompleteAt(
		CXTranslationUnit TU,
		const char * complete_filename,
		unsigned int complete_line,
		unsigned int complete_column,
		struct CXUnsavedFile * unsaved_files,
		unsigned int num_unsaved_files,
		unsigned int options
	)
{
	return clang_codeCompleteAt(TU, complete_filename, complete_line, complete_column, unsaved_files, num_unsaved_files, options);
}
void
	sortCodeCompletionResults(
		CXCompletionResult * Results,
		unsigned int NumResults
	)
{
	clang_sortCodeCompletionResults(Results, NumResults);
}
void
	disposeCodeCompleteResults(
		CXCodeCompleteResults * Results
	)
{
	clang_disposeCodeCompleteResults(Results);
}
unsigned int
	codeCompleteGetNumDiagnostics(
		CXCodeCompleteResults * Results
	)
{
	return clang_codeCompleteGetNumDiagnostics(Results);
}
CXDiagnostic
	codeCompleteGetDiagnostic(
		CXCodeCompleteResults * Results,
		unsigned int Index
	)
{
	return clang_codeCompleteGetDiagnostic(Results, Index);
}
unsigned long long
	codeCompleteGetContexts(
		CXCodeCompleteResults * Results
	)
{
	return clang_codeCompleteGetContexts(Results);
}
enum CXCursorKind
	codeCompleteGetContainerKind(
		CXCodeCompleteResults * Results,
		unsigned int * IsIncomplete
	)
{
	return clang_codeCompleteGetContainerKind(Results, IsIncomplete);
}
CXString
	codeCompleteGetContainerUSR(
		CXCodeCompleteResults * Results
	)
{
	return clang_codeCompleteGetContainerUSR(Results);
}
CXString
	codeCompleteGetObjCSelector(
		CXCodeCompleteResults * Results
	)
{
	return clang_codeCompleteGetObjCSelector(Results);
}
CXString
	getClangVersion(
	)
{
	return clang_getClangVersion();
}
void
	toggleCrashRecovery(
		unsigned int isEnabled
	)
{
	clang_toggleCrashRecovery(isEnabled);
}
void
	getInclusions(
		CXTranslationUnit tu,
		CXInclusionVisitor visitor,
		CXClientData client_data
	)
{
	clang_getInclusions(tu, visitor, client_data);
}
CXRemapping
	getRemappings(
		const char * path
	)
{
	return clang_getRemappings(path);
}
CXRemapping
	getRemappingsFromFileList(
		const char ** filePaths,
		unsigned int numFiles
	)
{
	return clang_getRemappingsFromFileList(filePaths, numFiles);
}
unsigned int
	remap_getNumFiles(
		CXRemapping arg0
	)
{
	return clang_remap_getNumFiles(arg0);
}
void
	remap_getFilenames(
		CXRemapping arg0,
		unsigned int index,
		CXString * original,
		CXString * transformed
	)
{
	clang_remap_getFilenames(arg0, index, original, transformed);
}
void
	remap_dispose(
		CXRemapping arg0
	)
{
	clang_remap_dispose(arg0);
}
CXResult
	findReferencesInFile(
		CXCursor cursor,
		CXFile file,
		CXCursorAndRangeVisitor visitor
	)
{
	return clang_findReferencesInFile(cursor, file, visitor);
}
CXResult
	findIncludesInFile(
		CXTranslationUnit TU,
		CXFile file,
		CXCursorAndRangeVisitor visitor
	)
{
	return clang_findIncludesInFile(TU, file, visitor);
}
int
	index_isEntityObjCContainerKind(
		CXIdxEntityKind arg0
	)
{
	return clang_index_isEntityObjCContainerKind(arg0);
}
const CXIdxObjCContainerDeclInfo *
	index_getObjCContainerDeclInfo(
		const CXIdxDeclInfo * arg0
	)
{
	return clang_index_getObjCContainerDeclInfo(arg0);
}
const CXIdxObjCInterfaceDeclInfo *
	index_getObjCInterfaceDeclInfo(
		const CXIdxDeclInfo * arg0
	)
{
	return clang_index_getObjCInterfaceDeclInfo(arg0);
}
const CXIdxObjCCategoryDeclInfo *
	index_getObjCCategoryDeclInfo(
		const CXIdxDeclInfo * arg0
	)
{
	return clang_index_getObjCCategoryDeclInfo(arg0);
}
const CXIdxObjCProtocolRefListInfo *
	index_getObjCProtocolRefListInfo(
		const CXIdxDeclInfo * arg0
	)
{
	return clang_index_getObjCProtocolRefListInfo(arg0);
}
const CXIdxObjCPropertyDeclInfo *
	index_getObjCPropertyDeclInfo(
		const CXIdxDeclInfo * arg0
	)
{
	return clang_index_getObjCPropertyDeclInfo(arg0);
}
const CXIdxIBOutletCollectionAttrInfo *
	index_getIBOutletCollectionAttrInfo(
		const CXIdxAttrInfo * arg0
	)
{
	return clang_index_getIBOutletCollectionAttrInfo(arg0);
}
const CXIdxCXXClassDeclInfo *
	index_getCXXClassDeclInfo(
		const CXIdxDeclInfo * arg0
	)
{
	return clang_index_getCXXClassDeclInfo(arg0);
}
CXIdxClientContainer
	index_getClientContainer(
		const CXIdxContainerInfo * arg0
	)
{
	return clang_index_getClientContainer(arg0);
}
void
	index_setClientContainer(
		const CXIdxContainerInfo * arg0,
		CXIdxClientContainer arg1
	)
{
	clang_index_setClientContainer(arg0, arg1);
}
CXIdxClientEntity
	index_getClientEntity(
		const CXIdxEntityInfo * arg0
	)
{
	return clang_index_getClientEntity(arg0);
}
void
	index_setClientEntity(
		const CXIdxEntityInfo * arg0,
		CXIdxClientEntity arg1
	)
{
	clang_index_setClientEntity(arg0, arg1);
}
CXIndexAction
	IndexAction_create(
		CXIndex CIdx
	)
{
	return clang_IndexAction_create(CIdx);
}
void
	IndexAction_dispose(
		CXIndexAction arg0
	)
{
	clang_IndexAction_dispose(arg0);
}
int
	indexSourceFile(
		CXIndexAction arg0,
		CXClientData client_data,
		IndexerCallbacks * index_callbacks,
		unsigned int index_callbacks_size,
		unsigned int index_options,
		const char * source_filename,
		const char *const * command_line_args,
		int num_command_line_args,
		struct CXUnsavedFile * unsaved_files,
		unsigned int num_unsaved_files,
		CXTranslationUnit * out_TU,
		unsigned int TU_options
	)
{
	return clang_indexSourceFile(arg0, client_data, index_callbacks, index_callbacks_size, index_options, source_filename, command_line_args, num_command_line_args, unsaved_files, num_unsaved_files, out_TU, TU_options);
}
int
	indexTranslationUnit(
		CXIndexAction arg0,
		CXClientData client_data,
		IndexerCallbacks * index_callbacks,
		unsigned int index_callbacks_size,
		unsigned int index_options,
		CXTranslationUnit arg5
	)
{
	return clang_indexTranslationUnit(arg0, client_data, index_callbacks, index_callbacks_size, index_options, arg5);
}
void
	indexLoc_getFileLocation(
		CXIdxLoc loc,
		CXIdxClientFile * indexFile,
		CXFile * file,
		unsigned int * line,
		unsigned int * column,
		unsigned int * offset
	)
{
	clang_indexLoc_getFileLocation(loc, indexFile, file, line, column, offset);
}
CXSourceLocation
	indexLoc_getCXSourceLocation(
		CXIdxLoc loc
	)
{
	return clang_indexLoc_getCXSourceLocation(loc);
}

} // namespace

