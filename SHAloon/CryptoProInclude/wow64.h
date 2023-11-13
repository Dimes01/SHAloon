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
 * \version $Revision: 191395 $
 * \date $Date:: 2019-04-01 14:11:33 +0300#$
 * \author $Author: maxdm $
 *
 * \brief Интерфейс wow64
 */

#ifndef _WOW64_H_INCLUDED
#define _WOW64_H_INCLUDED

#include <windows.h>
#include <wchar.h>

#ifndef _WIN64

#ifndef __cplusplus
#   define inline __inline
#endif // !__cplusplus

// WOW64 имеет смысл только когда компилируется 32-битное приложение,
// а запускается оно на 64-битной системе.
// TRUE - Wow64, FALSE - в остальных случаях

typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
inline BOOL IsWow64CurrentProcess(void)
{
    static LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS)-1;
    BOOL bWow64Process = FALSE;    

    if (fnIsWow64Process == (LPFN_ISWOW64PROCESS)-1) {
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
	    return FALSE;
	}
	fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(
	    hKernel32,"IsWow64Process");
    }
    if (fnIsWow64Process == 0) {
	// Для Windows 2000, где нет никакого понятия про WOW64	
	return FALSE;
    }
    if ( !fnIsWow64Process(GetCurrentProcess(), &bWow64Process) )
	return FALSE;
    return bWow64Process;
}

typedef BOOL (WINAPI *LPFN_WOW64DISABLEWOW64FSREDIRECTION) ( PVOID* );
inline BOOL DisableWow64FsRedirection(PVOID *OldValue)
{    
    static LPFN_WOW64DISABLEWOW64FSREDIRECTION fnWow64DisableWow64FsRedirection = (LPFN_WOW64DISABLEWOW64FSREDIRECTION)-1;
    
    if (fnWow64DisableWow64FsRedirection == (LPFN_WOW64DISABLEWOW64FSREDIRECTION)-1) {
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
	    return FALSE;
	}
	fnWow64DisableWow64FsRedirection = (LPFN_WOW64DISABLEWOW64FSREDIRECTION)GetProcAddress(
	    hKernel32,"Wow64DisableWow64FsRedirection");
    }
    if (fnWow64DisableWow64FsRedirection == 0) {
	return TRUE;
    }
    return fnWow64DisableWow64FsRedirection(OldValue);
}

typedef BOOL (WINAPI *LPFN_WOW64REVERTWOW64FSREDIRECTION) ( PVOID );
inline BOOL RevertWow64FsRedirection(PVOID OldValue)
{    
    static LPFN_WOW64REVERTWOW64FSREDIRECTION fnRevertWow64FsRedirection = (LPFN_WOW64REVERTWOW64FSREDIRECTION)-1;

    if (fnRevertWow64FsRedirection == (LPFN_WOW64REVERTWOW64FSREDIRECTION)-1) {
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
	    return FALSE;
	}
	fnRevertWow64FsRedirection = (LPFN_WOW64REVERTWOW64FSREDIRECTION)GetProcAddress(
	    hKernel32,"Wow64RevertWow64FsRedirection");
    }
    if (fnRevertWow64FsRedirection == 0) {
	return TRUE;
    }
    return fnRevertWow64FsRedirection(OldValue);
}

#endif

#ifndef __cplusplus
#undef inline
#endif // !__cplusplus

#endif /* _WOW64_H_INCLUDED */
/* end of file: $Id: apppath.h 191395 2019-04-01 11:11:33Z maxdm $ */
