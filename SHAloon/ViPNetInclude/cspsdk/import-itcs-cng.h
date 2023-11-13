/// @file 
/// @brief ViPNet ��������� ����������������� ����������� CNG
///
/// @copyright Copyright (c) InfoTeCS. All Rights Reserved.

#ifndef _ITC_IMPORT_ITCS_BCRYPT_H_
#define _ITC_IMPORT_ITCS_BCRYPT_H_

#include <cspsdk/import-itcs-crypt-base.h>

/// ������������� ViPNet CNG BCRYPT ����������, ���������������� ���� ���������
#define VPN_CNG_PROVIDER_CU_NAME                          L"Infotecs Primitive Provider CU"
/// ������������� ViPNet CNG BCRYPT ����������, ���������������� ���� ���������, ANSI ������
#define VPN_CNG_PROVIDER_CU_NAME_A                        "Infotecs Primitive Provider CU"

/// ������������� BCRYPT ����������, ���������������� ���� ���������
#define ITCS_BCRYPT_PROVIDER_NAME                         L"Infotecs Bcrypt Provider"
/// ������������� BCRYPT ����������, ���������������� ���� ���������, ANSI ������
#define ITCS_BCRYPT_PROVIDER_NAME_A                       "Infotecs Bcrypt Provider"

/// ��� ���������� �������� ������. Unicode ������.
/// ����������������� ��� � ����� ���� ������� � ��������� �������.
#define VPN_KEYSTORAGE_PROVIDER_NAME_W                    L"Infotecs Software Key Storage Provider"
/// ��� ���������� �������� ������. Ascii ������.
/// ����������������� ��� � ����� ���� ������� � ��������� �������.
#define VPN_KEYSTORAGE_PROVIDER_NAME_A                    "Infotecs Software Key Storage Provider"

/// ������������� ViPNet CNG BCRYPT ����������, ���������������� ���, Unicode ������
#define VPN_CNG_PROVIDER_RNG_W L"Infotecs UPRNG"
/// ������������� ViPNet CNG BCRYPT ����������, ���������������� ���, Ascii ������
#define VPN_CNG_PROVIDER_RNG_A  "Infotecs UPRNG"

// ==================================================================
// �������������� ����������
// ==================================================================

/// ������������� ��������� ����������� ���� � 34.11-94. RFC 4357. 
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_HASH_94_ALGID                      L"GOST R 34.11-94"

/// ������������� ��������� ����������� ���� � 34.11-2012 � ������ ������ 256 ���. 
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_HASH_2012_256_ALGID                L"GR 34.11-2012 256"

/// ������������� ��������� ����������� ���� � 34.11-2012 � ������ ������ 512 ���.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_HASH_2012_512_ALGID                L"GR 34.11-2012 512"

/// ������������� ��������� ���������� ���� 28147-89. RFC 4357. 
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_ENCRYPT_89_ALGID                   L"GOST 28147-89" 

/// ������������� ��������� ��� ��������� ����� ��� �������� ����� ���� 28147-89.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_89_EXPORT_KEY_HOLDER_ALGID          L"GOST 28147-89 EXPORT KEY HOLDER"

/// ������������� ��������� ���������� MAC. RFC 4357. ���� 28147-89.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_MAC_89_ALGID                       L"GOST 28147-89 MAC"

/// ������������� ��������� ���������� ���� � 34.12-2015 �����.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_ENCRYPT_MAGMA_ALGID                 L"GOST R 34.12-2015 MAGMA"

/// ������������� ��������� ���������� �� ���� � 34.12-2015 ����� � ������ CTR � ��������������� ���������� ������������
/// �� ���� � 34.13-2015, OMAC1 ��� ������������� ����� �����. �������� ������ � ��������� �� ��������� CMS.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_CMS_ENCRYPT_MAGMA_ALGID            L"MAGMA CMS ENCRYPT"

/// ������������� ��������� ��� ��������� ����� ��� �������� ����� ����� �� ������������� � 1323565.1.017-2018 (KExp15).
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_MAGMA_EXPORT_KEY_HOLDER_ALGID       L"MAGMA EXPORT KEY HOLDER"

/// ������������� ��������� ��������� ������������ �� ���� � 34.13-2015, OMAC1 ��� ������������� ����� �����.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_MAC_MAGMA_ALGID                     L"GOST R 34.12-2015 MAGMA MAC"

