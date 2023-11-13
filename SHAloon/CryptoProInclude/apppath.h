/*
 * Copyright(C) 2000 Проект ИОК
 *
 * Этот файл содержит информацию, являющуюся
 * собственностью компании Крипто Про.
 *
 * Любая часть этого файла не может быть скопирована,
 * исправлена, переведена на другие языки,
 * локализована или модифицирована любым способом,
 * откомпилирована, передана по сети с или на
 * любую компьютерную систему без предварительного
 * заключения соглашения с компанией Крипто Про.
 */

/*!
 * \file $RCSfile$
 * \version $Revision: 191428 $
 * \date $Date:: 2019-04-01 19:17:10 +0300#$
 * \author $Author: maxdm $
 *
 * \brief Интерфейс к модулю работы с ключем AppPaths реестра.
 */

#ifndef _APPPATH_H_INCLUDED
#define _APPPATH_H_INCLUDED

#include <windows.h>
#include <wchar.h>
#include "wow64.h"

//#pragma deprecated(GetAppPathEntry, GetAppPathEntryEx)
#ifdef UNICODE
#define GetAppPathEx GetAppPathExW
#define GetAppPathEntry _GetAppPathEntryW
#define GetAppPathEntryEx _GetAppPathEntryExW
#define GetThisModuleFileName GetThisModuleFileNameW
#else // UNICODE
#define GetAppPath GetAppPathA
#define GetAppPathEx GetAppPathExA
#define GetAppPathEntry _GetAppPathEntryA
#define GetAppPathEntryEx _GetAppPathEntryExA
#define GetThisModuleFileName GetThisModuleFileNameA
#endif // UNICODE

#ifdef WINCE
#define CPREGSTR_PATH_APPPATH_A "SOFTWARE\\Crypto Pro\\CSP\\AppPath"
#define CPREGSTR_PATH_APPPATH_W L"SOFTWARE\\Crypto Pro\\CSP\\AppPath"
#define CPREGSTR_PATH_APPPATH L"SOFTWARE\\Crypto Pro\\CSP\\AppPath"
#else // !WINCE
#define CPREGSTR_PATH_APPPATH_A "SOFTWARE\\Crypto Pro\\Cryptography\\CurrentVersion\\AppPath"
#define CPREGSTR_PATH_APPPATH_W L"SOFTWARE\\Crypto Pro\\Cryptography\\CurrentVersion\\AppPath"
#ifdef _WIN64
#define CPREGSTR_PATH_APPPATH_WOW64_A "SOFTWARE\\Wow6432Node\\Crypto Pro\\Cryptography\\CurrentVersion\\AppPath"
#define CPREGSTR_PATH_APPPATH_WOW64_W L"SOFTWARE\\Wow6432Node\\Crypto Pro\\Cryptography\\CurrentVersion\\AppPath"
#endif // _WIN64
#ifdef UNICODE
#define CPREGSTR_PATH_APPPATH CPREGSTR_PATH_APPPATH_W
#else // !UNICODE
#define CPREGSTR_PATH_APPPATH CPREGSTR_PATH_APPPATH_A
#endif // !UNICODE
#ifdef _WIN64
#ifdef UNICODE
#define CPREGSTR_PATH_APPPATH_WOW64 CPREGSTR_PATH_APPPATH_WOW64_W
#else // !UNICODE
#define CPREGSTR_PATH_APPPATH_WOW64 CPREGSTR_PATH_APPPATH_WOW64_A
#endif // !UNICODE
#endif // _WIN64
#endif // !WINCE

#ifdef _WIN64
// Для 64-битной компиляции смотреть на WOW64 не требуется
#define NO_WOW64_CHECK
#endif // _WIN64

#ifndef CALLEE_CHECK
#define NO_WOW64_CHECK
#endif

#ifndef __cplusplus
#define inline __inline
#endif // !__cplusplus

static inline errno_t __cdecl 
__wcscat_s(wchar_t *_Dst, size_t _SizeInWords, const wchar_t *_Src);
static inline errno_t __cdecl 
__strcat_s(char *_Dst, size_t _SizeInWords, const char *_Src);

