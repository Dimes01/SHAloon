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
 * \version $Revision: 132389 $
 * \date $Date:: 2015-12-25 12:44:02 +0300#$
 * \author $Author: borodin $
 *
 * \brief Интерфейс Microsoft Cryptography Service Provider.
 *
 * Содержит прототипы функций, которые должен предоставлять любой CSP.
 */
#ifndef _WINCSP_H_INCLUDED
#define _WINCSP_H_INCLUDED

#include "cspvtable.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CSP_EXPORT
#define CSP_EXPORT extern
#endif /* CSP_EXPORT */

#define CPREGSTR_PATH_PROVIDER _TEXT("Software\\Microsoft\\Cryptography\\Defaults\\Provider")

CSP_EXPORT BOOL WINAPI CPAcquireContext (
    /* [out] */ HCRYPTPROV *phProv,
    /* [string][in] */ CHAR *pszContainer,
    /* [in] */ DWORD dwFlags,
    /* [in] */ PVTABLEPROVSTRUC pVTable);

CSP_EXPORT BOOL WINAPI CPReleaseContext (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ DWORD dwFlags);

CSP_EXPORT BOOL WINAPI CPGetProvParam ( 
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ DWORD dwParam,
    /* [size_is][out] */ BYTE *pbData,
    /* [out][in] */ DWORD *pdwDataLen,
    /* [in] */ DWORD dwFlags);

CSP_EXPORT BOOL WINAPI CPSetProvParam (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ DWORD dwParam,
    /* [size_is][in] */ BYTE *pbData,
    /* [in] */ DWORD dwFlags);

CSP_EXPORT BOOL WINAPI CPGenKey (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ ALG_ID AlgId,
    /* [in] */ DWORD dwFlags,
    /* [out] */ HCRYPTKEY *phKey);

CSP_EXPORT BOOL WINAPI CPDestroyKey (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTKEY hKey);

CSP_EXPORT BOOL WINAPI CPCreateHash (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ ALG_ID AlgId,
    /* [in] */ HCRYPTKEY hKey,
    /* [in] */ DWORD dwFlags,
    /* [out] */ HCRYPTHASH *phHash);

CSP_EXPORT BOOL WINAPI CPDestroyHash (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTHASH hHash);

CSP_EXPORT BOOL WINAPI CPEncrypt (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTKEY hKey,
    /* [in] */ HCRYPTHASH hHash,
    /* [in] */ BOOL Final,
    /* [in] */ DWORD dwFlags,
    /* [size_is][out][in] */ BYTE *pbData,
    /* [out][in] */ DWORD *pdwDataLen,
    /* [in] */ DWORD dwBufLen);

CSP_EXPORT BOOL WINAPI CPDecrypt (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTKEY hKey,
    /* [in] */ HCRYPTHASH hHash,
    /* [in] */ BOOL Final,
    /* [in] */ DWORD dwFlags,
    /* [full][size_is][out][in] */ BYTE *pbData,
    /* [out][in] */ DWORD *pdwDataLen);

CSP_EXPORT BOOL WINAPI CPDeriveKey (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ ALG_ID AlgId,
    /* [in] */ HCRYPTHASH hBaseData,
    /* [in] */ DWORD dwFlags,
    /* [out] */ HCRYPTKEY *phKey);

CSP_EXPORT BOOL WINAPI CPDuplicateKey (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTKEY hKey,
    /* [full][in] */ DWORD *pdwReserved,
    /* [in] */ DWORD dwFlags,
    /* [out] */ HCRYPTKEY *phKey);

CSP_EXPORT BOOL WINAPI CPDuplicateHash (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTHASH hHash,
    /* [full][in] */ DWORD *pdwReserved,
    /* [in] */ DWORD dwFlags,
    /* [out] */ HCRYPTHASH *phHash);

CSP_EXPORT BOOL WINAPI CPExportKey (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTKEY hKey,
    /* [in] */ HCRYPTKEY hExpKey,
    /* [in] */ DWORD dwBlobType,
    /* [in] */ DWORD dwFlags,
    /* [full][size_is][out][in] */ BYTE *pbData,
    /* [out][in] */ DWORD *pdwDataLen);

CSP_EXPORT BOOL WINAPI CPGenRandom (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ DWORD dwLen,
    /* [size_is][out][in] */ BYTE *pbBuffer);

CSP_EXPORT BOOL WINAPI CPGetHashParam (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTHASH hHash,
    /* [in] */ DWORD dwParam,
    /* [full][size_is][out][in] */ BYTE *pbData,
    /* [out][in] */ DWORD *pdwDataLen,
    /* [in] */ DWORD dwFlags);