/// ������������� ��������� ���������� ���� � 34.12-2015 ��������.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_ENCRYPT_KUZNYECHIK_ALGID            L"GOST R 34.12-2015 KUZNYECHIK" 

/// ������������� ��������� ���������� �� ���� � 34.12-2015 �������� � ������ CTR � ��������������� ����������
/// ������������ �� ���� � 34.13-2015, OMAC1 ��� ������������� ����� ��������. �������� ������ � ��������� �� ��������� CMS.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_CMS_ENCRYPT_KUZNYECHIK_ALGID       L"KUZNYECHIK CMS ENCRYPT"

/// ������������� ��������� ��� ��������� ����� ��� �������� ����� �������� �� ������������� � 1323565.1.017-2018 (KExp15).
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_KUZNYECHIK_EXPORT_KEY_HOLDER_ALGID  L"KUZNYECHIK EXPORT KEY HOLDER"

/// ������������� ��������� ��������� ������������ �� ���� � 34.13-2015, OMAC1 ��� ������������� ����� ��������.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_MAC_KUZNYECHIK_ALGID                L"GOST R 34.12-2015 KUZNYECHIK MAC"

/// ������������� ��������� ������� ���� � 34.10-2001. RFC 4357. 
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_SIGN_2001_ALGID                    L"GOST R 34.10-2001"

/// ������������� ��������� ������������ ������ ���� � 34.10-2001. RFC 4357. 
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_DH_2001_ALGID                    L"DH 34.10-2001"

/// ������������� ��������� ������� ���� � 34.10-2012 � ������ ����� 256 ���.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_SIGN_2012_256_ALGID                L"GR 34.10-2012 256"

/// ������������� ��������� ������������ ������ ���� � 34.10-2012 � ������ ����� 256 ���.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_DH_2012_256_ALGID                L"DH 34.10-2012 256"

/// ������������� ��������� ������� ���� � 34.10-2012 � ������ ����� 512 ���.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_SIGN_2012_512_ALGID                L"GR 34.10-2012 512"

/// ������������� ��������� ������������ ������ ���� � 34.10-2012 � ������ ����� 512 ���.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_DH_2012_512_ALGID                L"DH 34.10-2012 512"

/// ������������� ��������� ���������� ������ ��������� ������������������, ������������� ��������� IV.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_RNG_ALGID                          L"ITCS-RNG-ALGORITHM"

/// ������������� ��������� ���������� ������ ��������� ������������������, ������������� ��������� ���������� ������.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_KEY_RNG_ALGID                       L"ITCS-KEY-RNG-ALGORITHM"

/// ������������� ��������� ���������� ������ ��������� ������������������, ������������� ��������� �����.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_MASK_RNG_ALGID                      L"ITCS-MASK-RNG-ALGORITHM"

/// ������������� ��������� ���������� ������ ��������� ������������������, ��� ��������� �������������� ������.
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_ADVANCED_RNG_ALGID                  L"ITCS-ADVANCED-RNG-ALGORITHM"

/// ������������� ��������� ���� TLS PRF
/// ������������ � ������� BCryptOpenAlgorithmProvider
#define BCRYPT_GOST_TLS_PRF_ALG_ID                     L"GOST-TLS-PRF"

/// ������������� ��������� KDF �������������� ����� �� RFC 4357
/// ������������ � ������� BCryptDeriveKey
#define BCRYPT_KDF_RFC_4357                            L"KDF_RFC_4357"

/// ������������� ��������� KDF �������������� ����� �� ���� � 50.1.113
/// ������������ � ������� BCryptDeriveKey
#define BCRYPT_KDF_GOSTR3411_2012_256                  L"KDF_GOSTR3411_2012_256"