// near the top of your CPP file
EXTERN_C IMAGE_DOS_HEADER __ImageBase;

#if _WIN32_WINNT > 0x0500
    #define __GetModuleHandleExW GetModuleHandleExW
#else
#ifndef __GETMODULEHANDLEEXW_DEFINED
#define __GETMODULEHANDLEEXW_DEFINED

#ifndef GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS
#define GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS (0x00000004)
#endif //GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS

#ifndef GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT
#define GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT  (0x00000002)
#endif //GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT

typedef BOOL (WINAPI *pGetModuleHandleExW)(DWORD, LPCWSTR, HMODULE*);
static pGetModuleHandleExW fnGetModuleHandleExW = 0;

static inline BOOL __GetModuleHandleExW(
    DWORD dwFlags, LPCWSTR lpModuleName, HMODULE* phModule)
{
    MEMORY_BASIC_INFORMATION memInfo;
    if (fnGetModuleHandleExW)
	return fnGetModuleHandleExW(dwFlags, lpModuleName, phModule);
    else {
	HINSTANCE hInst = GetModuleHandleW(L"kernel32.dll");
	if (hInst) {
	    fnGetModuleHandleExW = (pGetModuleHandleExW)GetProcAddress (
		hInst, "GetModuleHandleExW");
	    if (fnGetModuleHandleExW)
		return fnGetModuleHandleExW(dwFlags, lpModuleName, phModule);
	}
    }
    // Собственная реализация через VirtualQuery
    if (dwFlags != GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS) {
	SetLastError((DWORD)E_NOTIMPL);
	return FALSE;
    }
    memset(&memInfo, 0, sizeof(memInfo));
    if (VirtualQuery(lpModuleName, &memInfo, sizeof(memInfo))
	< sizeof(memInfo)) {
	SetLastError((DWORD)E_INVALIDARG);
	return FALSE;
    }
    *phModule = (HMODULE)memInfo.AllocationBase;
    return TRUE;
}

#endif //__GETMODULEHANDLEEXW_DEFINED
#endif /*_WIN32_WINNT > 0x0500*/

#ifndef NO_WOW64_CHECK

typedef UINT (WINAPI *LPFN_GETSYSTEMWOW64DIRECTORYW)(LPWSTR, UINT);
typedef UINT (WINAPI *LPFN_GETSYSTEMWOW64DIRECTORYA)(LPSTR, UINT);

static inline UINT GetSystemWow64DirA(LPSTR lpBuffer, UINT uSize)
{
    static LPFN_GETSYSTEMWOW64DIRECTORYA fnGetSystemWow64DirA
	= (LPFN_GETSYSTEMWOW64DIRECTORYA)-1;
    if (fnGetSystemWow64DirA == (LPFN_GETSYSTEMWOW64DIRECTORYA)-1) {
	// Раньше было так:
	//fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(
	//    GetModuleHandleW(L"kernel32"),"IsWow64Process");
	//
	// На этот код анализатор ругался так:
	// warning C6309: Argument '1' is null: this does not adhere to
	// function specification of 'GetProcAddress'
	//
	// Понятно, что kernel32.dll есть в любом процессе, но для анализатора
	// вставлена проверка на ненулевой возврат GetModuleHandleW().
	HMODULE hKernel32 = GetModuleHandleW(L"kernel32");
	if (!hKernel32) {
	    return 0;
	}
	fnGetSystemWow64DirA = (LPFN_GETSYSTEMWOW64DIRECTORYA)GetProcAddress(
	    hKernel32,"GetSystemWow64DirectoryA");
    }
    // Для Windows 2000, где нет никакого понятия про WOW64
    if (fnGetSystemWow64DirA == 0)
	return 0;
    return fnGetSystemWow64DirA(lpBuffer, uSize);
}