CSP_EXPORT BOOL WINAPI CPGetKeyParam (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTKEY hKey,
    /* [in] */ DWORD dwParam,
    /* [full][size_is][out][in] */ BYTE *pbData,
    /* [out][in] */ DWORD *pdwDataLen,
    /* [in] */ DWORD dwFlags);

CSP_EXPORT BOOL WINAPI CPGetUserKey (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ DWORD dwKeySpec,
    /* [out] */ HCRYPTKEY *phUserKey);

CSP_EXPORT BOOL WINAPI CPHashData (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTHASH hHash,
    /* [full][size_is][in] */ CONST BYTE *pbData,
    /* [in] */ DWORD dwDataLen,
    /* [in] */ DWORD dwFlags);

CSP_EXPORT BOOL WINAPI CPHashSessionKey (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTHASH hHash,
    /* [in] */ HCRYPTKEY hKey,
    /* [in] */ DWORD dwFlags);

CSP_EXPORT BOOL WINAPI CPImportKey (
    /* [in] */ HCRYPTPROV hProv,
    /* [full][size_is][in] */ CONST BYTE *pbData,
    /* [in] */ DWORD dwDataLen,
    /* [in] */ HCRYPTKEY hImpKey,
    /* [in] */ DWORD dwFlags,
    /* [out] */ HCRYPTKEY *phKey);

CSP_EXPORT BOOL WINAPI CPSetHashParam (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTHASH hHash,
    /* [in] */ DWORD dwParam,
    /* [size_is][in] */ BYTE *pbData,
    /* [in] */ DWORD dwFlags);

CSP_EXPORT BOOL WINAPI CPSetKeyParam (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTKEY hKey,
    /* [in] */ DWORD dwParam,
    /* [size_is][in] */ BYTE *pbData,
    /* [in] */ DWORD dwFlags);

CSP_EXPORT BOOL WINAPI CPSignHash (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTHASH hHash,
    /* [in] */ DWORD dwKeySpec,
    /* [string][full][in] */ LPCWSTR sDescription,
    /* [in] */ DWORD dwFlags,
    /* [size_is][out][in] */ BYTE *pbSignature,
    /* [out][in] */ DWORD *pdwSigLen);

CSP_EXPORT BOOL WINAPI CPVerifySignature (
    /* [in] */ HCRYPTPROV hProv,
    /* [in] */ HCRYPTHASH hHash,
    /* [size_is][in] */ CONST BYTE *pbSignature,
    /* [in] */ DWORD dwSigLen,
    /* [in] */ HCRYPTKEY hPubKey,
    /* [string][full][in] */ LPCWSTR sDescription,
    /* [in] */ DWORD dwFlags);


/*======================================================*/
/* Инициализация и параметры криптопровайдера */

/*------------------------------------------------------*/
/* Определение функции CPAcquireContext*/
typedef BOOL (WINAPI *CPAcquireContext_t) (
    HCRYPTPROV *phProv,       /* out*/
    CHAR *pszContainer,       /* in, out*/
    DWORD dwFlags,            /* in*/
    PVTABLEPROVSTRUC pVTable  /* in*/
);

/*------------------------------------------------------*/
/* Определение функции CPReleaseContext */
typedef BOOL (WINAPI *CPReleaseContext_t) (
    HCRYPTPROV hProv,  /* in*/
    DWORD dwFlags      /* in*/
);

/*------------------------------------------------------*/
/* Определение функции CPGetProvParam */
typedef BOOL (WINAPI *CPGetProvParam_t) (
    HCRYPTPROV hProv,  /* in*/
    DWORD dwParam,     /* in*/
    BYTE *pbData,      /* out*/
    DWORD *pdwDataLen, /* in, out*/
    DWORD dwFlags      /* in*/
);

/*------------------------------------------------------*/
/* Определение функции CPSetProvParam */
typedef BOOL (WINAPI *CPSetProvParam_t) (
    HCRYPTPROV hProv,  /* in*/
    DWORD dwParam,     /* in*/
    BYTE *pbData,      /* in*/
    DWORD dwFlags      /* in*/
);

/*======================================================*/
/* Функции генерации и работы с ключами */

/*------------------------------------------------------*/
/* Определение функции CPGenKey */
typedef BOOL (WINAPI *CPGenKey_t) (
    HCRYPTPROV hProv,     /* in*/
    ALG_ID Algid,         /* in*/
    DWORD dwFlags,        /* in*/
    HCRYPTKEY *phKey     /* out*/
);

/*------------------------------------------------------*/
/* Определение функции CPDestroyKey */
typedef BOOL (WINAPI *CPDestroyKey_t) (
    HCRYPTPROV hProv,  /* in*/
    HCRYPTKEY  hKey    /* in*/
);

