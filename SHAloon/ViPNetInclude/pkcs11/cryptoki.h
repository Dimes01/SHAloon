/* cryptoki.h include file for PKCS #11. */
/* $Revision: 1.4 $ */

/* License to copy and use this software is granted provided that it is
 * identified as "RSA Security Inc. PKCS #11 Cryptographic Token Interface
 * (Cryptoki)" in all material mentioning or referencing this software.

 * License is also granted to make and use derivative works provided that
 * such works are identified as "derived from the RSA Security Inc. PKCS #11
 * Cryptographic Token Interface (Cryptoki)" in all material mentioning or 
 * referencing the derived work.

 * RSA Security Inc. makes no representations concerning either the 
 * merchantability of this software or the suitability of this software for
 * any particular purpose. It is provided "as is" without express or implied
 * warranty of any kind.
 */

/* This is a sample file containing the top level include directives
 * for building WIN32 Cryptoki libraries and applications.
 */

#ifndef ___CRYPTOKI_H_INC___
#define ___CRYPTOKI_H_INC___

#ifdef _WIN32
#    pragma pack(push, cryptoki, 1)
#endif

/* Specifies that the function is a DLL entry point. */
#if defined(_WIN32) && !defined(PKCS11_NO_DYNAMIC)
#    define CK_IMPORT_SPEC __declspec(dllimport)
#else
#    define CK_IMPORT_SPEC
#endif /* __unix__ */

/* Define CRYPTOKI_EXPORTS during the build of cryptoki libraries. Do
 * not define it in applications.
 */
#ifdef _WIN32
#    ifdef CRYPTOKI_EXPORTS
/* Specified that the function is an exported DLL entry point. */
#         define CK_EXPORT_SPEC __declspec(dllexport) 
#    else
#         define CK_EXPORT_SPEC CK_IMPORT_SPEC 
#    endif
#else
#    define CK_EXPORT_SPEC
#endif /* __unix__ */

/* Ensures the calling convention for WIN32 builds */
#ifdef _WIN32
#    define CK_CALL_SPEC __cdecl
#else
#    define CK_CALL_SPEC
#endif /* __unix__ */

#define CK_PTR *

#define CK_DEFINE_FUNCTION(returnType, name) \
  returnType CK_EXPORT_SPEC CK_CALL_SPEC name

#define CK_DECLARE_FUNCTION(returnType, name) \
  returnType CK_EXPORT_SPEC CK_CALL_SPEC name

#define CK_DECLARE_FUNCTION_POINTER(returnType, name) \
  returnType CK_IMPORT_SPEC (CK_CALL_SPEC CK_PTR name)

#define CK_CALLBACK_FUNCTION(returnType, name) \
  returnType (CK_CALL_SPEC CK_PTR name)

#ifndef NULL_PTR
#    define NULL_PTR 0
#endif

#include "pkcs11.h"

#ifdef _WIN32
#    pragma pack(pop, cryptoki)
#endif

#endif /* ___CRYPTOKI_H_INC___ */