static inline UINT GetSystemWow64DirW(LPWSTR lpBuffer, UINT uSize)
{
    static LPFN_GETSYSTEMWOW64DIRECTORYW fnGetSystemWow64DirW
	= (LPFN_GETSYSTEMWOW64DIRECTORYW)-1;
    if (fnGetSystemWow64DirW == (LPFN_GETSYSTEMWOW64DIRECTORYW)-1) {
	// Раньше было так:
	//fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(
	//    GetModuleHandleW(L"kernel32"),"IsWow64Process");
	//
	// На этот код анализатор ругался так:
	// warning C6309: Argument '1' is null: this does not adhere to
	// function specification of 'GetProcAddress'
	//
	// Понятно, что kernel32.dll есть в любом процессе, но для анализатора
	// вставлена проверка на ненулевой возврат GetModuleHandleW().
	HMODULE hKernel32 = GetModuleHandleW(L"kernel32");
	if (!hKernel32) {
	    return 0;
	}
	fnGetSystemWow64DirW = (LPFN_GETSYSTEMWOW64DIRECTORYW)GetProcAddress(
	    hKernel32,"GetSystemWow64DirectoryW");
    }
    // Для Windows 2000, где нет никакого понятия про WOW64
    if (fnGetSystemWow64DirW == 0)
	return 0;
    return fnGetSystemWow64DirW(lpBuffer, uSize);
}
#endif //!NO_WOW64_CHECK

static inline BOOL
GetThisModuleFileNameA(LPSTR szThisFileName, DWORD dwNameLen)
{
    // Определим полное имя DLL, содержащей hook.
    HMODULE hSrcModule = (HMODULE)&__ImageBase;
    // Определять будем по адресу функции из этого модуля
    //   if (!__GetModuleHandleExW(
	//GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
	//(LPCWSTR)(DWORD_PTR)GetThisModuleFileNameA, &hSrcModule))
	//return FALSE;

    // Обнулим кончик, чтобы определить, что буфер мал.
    szThisFileName[dwNameLen - 1] = 0;
    if (!GetModuleFileNameA(hSrcModule, szThisFileName, dwNameLen)) {
	szThisFileName[0] = '\0';
	return FALSE;
    }
    if (szThisFileName[dwNameLen - 1]) {
	// функция затерла конечный ноль в буфере
	// - путь слишком большой для нас
	szThisFileName[0] = '\0';
	return FALSE;
    }
    if (!GetLongPathNameA(szThisFileName, szThisFileName, dwNameLen))
    {
	return FALSE;
    }
#ifndef NO_WOW64_CHECK
    {	
	if (IsWow64CurrentProcess()) {
	    // проверим, не записан ли путь, лежащий внутри System32 каталога
	    // через SysWOW64, если да, то изменим его на канонический вид,
	    // записанный через System32.
	    BOOL bGlobResult = FALSE;
	    int nLen;
	    CHAR *szSysWow64DirA = (CHAR *)LocalAlloc(LPTR, MAX_PATH * sizeof(CHAR));
	    CHAR *szSysDirA = (CHAR *)LocalAlloc(LPTR, MAX_PATH * sizeof(CHAR));
	    if (!szSysWow64DirA || !szSysDirA)
		goto error;
	    // Если это правда WOW64 процесс, то GetSystemWow64DirA должна работать!
	    if (!GetSystemWow64DirA(szSysWow64DirA, MAX_PATH))
		goto error;
	    nLen = (int)strlen(szSysWow64DirA);
	    if (CompareStringA (LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE,
		szSysWow64DirA, nLen, szThisFileName, nLen) == CSTR_EQUAL) {
		if (!GetSystemDirectoryA(szSysDirA, MAX_PATH))
		    goto error;
		if (__strcat_s(szSysDirA, MAX_PATH, szThisFileName + nLen))
		    goto error;
		*szThisFileName = 0;
		// Хочу воспользоватся функцией __strcat_s вместо strcpy_s,
		// для чего делаю пустой строкой szThisFileName, а потом доклеиваю wszSysDirA.
		if (__strcat_s(szThisFileName, dwNameLen, szSysDirA))
		    goto error;
	    }

	    bGlobResult = TRUE;
error:
	    LocalFree(szSysWow64DirA);
	    LocalFree(szSysDirA);
	    return bGlobResult;
	}
    }
#endif // NO_WOW64_CHECK
    return TRUE;
}