/// ������������� ��������� KDF �������������� ����� �� NIST SP 800-108 � HMAC � �������� PRF � ������ ��������
/// ���� �������� ������������ KDF_GOSTR3411_2012_256, ���� ���� ���������� ������ DeriveKey �� �������� ��������
/// ����������� (KDF_HASH_ALGORITHM) � ������ ���� �������� (KDF_GOST_CTR_SIZE). ���� �� �������� ������ ��������
/// ����������� (KDF_HASH_ALGORITHM), � ������ ���� �������� (KDF_GOST_CTR_SIZE) ������, �� �������
/// KDF_TREE_GOSTR3411_2012_256
/// ������������ � ������� BCryptDeriveKey
/// ����� ������ ����� ������ �� Win7, �.�. ��� ����������� ������������� ������� � win8
#ifndef BCRYPT_SP800108_CTR_HMAC_ALGORITHM
#define BCRYPT_SP800108_CTR_HMAC_ALGORITHM              L"SP800_108_CTR_HMAC"
#endif

// ==================================================================
// �������������� ���� ������, ������������ � �������� BCryptImportKey � BCryptExportKey 
// ==================================================================

/// ��� ����� ��� ������������ ������������� ����-�����.
/// ������������ � �������� BCryptImportKey � BCryptExportKey 
#define BCRYPT_ITCS_SIMPLE_KEY_BLOB                     L"ItcsBcryptSimpleKeyBlob"

/// ��� ����� ������������ � �������� SIMPLEBLOB �� CSP ��� ���� ����������.
/// ������������ � �������� BCryptImportKey � BCryptExportKey 
#define LEGACY_GOST_SIMPLE_KEY_BLOB                    L"CAPIGostSimpleBlob"

/// ��� ����� ������������ � �������� PUBLICKEYBLOB �� CSP ��� ���� ����������.
/// ������������ � �������� BCryptImportKey � BCryptExportKey 
#define LEGACY_GOST_PUBLIC_KEY_BLOB                    L"CAPIGostPublicKeyBlob"

/// ��� ����� ������������ � �������� PRIVATEKEYBLOB �� CSP ��� ���� ����������.
/// ������������ � �������� BCryptImportKey � BCryptExportKey 
#define LEGACY_GOST_PRIVATE_KEY_BLOB                    L"CAPIGostPrivateKeyBlob"

#define BCRYPT_ITCS_SIMPLE_KEY_BLOB_MAGIC               0x534b424d  // SKBM
#define BCRYPT_ITCS_WRAPPED_KEY_BLOB_MAGIC              0x574b424d  // WKBM

// ==================================================================
// Magics ��� BCRYPT_PUBLIC_KEY_BLOB ���� ���������� 
// ==================================================================

//"G01_"
#define GOST_2001_PUBLIC_KEY_BLOB_MAGIC 0x5F313047

//"G12S"
#define GOST_12_256_PUBLIC_KEY_BLOB_MAGIC 0x53323147

//"G12L"
#define GOST_12_512_PUBLIC_KEY_BLOB_MAGIC 0x4C323147

// ==================================================================
// �������������� ����� ������ ������������ � �������� BCryptGetProperty � BCryptSetProperty
// ==================================================================

/// OID - ������������� ���������� �����������.
/// ������������ � �������� BCryptGetProperty � BCryptSetProperty
#define BCRYPT_ITCS_HASH_OID                       L"itcs-hash-oid"

/// OID - ������������� ���������� ����������� �������.
/// ������������ � �������� BCryptGetProperty � BCryptSetProperty
#define BCRYPT_ITCS_SIGNATURE_OID                  L"itcs-signature-oid"

/// ��������� ��������� ����� ��� ���������� ����������� �������.
/// ������������ � �������� BCryptGetProperty � BCryptSetProperty
#define BCRYPT_ITCS_PUBLIC_KEY_PARAMETERS               L"itcs-publickey-parameters"

/// OID - ������������� ���������� ����������.
/// ������������ � �������� BCryptGetProperty � BCryptSetProperty
#define BCRYPT_ITCS_CIPHER_OID                     L"itcs-cipher-oid"

/// ������� ����, ��� ���������� ������������� ������� �����.
/// ������������ � �������� BCryptGetProperty � BCryptSetProperty 
#define BCRYPT_ITCS_USE_MECHING_PERIOD             L"itcs-use-meshing-period"

/// ������ ������� �����.
/// ������������ � �������� BCryptGetProperty � BCryptSetProperty 
#define BCRYPT_ITCS_MESHING_PERIOD                      L"itcs-meshing-period"

/// �������� ��������� �����.
/// ������������ � ������� BCryptSetProperty 
#define BCRYPT_ITCS_PRIVATE_KEY_VALUE              L"itcs-private-key-value" 

