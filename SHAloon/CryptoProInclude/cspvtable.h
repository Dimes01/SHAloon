/*
 * Copyright(C) 2000-2006 Проект ИОК
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
 * \version $Revision: 207435 $
 * \date $Date:: 2020-02-28 14:03:16 +0300#$
 * \author $Author: frolov $
 *
 * \brief Определение VTABLEPROVSTRUC.
 *
 * Содержит определение VTABLEPROVSTRUC и PVTABLEPROVSTRUC для использования
 * в других заголовочных файлах.
 */
#ifndef _CSP_VTABLE_H_INCLUDED
#define _CSP_VTABLE_H_INCLUDED

#if defined(UNIX)
#include "CSP_WinDef.h"
#else // defined(UNIX)
#include <windef.h>
#endif // defined(UNIX)

#if defined(__cplusplus)
extern "C" {
#endif // defined(__cplusplus)

typedef BOOL (WINAPI *CRYPT_VERIFY_IMAGE_A)(LPCSTR  szImage, CONST BYTE *pbSigData);
typedef void (WINAPI *CRYPT_RETURN_HWND)(HWND *phWnd);

typedef struct _VTABLEPROVSTRUC {
    DWORD   Version; 
    CRYPT_VERIFY_IMAGE_A FuncVerifyImage;
    CRYPT_RETURN_HWND    FuncReturnhWnd;
    DWORD   dwProvType; 
    BYTE    *pbContextInfo; 
    DWORD   cbContextInfo;
    LPSTR   pszProvName;
} VTABLEPROVSTRUC, *PVTABLEPROVSTRUC;

#if defined(__cplusplus)
} // extern "C"
#endif // defined(__cplusplus)

#endif /* _CSP_VTABLE_H_INCLUDED */