static inline BOOL
GetThisModuleFileNameW(LPWSTR wszThisFileName, DWORD dwNameLen)
{
    // Определим полное имя DLL, содержащей hook.
    HMODULE hSrcModule = (HMODULE)&__ImageBase;    
    // Определять будем по адресу функции из этого модуля
    //   if (!__GetModuleHandleExW(
	//GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
	//(LPCWSTR)(DWORD_PTR)GetThisModuleFileNameW, &hSrcModule))
	//return FALSE;
    // Обнулим кончик, чтобы определить, что буфер мал.
    wszThisFileName[dwNameLen - 1] = 0;
    if (!GetModuleFileNameW(hSrcModule, wszThisFileName, dwNameLen)) {
	wszThisFileName[0] = '\0';
	return FALSE;
    }
    if (wszThisFileName[dwNameLen - 1]) {
	// функция затерла конечный ноль в буфере
	// - путь слишком большой для нас
	wszThisFileName[0] = '\0';
	return FALSE;
    }
    if (!GetLongPathNameW(wszThisFileName, wszThisFileName, dwNameLen))
    {
	return FALSE;
    }
#ifndef NO_WOW64_CHECK
    {	
	// В 32-битном процессе функция IsWow64CurrentProcess должна возвращать
	// осмысленное значение	
	if (IsWow64CurrentProcess()) {
	    // проверим, не записан ли путь, лежащий внутри System32 каталога
	    // через SysWOW64, если да, то изменим его на канонический вид,
	    // записанный через System32.
	    BOOL bGlobResult = FALSE;
	    int nLen;
	    WCHAR *wszSysWow64DirW = (WCHAR *)LocalAlloc(LPTR, MAX_PATH * sizeof(WCHAR));
	    WCHAR *wszSysDirW = (WCHAR *)LocalAlloc(LPTR, MAX_PATH * sizeof(WCHAR));
	    if (!wszSysWow64DirW || !wszSysDirW)
		goto error;
	    // Если это правда WOW64 процесс, то GetSystemWow64DirW должна работать!
	    if (!GetSystemWow64DirW(wszSysWow64DirW, MAX_PATH))
		goto error;
	    nLen = (int)wcslen(wszSysWow64DirW);
	    if (CompareStringW (LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE,
		wszSysWow64DirW, nLen, wszThisFileName, nLen) == CSTR_EQUAL) {
		    if (!GetSystemDirectoryW(wszSysDirW, MAX_PATH))
			goto error;
		    if (__wcscat_s(wszSysDirW, MAX_PATH, wszThisFileName + nLen))
			goto error;
		*wszThisFileName = 0;
		// Хочу воспользоватся функцией __wcscat_s вместо wcscpy_s,
		// для чего делаю пустой строкой wszThisFileName, а потом доклеиваю wszSysDirW.
		if (__wcscat_s(wszThisFileName, dwNameLen, wszSysDirW))
		    goto error;
	    }

	    bGlobResult = TRUE;
error:
	    LocalFree(wszSysWow64DirW);
	    LocalFree(wszSysDirW);
	    return bGlobResult;
	}
    }
#endif // NO_WOW64_CHECK
    return TRUE;
}


static inline errno_t __cdecl 
__wcscat_s(wchar_t *_Dst, size_t _SizeInWords, const wchar_t *_Src)
{
    wchar_t *p;
    size_t available;

    if (! (_Dst != NULL && _SizeInWords > 0)) return /*EINVAL*/22;
    if (_Src == 0) { (*_Dst) = 0; return /*EINVAL*/22; }
    p = _Dst;
    available = _SizeInWords;
    while (available > 0 && *p != 0) {
	p++;
	available--;
    }
    if (available == 0) {
	(*_Dst) = 0;
	return /*EINVAL*/22;
    }
    while ((*p++ = *_Src++) != 0 && --available > 0) {
    }
    if (available == 0) {
	(*_Dst) = 0;
	return /*ERANGE*/34;
    }
    return 0;
}