/// C�������������� ��������� ������� �����������.
/// ������������ � �������� BCryptGetProperty � BCryptSetProperty 
#define BCRYPT_ITCS_HASH_STATE                     L"itcs-hash-state" //��������� ����

///������������� �������� ������������� �����.
///������������ � ����� ������(�������� hImportKey � ������� BCryptImportKey � �������� hExportKey � ������� BCryptExportKey), 
///�� ������� ���������� ������� / ������ ������� ������������� �����.
#define BCRYPT_ITCS_EXPORT_ID                      L"itcs-export-id"

/// �������� ��������-���������� - ������������ �������� ���.
#define BCRYPT_ITCS_RNG_REGLAMENT_CTRL            L"itcs-rng-reglament-ctrl"

/// UKM ��� VKO.
/// ������������ � ������� BCryptSetProperty 
#define BCRYPT_ITCS_VKO_UKM                             L"itcs-vko-ukm"


// ==================================================================
// �������������� �������� �������� BCRYPT_CHAINING_MODE
// ==================================================================
/// ����� �������� ��� ��������� ���������� ���� 28147-89
/// (��� ��������� ���������� ���� 28147-89 ������������� ������ CRYPT_MODE_OFB � CSP).
#define BCRYPT_CHAIN_MODE_GOST89_CNT    L"ChainingModeGost89CNT"

/// ����� ������������ �� ���� � 34.13-2015, CTR.
#define BCRYPT_CHAIN_MODE_GOST_34_13_2015_CTR           L"ChainingModeGost34_13_2015_CTR"

// ==================================================================
// �������� �������� BCRYPT_ITCS_CIPHER_OID
// ==================================================================

/// ��������� ��������� ���������� �� ���� 28147-89
/// A ParamSet. RFC 4357.
/// �������� �������� BCRYPT_ITCS_CIPHER_OID.
#define BCRYPT_ITCS_CIPHER_A_PARAM                 szOID_CPCSP_ENCR_DEF_PARAM_W

/// ��������� ��������� ���������� �� ���� 28147-89 �� ���������.
/// �������� �������� BCRYPT_ITCS_CIPHER_OID.
#define BCRYPT_ITCS_CIPHER_DEF_PARAM               BCRYPT_ITCS_CIPHER_A_PARAM

/// ��������� ��������� ���������� �� ���� 28147-89
/// B ParamSet. RFC 4357.
/// �������� �������� BCRYPT_ITCS_CIPHER_OID.
#define BCRYPT_ITCS_CIPHER_B_PARAM                 szOID_CPCSP_ENCR_B_PARAM_W

/// ��������� ��������� ���������� �� ���� 28147-89
/// � ParamSet. RFC 4357.
/// �������� �������� BCRYPT_ITCS_CIPHER_OID.
#define BCRYPT_ITCS_CIPHER_C_PARAM                 szOID_CPCSP_ENCR_C_PARAM_W

/// ��������� ��������� ���������� �� ���� 28147-89
/// � ParamSet. RFC 4357.
/// �������� �������� BCRYPT_ITCS_CIPHER_OID.
#define BCRYPT_ITCS_CIPHER_D_PARAM                 szOID_CPCSP_ENCR_D_PARAM_W

/// ��������� ��������� ���������� �� ���� 28147-89, ���������
/// ������������ � ����������� ���� � 34.10-2012 � ���� � 34.11-2012
/// � ������������ � ������������ �� ��������������
/// "������� ����� ������ ����� ����������� ��������� ����������
/// ���� 28147". ��������� ��� �� ��� ParamSet Z � ParamSet ISO.
/// �������� �������� BCRYPT_ITCS_CIPHER_OID.
#define BCRYPT_ITCS_CIPHER_ISO_GOST_28147          szOID_CSP2012_ENCRYPT_PARAM_W

// ==================================================================
// �������� �������� BCRYPT_ITCS_HASH_OID
// ==================================================================

/// �������� �������� BCRYPT_ITCS_SIGNATURE_OID.
/// ��������� ��������� ����������� ���� � 34.11-94. 
/// �����-� �����������, �������� �� ���������. 
#define BCRYPT_ITCS_HASH_DEF_PARAM                 szOID_CPCSP_HASH_DEF_PARAM_W