/*------------------------------------------------------*/
/* Определение функции CPDeriveKey */
typedef BOOL (WINAPI *CPDeriveKey_t) ( 
	HCRYPTPROV hProv,		/* in*/
	ALG_ID AlgId,			/* in*/
	HCRYPTHASH hBaseData,	/* in*/
	DWORD dwFlags,			/* in*/
	HCRYPTKEY *phKey		/* out*/
);

/*------------------------------------------------------*/
/* Определение функции CPDuplicateKey */
typedef BOOL (WINAPI *CPDuplicateKey_t) ( 
	HCRYPTPROV hProv,		/* in*/
	HCRYPTKEY hKey,			/* in*/
	DWORD *pdwReserved,		/* in*/
	DWORD dwFlags,			/* in*/
	HCRYPTKEY *phKey		/* out*/
);

/*------------------------------------------------------*/
/* Определение функции CPExportKey */
typedef BOOL (WINAPI *CPExportKey_t) (
    HCRYPTPROV hProv,      /* in*/
    HCRYPTKEY hKey,        /* in*/
    HCRYPTKEY hPubKey,     /* in*/
    DWORD dwBlobType,      /* in*/
    DWORD dwFlags,         /* in*/
    BYTE *pbData,          /* out*/
    DWORD *pdwDataLen	   /* in, out*/
);

/*------------------------------------------------------*/
/* Определение функции CPGenRandom */
typedef BOOL (WINAPI *CPGenRandom_t) ( 
	HCRYPTPROV hProv,		/* in*/
	DWORD dwLen,			/* in*/
	BYTE *pbBuffer			/* in, out*/
);

/*------------------------------------------------------*/
/* Определение функции CPGetKeyParam*/
typedef BOOL (WINAPI *CPGetKeyParam_t) (
    HCRYPTPROV hProv,       /* in*/
    HCRYPTKEY hKey,         /* in*/
    DWORD dwParam,          /* in*/
    BYTE *pbData,           /* out*/
    DWORD *pdwDataLen,      /* in, out*/
    DWORD dwFlags           /* in*/
);

/*------------------------------------------------------*/
/* Определение функции CPGetUserKey */
typedef BOOL (WINAPI *CPGetUserKey_t) (
    HCRYPTPROV hProv,      
    DWORD dwKeySpec,       
    HCRYPTKEY *phUserKey   
);

/*------------------------------------------------------*/
/* Определение функции CPImportKey */
typedef BOOL (WINAPI *CPImportKey_t) (
    HCRYPTPROV hProv,       /* in*/
    CONST BYTE *pbData,     /* in*/
    DWORD  dwDataLen,       /* in*/
    HCRYPTKEY hPubKey,      /* in*/
    DWORD dwFlags,          /* in*/
HCRYPTKEY *phKey        /* out*/
);

/*------------------------------------------------------*/
/* Определение функции CPSetKeyParam*/
typedef BOOL (WINAPI *CPSetKeyParam_t) (
    HCRYPTPROV hProv,       /* in*/
    HCRYPTKEY hKey,         /* in*/
    DWORD dwParam,          /* in*/
    BYTE *pbData,           /* in*/
    DWORD dwFlags           /* in*/
);

/*======================================================*/
/* Функции шифрования/расшифрования данных */

/*------------------------------------------------------*/
/* Определение функции CPEncrypt*/
typedef BOOL (WINAPI *CPEncrypt_t) ( 
	HCRYPTPROV hProv,		/* in*/
	HCRYPTKEY hKey,			/* in*/
	HCRYPTHASH hHash,		/* in*/
	BOOL Final,				/* in*/
	DWORD dwFlags,			/* in*/
	BYTE *pbData,			/* in, out*/
	DWORD *pdwDataLen,		/* in, out*/
	DWORD dwBufLen			/* in*/
);

/*------------------------------------------------------*/
/* Определение функции CPDecrypt*/
typedef BOOL (WINAPI *CPDecrypt_t) (
	HCRYPTPROV hProv,		/* in*/
	HCRYPTKEY hKey,			/* in*/
	HCRYPTHASH hHash,		/* in*/
	BOOL Final,				/* in*/
	DWORD dwFlags,			/* in*/
	BYTE *pbData,			/* in, out*/
	DWORD *pdwDataLen		/* in, out*/
);

/*======================================================*/
/* Функции хэширования и ЭЦП */

/*------------------------------------------------------*/
/* Определение функции CPCreateHash */
typedef BOOL (WINAPI *CPCreateHash_t) (
    HCRYPTPROV hProv,    /* in*/
    ALG_ID Algid,        /* in*/
    HCRYPTKEY hKey,      /* in*/
    DWORD dwFlags,       /* in*/
    HCRYPTHASH *phHash   /* out*/
);

/*------------------------------------------------------*/
/* Определение функции CPDestroyHash */
typedef BOOL (WINAPI *CPDestroyHash_t) (
    HCRYPTPROV hProv, /* in*/
    HCRYPTHASH hHash  /* in*/
);