static inline errno_t __cdecl 
__strcat_s(char *_Dst, size_t _SizeInWords, const char *_Src)
{
    char *p;
    size_t available;

    if (! (_Dst != NULL && _SizeInWords > 0)) return /*EINVAL*/22;
    if (_Src == 0) { (*_Dst) = 0; return /*EINVAL*/22; }
    p = _Dst;
    available = _SizeInWords;
    while (available > 0 && *p != 0) {
	p++;
	available--;
    }
    if (available == 0) {
	(*_Dst) = 0;
	return /*EINVAL*/22;
    }
    while ((*p++ = *_Src++) != 0 && --available > 0) {
    }
    if (available == 0) {
	(*_Dst) = 0;
	return /*ERANGE*/34;
    }
    return 0;
}

#ifndef DISABLE_REGISTRY_API
static inline BOOL
_GetAppPathEntryExW (LPCWSTR szDll, LPCWSTR szEntry, LPWSTR szValue,
    DWORD *pcbMaxLen)
{
    BOOL result = FALSE;
    HKEY hKey = 0;
    WCHAR wszRegKey[256] = CPREGSTR_PATH_APPPATH_W L"\\";

    /* Прочитаем подключ 'szDll' в системном ключе 'AppPath',
     * для того, чтобы определить полное имя szDll */

    if (__wcscat_s(wszRegKey, 256, szDll))
	goto err;

    if (ERROR_SUCCESS != RegOpenKeyExW (HKEY_LOCAL_MACHINE,
	wszRegKey, 0, KEY_QUERY_VALUE, &hKey)) {
	hKey = 0;
	goto err;
    }
    if (ERROR_SUCCESS != RegQueryValueExW (hKey, szEntry, NULL, NULL,
	(LPBYTE)szValue, pcbMaxLen)) {
	goto err;
    }
    result = TRUE;

err:
    if (hKey)
	RegCloseKey (hKey);
    return result;
}

static inline BOOL
_GetAppPathEntryW (LPCWSTR szDll, LPCWSTR szEntry, LPWSTR szValue, DWORD cbMaxLen)
{
    return _GetAppPathEntryExW (szDll, szEntry, szValue, &cbMaxLen);
}

static inline BOOL
_GetAppPathEntryExA (LPCSTR szDll, LPCSTR szEntry, LPSTR szValue, DWORD *pcbMaxLen)
{
    BOOL result = FALSE;
    HKEY hKey = 0;
    char szRegKey[256] = CPREGSTR_PATH_APPPATH_A "\\";

    /* Прочитаем подключ 'szDll' в системном ключе 'AppPath',
    * для того, чтобы определить полное имя szDll */

    if (__strcat_s(szRegKey, 256, szDll))
	goto err;

    if (ERROR_SUCCESS != RegOpenKeyExA (HKEY_LOCAL_MACHINE,
	szRegKey, 0, KEY_QUERY_VALUE, &hKey)) {
	hKey = 0;
	goto err;
    }
    if (ERROR_SUCCESS != RegQueryValueExA (hKey, szEntry, NULL, NULL,
	(LPBYTE)szValue, pcbMaxLen)) {
	goto err;
    }
    result = TRUE;

err:
    if (hKey)
	RegCloseKey (hKey);
    return result;
}

static inline BOOL
_GetAppPathEntryA (LPCSTR szDll, LPCSTR szEntry, LPSTR szValue, DWORD cbMaxLen)
{
    return _GetAppPathEntryExA (szDll, szEntry, szValue, &cbMaxLen);
}

#else // DISABLE_REGISTRY_API
#define _GetAppPathEntryExW(szDll,szEntry,szValue,pcbMaxLen) \
    ((szDll),(szEntry),(szValue),(pcbMaxLen),FALSE)