// ==================================================================
// �������� �������� BCRYPT_ITCS_SIGNATURE_OID
// ==================================================================

/// ��������� ��������� ������� �� ���� � 34.10-2001
/// A ParamSet, �������� �� ���������. RFC 4357.
/// �������� �������� BCRYPT_ITCS_SIGNATURE_OID.
#define BCRYPT_ITCS_SIGNATURE_256_DEF_PARAM            szOID_CPCSP_EL_SIGN_DEF_PARAM_W

/// ��������� ��������� ������� �� ���� � 34.10-2001
/// B ParamSet, �����-2x. RFC 4357.
/// �������� �������� BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_256_B_PARAM              szOID_CPCSP_EL_SIGN_1_PARAM_W

/// ��������� ��������� ������� �� ���� � 34.10-2001
/// C ParamSet. RFC 4357. 
/// �������� �������� BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_256_C_PARAM              szOID_CPCSP_EL_SIGN_2_PARAM_W

/// ��������� ��������� ������� �� ���� � 34.10-2012
/// A ParamSet �� � 50.1.114-2016. ���������� ������ ��������.
/// �������� �������� BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_2012_256_A_PARAM         szOID_CSP2012_SIGN_256_PARAM_A_W

/// ��������� ��������� ������� �� ���� � 34.10-2012
/// B ParamSet. �������� �� ������. 
/// �������� �������� BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_2012_256_B_PARAM         szOID_CSP2012_SIGN_256_PARAM_B_W

/// ��������� ��������� ������� �� ���� � 34.10-2012
/// C ParamSet. �������� �� ������. 
/// �������� �������� BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_2012_256_C_PARAM         szOID_CSP2012_SIGN_256_PARAM_C_W

/// ��������� ��������� ������� �� ���� � 34.10-2012
/// D ParamSet. �������� �� ������. 
/// �������� �������� BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_2012_256_D_PARAM         szOID_CSP2012_SIGN_256_PARAM_D_W

/// ��������� ��������� ������� �� ���� � 34.10-2012
/// A ParamSet �� � 50.1.114-2016.
/// �������� �������� BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_512_DEF_PARAM            szOID_CSP2012_SIGN_512_PARAM_A_W

/// ��������� ��������� ������� �� ���� � 34.10-2012
/// B ParamSet �� � 50.1.114-2016.
/// �������� �������� BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_512_B_PARAM              szOID_CSP2012_SIGN_512_PARAM_B_W

/// ��������� ��������� ������� �� ���� � 34.10-2012
/// C ParamSet �� � 50.1.114-2016.
/// �������� �������� BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_512_C_PARAM              szOID_CSP2012_SIGN_512_PARAM_C_W

/// ��������� ��������� exchange �� ���� � 34.10-2001
/// A ParamSet. RFC 4357.
/// �������� �������� BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_DH_256_DEF_PARAM                   szOID_CPCSP_EL_DH_DEF_PARAM_W

/// ��������� ��������� exchange �� ���� � 34.10-2001
/// B ParamSet. RFC 4357.
/// �������� �������� BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_DH_256_1_PARAM                     szOID_CPCSP_EL_DH_1_PARAM_W

// ==================================================================
// �������� �������� BCRYPT_ITCS_EXPORT_ID
// ==================================================================

/// ��������� �� ��, ��� ��� ��������/������� ����� ���� ������������
/// �������� �� RFC 4357  (�. 6.3).
/// �������� �������� BCRYPT_ITCS_EXPORT_ID
#define BCRYPT_ITCS_CRYPTO_PRO_EXPORT L"itcs-crypto-pro-export"

/// ��������� �� ��, ��� ��� ��������/������� ����� ���� ������������
/// �������� �� � 50.1.113-2016.
/// �������� �������� BCRYPT_ITCS_EXPORT_ID
#define BCRYPT_ITCS_CRYPTO_PRO12_EXPORT L"itcs-crypto-pro12-export" 

/// ��������� �� ��, ��� ��� ��������/������� ����� ���� ������������
/// �������� �� RFC 4357  (�. 6.1)
/// ����������� ��� �������� � ����������� ������.
/// �������� �������� BCRYPT_ITCS_EXPORT_ID
#define BCRYPT_ITCS_SIMPLE_EXPORT L"itcs-simple-export" 