/*------------------------------------------------------*/
/* Определение функции CPDuplicateHash */
typedef BOOL (WINAPI *CPDuplicateHash_t) ( 
	HCRYPTPROV hProv, 
	HCRYPTHASH hHash,		/* in*/ 
	DWORD *pdwReserved,		/* in*/
	DWORD dwFlags,			/* in*/
	HCRYPTHASH *phHash		/* out*/
);

/*------------------------------------------------------*/
/* Определение функции CPGetHashParam */
typedef BOOL (WINAPI *CPGetHashParam_t) (
    HCRYPTPROV hProv,        /* in*/
    HCRYPTHASH hHash,        /* in*/
    DWORD dwParam,           /* in*/
    BYTE *pbData,            /* out*/
    DWORD *pdwDataLen,       /* in, out*/
    DWORD dwFlags            /* in*/
);

/*------------------------------------------------------*/
/* Определение функции CPHashData */
typedef BOOL (WINAPI *CPHashData_t) (
    HCRYPTPROV hProv,       /* in*/
    HCRYPTHASH hHash,       /* in*/
    CONST BYTE *pbData,     /* in*/
    DWORD dwDataLen,        /* in*/
    DWORD dwFlags           /* in*/
);

/*------------------------------------------------------*/
/* Определение функции CPHashSessionKey */
typedef BOOL (WINAPI *CPHashSessionKey_t) ( 
	HCRYPTPROV hProv,		/* in*/
	HCRYPTHASH hHash,		/* in*/
	HCRYPTKEY hKey,			/* in*/
	DWORD dwFlags			/* in*/
);

/*------------------------------------------------------*/
/* Определение функции CPGetHashParam */
typedef BOOL (WINAPI *CPSetHashParam_t) (
    HCRYPTPROV hProv,        /* in*/
    HCRYPTHASH hHash,        /* in*/
    DWORD dwParam,           /* in*/
    BYTE *pbData,            /* out*/
    DWORD dwFlags            /* in*/
);

/*------------------------------------------------------*/
/* Определение функции CPSignHash */
typedef BOOL (WINAPI *CPSignHash_t) (
    HCRYPTPROV hProv,           /* in*/
    HCRYPTHASH hHash,           /* in*/
    DWORD dwKeySpec,            /* in*/
    LPCWSTR sDescription,       /* in*/
    DWORD dwFlags,              /* in*/
    BYTE *pbSignature,          /* out*/
    DWORD *pdwSigLen            /* in, out*/
);

/*------------------------------------------------------*/
/* Определение функции CPVerifySignature */
typedef BOOL (WINAPI *CPVerifySignature_t) (
    HCRYPTPROV hProv,         /* in*/
    HCRYPTHASH hHash,         /* in*/
    CONST BYTE *pbSignature,  /* in*/
    DWORD dwSigLen,           /* in*/
    HCRYPTKEY hPubKey,        /* in*/
    LPCWSTR sDescription,     /* in*/
    DWORD dwFlags             /* in*/
);

/* Инициализация и параметры криптопровайдера */
typedef struct _CSP_FUNCTION_TABLE {
    CPAcquireContext_t	AcquireContext;
    CPReleaseContext_t	ReleaseContext;
    CPGetProvParam_t	GetProvParam;
    CPSetProvParam_t	SetProvParam;
    CPGenKey_t		GenKey;
    CPDestroyKey_t	DestroyKey;
    CPDeriveKey_t	DeriveKey;
    CPDuplicateKey_t	DuplicateKey;
    CPExportKey_t	ExportKey;
    CPGenRandom_t	GenRandom; 
    CPGetKeyParam_t	GetKeyParam;
    CPGetUserKey_t	GetUserKey;
    CPImportKey_t	ImportKey;
    CPSetKeyParam_t	SetKeyParam;
    CPEncrypt_t		Encrypt;
    CPDecrypt_t		Decrypt;
    CPCreateHash_t	CreateHash;
    CPDestroyHash_t	DestroyHash;
    CPDuplicateHash_t	DuplicateHash;
    CPGetHashParam_t	GetHashParam;
    CPHashData_t	HashData;
    CPHashSessionKey_t	HashSessionKey; 
    CPSetHashParam_t	SetHashParam;
    CPSignHash_t	SignHash;
    CPVerifySignature_t	VerifySignature;
} CSP_FUNCTION_TABLE, *PCSP_FUNCTION_TABLE;

CSP_EXPORT PCSP_FUNCTION_TABLE WINAPI CPGetFunctionTable (void);

typedef PCSP_FUNCTION_TABLE (WINAPI *CPGetFunctionTable_t) (void);

#ifdef __cplusplus
}
#endif

#endif /* _WINCSP_H_INCLUDED */