#define _GetAppPathEntryW(szDll,szEntry,szValue,cbMaxLen) \
    ((szDll),(szEntry),(szValue),(cbMaxLen),FALSE)
#define _GetAppPathEntryExA(szDll,szEntry,szValue,pcbMaxLen) \
    ((szDll),(szEntry),(szValue),(pcbMaxLen),FALSE)
#define _GetAppPathEntryA(szDll,szEntry,szValue,cbMaxLen) \
    ((szDll),(szEntry),(szValue),(cbMaxLen),FALSE)
#endif // DISABLE_REGISTRY_API

#ifdef CALLEE_CHECK
static inline BOOL
GetAppPathExW (LPCWSTR szDll, LPWSTR szPath, DWORD *pcbMaxLen, BOOL bNotUseThisFilePath)
{
    BOOL bGlobResult = FALSE;
    BOOL bResult;
    DWORD cbRegPathLen = MAX_PATH * sizeof(WCHAR);
    WCHAR *wszRegisteredPath = (WCHAR *)LocalAlloc(LPTR, cbRegPathLen);
    WCHAR *wszThisFileName = (WCHAR *)LocalAlloc(LPTR, cbRegPathLen);
    LPWSTR wszThisFileShortName;

    if (!wszRegisteredPath || !wszThisFileName)
	goto error;
    // заполним полное и короткое имя текущего DLL
    if (!GetThisModuleFileNameW(wszThisFileName, MAX_PATH))
	goto error;
    wszThisFileShortName = wcsrchr (wszThisFileName, L'\\');
    if (!wszThisFileShortName) // С относительными путями не работаем!
	goto error;
    ++wszThisFileShortName; // смещаемся на начало имени файла
    if ( bNotUseThisFilePath )
    {
	bResult = _GetAppPathEntryExW (wszThisFileShortName, L"",
	    wszRegisteredPath, &cbRegPathLen);
	if (bResult) {
	    // Если текущий DLL зарегистрирован в AppPath, работаем, как раньше
	    if (CompareStringW (LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE,
		wszThisFileName, -1, wszRegisteredPath, -1) == CSTR_EQUAL) 
	    {
		bGlobResult = _GetAppPathEntryExW (szDll, L"", szPath, pcbMaxLen);
		if ( bGlobResult)//работаем как раньше, только если существует запись в apppath, иначе будем строить текущий путь
		    goto error;
	    }
	}
    }
    else
    {
	// Текущий DLL не зарегистрирован в AppPath, либо зарегистрирован
	// другой DLL. Работаем с целевым DLL, который находится в том же
	// каталоге с текущим DLL
	*wszThisFileShortName = 0; // Затираем следующий символ за слэшом нулем
	if (__wcscat_s(wszThisFileName, MAX_PATH, szDll))
	    goto error;
	if (!szPath) {
	    *pcbMaxLen = (DWORD)((wcslen(wszThisFileName) + 1) * sizeof(WCHAR));
	    bGlobResult = TRUE;
	    goto error;
	}
	cbRegPathLen = (DWORD)((wcslen(wszThisFileName) + 1) * sizeof(WCHAR));
	if (*pcbMaxLen < cbRegPathLen) {
	    *pcbMaxLen = cbRegPathLen;
	    goto error;
	}
	// Хочу воспользоватся функцией __wcscat_s вместо wcscpy_s,
	// для чего делаю пустой строкой szPath, а потом доклеиваю szDll.
	*szPath = 0;
	if (__wcscat_s(szPath, *pcbMaxLen/sizeof(WCHAR), wszThisFileName))
	    goto error;

	bGlobResult = TRUE;
    }
error:
    LocalFree(wszRegisteredPath);
    LocalFree(wszThisFileName);
    return bGlobResult;
}