#if defined( _WIN32 ) || ( defined( __unix__ ) && !defined ( __KERNEL__ ) )

/// ���������, ������������ ������������ ������� ������
/// ��� ������� ������� ������������� ���������� ��������� BCRYPT_ITCS_ENCRYPT_89_ALGID.
/// ��������� �� ��� �������� � �������� pPaddingInfo ������� BCryptEncrypt � BCryptDecrypt
/// (������� ������ ����������: BCRYPT_CHAIN_MODE_ECB � BCRYPT_CHAIN_MODE_CBC).
typedef struct __BCRYPT_ITCS_PADDING_INFO
{
     /// ������������� ��������
     /// ����� ��������� ���� �� ��������� ��������:
     /// -     BCRYPT_ITCS_PADDING_DEFAULT - ������� �� ��������� (��������� � BCRYPT_ITCS_PADDING_PKCS5_16 ���
     /// "���� � 34.12-2015 ��������" � � BCRYPT_ITCS_PADDING_PKCS5 ��� ���� ��������� ����������)
     /// -     BCRYPT_ITCS_PADDING_PKCS5 - PKCS5 �������
     /// -     BCRYPT_ITCS_PADDING_PKCS5_16 - PKCS5 ������� � ������ ����� 16 ����
     /// -     BCRYPT_ITCS_PADDING_ZERO - ������� ������
     /// -     BCRYPT_ITCS_PADDING_UEC - UEC �������
     /// -     BCRYPT_ITCS_PADDING_NO - ������� �� ������������.
     const wchar_t*   szPaddingType;
} BCRYPT_ITCS_PADDING_INFO, *PBCRYPT_ITCS_PADDING_INFO;

#endif

// ==================================================================
// �������� ������������ � szPaddingType BCRYPT_ITCS_PADDING_INFO
// ==================================================================

/// ������� �� ������������.
/// �������� ������������ � szPaddingType BCRYPT_ITCS_PADDING_INFO.
#define BCRYPT_ITCS_PADDING_NO                     L"itcs-no-padding"

/// ������� �� ��������� (��������� � BCRYPT_ITCS_PADDING_PKCS5).
/// �������� ������������ � szPaddingType BCRYPT_ITCS_PADDING_INFO.
#define BCRYPT_ITCS_PADDING_DEFAULT                L"itcs-default-padding"

/// PKCS5 �������.
/// �������� ������������ � szPaddingType BCRYPT_ITCS_PADDING_INFO.
#define BCRYPT_ITCS_PADDING_PKCS5                  L"itcs-PKCS5-padding"

/// PKCS5 ������� (������� � ������ ����� 16 ����).
/// �������� ������������ � szPaddingType BCRYPT_ITCS_PADDING_INFO.
#define BCRYPT_ITCS_PADDING_PKCS5_16                    L"itcs-PKCS5-16-padding"

/// ������� ������.
/// �������� ������������ � szPaddingType BCRYPT_ITCS_PADDING_INFO.
#define BCRYPT_ITCS_PADDING_ZERO                   L"itcs-zero-padding"

/// UEC �������.
/// �������� ������������ � szPaddingType BCRYPT_ITCS_PADDING_INFO.
#define BCRYPT_ITCS_PADDING_UEC                    L"itcs-UEC-padding"

// ==================================================================
// �������������� ���� KDF BufferTypes
// ==================================================================
#define KDF_GOST_UKM      0x80000001
#define KDF_GOST_CIPHER_OID                             0x80000002
#define KDF_GOST_CTR_SIZE                               0x80000003

// ����� ������ ����� ������ �� Win7
#ifndef KDF_LABEL
#define KDF_LABEL                                       0xD
#endif


//������������ � ������� BCryptDeriveKey � ����������, ��� ������� ������ ������ ��� ����,
//���������� �� ��������� ������������ ������.
//������ ��������� ���������� � bcrypt.h ������� � WSDK ������ 10 � ������ ��� Win8.1 � ������. 
#ifndef BCRYPT_KDF_RAW_SECRET
#define BCRYPT_KDF_RAW_SECRET               L"TRUNCATE"
#endif

#endif