static inline BOOL
GetAppPathExA (LPCSTR szDll, LPSTR szPath, DWORD *pcbMaxLen)
{
    BOOL bGlobResult = FALSE;
    BOOL bResult;
    DWORD cbRegPathLen = MAX_PATH  * sizeof(char);
    char *szRegisteredPath = (char *)LocalAlloc(LPTR, cbRegPathLen);
    char *szThisFileName = (char *)LocalAlloc(LPTR, cbRegPathLen);
    LPSTR szThisFileShortName;

    if (!szRegisteredPath || !szThisFileName)
	goto error;
    // заполним полное и короткое имя текущего DLL
    if (!GetThisModuleFileNameA(szThisFileName, MAX_PATH))
	goto error;
    szThisFileShortName = strrchr (szThisFileName, '\\');
    if (!szThisFileShortName) // С относительными путями не работаем!
	goto error;
    ++szThisFileShortName; // смещаемся на начало имени файла
    bResult = _GetAppPathEntryExA (szThisFileShortName, "",
	szRegisteredPath, &cbRegPathLen);
    if (bResult) {
	// Если текущий DLL зарегистрирован в AppPath, работаем, как раньше
	if (CompareStringA (LOCALE_SYSTEM_DEFAULT, NORM_IGNORECASE,
	    szThisFileName, -1, szRegisteredPath, -1) == CSTR_EQUAL)
	{
	    bGlobResult = _GetAppPathEntryExA (szDll, "", szPath, pcbMaxLen);
	    if ( bGlobResult )//работаем как раньше, только если существует запись в apppath, иначе будем строить текущий путь
		goto error;
	}
    }
    // Текущий DLL не зарегистрирован в AppPath, либо зарегистрирован
    // другой DLL. Работаем с целевым DLL, который находится в том же
    // каталоге с текущим DLL
    *szThisFileShortName = 0; // Затираем следующий символ за слэшом нулем
    if (__strcat_s(szThisFileName, MAX_PATH, szDll))
	goto error;
    if (!szPath) {
	*pcbMaxLen = (DWORD)((strlen(szThisFileName) + 1) * sizeof(char));
	bGlobResult = TRUE;
	goto error;
    }
    cbRegPathLen = (DWORD)((strlen(szThisFileName) + 1) * sizeof(char));
    if (*pcbMaxLen < cbRegPathLen) {
	*pcbMaxLen = cbRegPathLen;
	goto error;
    }
    // Хочу воспользоватся функцией __strcat_s вместо strcpy_s,
    // для чего делаю пустой строкой szPath, а потом доклеиваю szDll.
    *szPath = 0;
    if (__strcat_s(szPath, *pcbMaxLen/sizeof(char), szThisFileName))
	goto error;

    bGlobResult = TRUE;
error:
    LocalFree(szRegisteredPath);
    LocalFree(szThisFileName);
    return bGlobResult;
}
#else // !CALLEE_CHECK
static inline BOOL GetModulePathW( LPWSTR szPath )
{
    // заполним полное и короткое имя текущего DLL
    if ( GetThisModuleFileNameW( szPath, MAX_PATH ) )
    {
	LPWSTR wszThisFileShortName = wcsrchr( szPath, L'\\' );
	if ( !wszThisFileShortName ) // С относительными путями не работаем!
	    return FALSE;
	++wszThisFileShortName; // смещаемся на начало имени файла
	// Работаем с целевым DLL, который находится в том же
	// каталоге с текущим DLL
	*wszThisFileShortName = 0; // Затираем следующий символ за слэшом нулем
	return TRUE;
    }
    return FALSE;
}


static WCHAR g_ThisModulePath[MAX_PATH] = { 0 };

inline BOOL InitModulePath()
{
    return GetModulePathW( g_ThisModulePath );
}

static inline BOOL
GetAppPathExW( LPCWSTR szDll, LPWSTR szPath, DWORD *pcbMaxLen, BOOL bNotUseThisFilePath )
{
    WCHAR *wszThisFileName = NULL;
    BOOL bGlobResult = FALSE;
    if( bNotUseThisFilePath )
    {
	bGlobResult = _GetAppPathEntryExW( szDll, L"", szPath, pcbMaxLen );
    }
    else
    {
	DWORD cbRegPathLen = MAX_PATH * sizeof( WCHAR );

	wszThisFileName = (WCHAR *)LocalAlloc( LMEM_FIXED, cbRegPathLen );
	
	if( !wszThisFileName )
	    goto error;

	if ( *g_ThisModulePath == 0 )
	{
	    if (!GetModulePathW( wszThisFileName ) )
		goto error;
	}
	else
	{
	    *wszThisFileName = 0;
	    if ( __wcscat_s( wszThisFileName, MAX_PATH, g_ThisModulePath ) )
		goto error;
	}

	if( __wcscat_s( wszThisFileName, MAX_PATH, szDll ) )
	    goto error;
	cbRegPathLen = (DWORD)( ( wcslen( wszThisFileName ) + 1 ) * sizeof( WCHAR ) );
	if( !szPath ) {
	    *pcbMaxLen = cbRegPathLen;
	    bGlobResult = TRUE;
	    goto error;
	}

	if( *pcbMaxLen < cbRegPathLen ) {
	    *pcbMaxLen = cbRegPathLen;
	    goto error;
	}
	// Хочу воспользоватся функцией __wcscat_s вместо wcscpy_s,
	// для чего делаю пустой строкой szPath, а потом доклеиваю szDll.
	*szPath = 0;
	if( __wcscat_s( szPath, *pcbMaxLen / sizeof( WCHAR ), wszThisFileName ) )
	    goto error;

	bGlobResult = TRUE;
    }
error:
    if( wszThisFileName )
        LocalFree(wszThisFileName);
    return bGlobResult;
}

static inline BOOL
GetAppPathExA (LPCSTR szDll, LPSTR szPath, DWORD *pcbMaxLen)
{
    BOOL bGlobResult = FALSE;
    DWORD cbRegPathLen = MAX_PATH  * sizeof(char);
    char *szRegisteredPath = (char *)LocalAlloc(LPTR, cbRegPathLen);
    char *szThisFileName = (char *)LocalAlloc(LPTR, cbRegPathLen);
    char *szThisFileShortName = NULL;

    if (!szRegisteredPath || !szThisFileName)
	goto error;

    bGlobResult = _GetAppPathEntryExA( szDll, "", szPath, pcbMaxLen );
    if( bGlobResult )//работаем как раньше, только если существует запись в apppath, иначе будем строить текущий путь
	goto error;

    // заполним полное и короткое имя текущего DLL
    if (!GetThisModuleFileNameA(szThisFileName, MAX_PATH))
	goto error;
    szThisFileShortName = strrchr (szThisFileName, '\\');
    if (!szThisFileShortName) // С относительными путями не работаем!
	goto error;
    ++szThisFileShortName; // смещаемся на начало имени файла

    // Работаем с целевым DLL, который находится в том же
    // каталоге с текущим DLL
    *szThisFileShortName = 0; // Затираем следующий символ за слэшом нулем    
    if (__strcat_s(szThisFileName, MAX_PATH, szDll))
	goto error;
    cbRegPathLen = (DWORD)( ( strlen( szThisFileName ) + 1 ) * sizeof( char ) );
    if (!szPath) {
	*pcbMaxLen = cbRegPathLen;
	bGlobResult = TRUE;
	goto error;
    }    
    if (*pcbMaxLen < cbRegPathLen) {
	*pcbMaxLen = cbRegPathLen;
	goto error;
    }
    // Хочу воспользоватся функцией __strcat_s вместо strcpy_s,
    // для чего делаю пустой строкой szPath, а потом доклеиваю szDll.
    *szPath = 0;
    if (__strcat_s(szPath, *pcbMaxLen/sizeof(char), szThisFileName))
	goto error;

    bGlobResult = TRUE;
error:
    LocalFree(szRegisteredPath);
    LocalFree(szThisFileName);
    return bGlobResult;
}
#endif // !CALLEE_CHECK

#ifndef __cplusplus
#undef inline
#endif // !__cplusplus

#endif /* _APPPATH_H_INCLUDED */
/* end of file: $Id: apppath.h 191428 2019-04-01 16:17:10Z maxdm $ */
