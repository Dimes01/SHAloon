/// @file 
/// @brief ViPNet специфика криптографических интерфейсов CNG
///
/// @copyright Copyright (c) InfoTeCS. All Rights Reserved.

#ifndef _ITC_IMPORT_ITCS_BCRYPT_H_
#define _ITC_IMPORT_ITCS_BCRYPT_H_

#include <cspsdk/import-itcs-crypt-base.h>

/// Идентификатор ViPNet CNG BCRYPT провайдера, предоставляющего ГОСТ алгоритмы
#define VPN_CNG_PROVIDER_CU_NAME                          L"Infotecs Primitive Provider CU"
/// Идентификатор ViPNet CNG BCRYPT провайдера, предоставляющего ГОСТ алгоритмы, ANSI версия
#define VPN_CNG_PROVIDER_CU_NAME_A                        "Infotecs Primitive Provider CU"

/// Идентификатор BCRYPT провайдера, предоставляющего ГОСТ алгоритмы
#define ITCS_BCRYPT_PROVIDER_NAME                         L"Infotecs Bcrypt Provider"
/// Идентификатор BCRYPT провайдера, предоставляющего ГОСТ алгоритмы, ANSI версия
#define ITCS_BCRYPT_PROVIDER_NAME_A                       "Infotecs Bcrypt Provider"

/// Имя провайдера хранения ключей. Unicode версия.
/// Экспериментальное имя и может быть удалено в следующих версиях.
#define VPN_KEYSTORAGE_PROVIDER_NAME_W                    L"Infotecs Software Key Storage Provider"
/// Имя провайдера хранения ключей. Ascii версия.
/// Экспериментальное имя и может быть удалено в следующих версиях.
#define VPN_KEYSTORAGE_PROVIDER_NAME_A                    "Infotecs Software Key Storage Provider"

/// Идентификатор ViPNet CNG BCRYPT провайдера, предоставляющего ДСЧ, Unicode версия
#define VPN_CNG_PROVIDER_RNG_W L"Infotecs UPRNG"
/// Идентификатор ViPNet CNG BCRYPT провайдера, предоставляющего ДСЧ, Ascii версия
#define VPN_CNG_PROVIDER_RNG_A  "Infotecs UPRNG"

// ==================================================================
// Идентификаторы алгоритмов
// ==================================================================

/// Идентификатор алгоритма хеширования ГОСТ Р 34.11-94. RFC 4357. 
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_HASH_94_ALGID                      L"GOST R 34.11-94"

/// Идентификатор алгоритма хеширования ГОСТ Р 34.11-2012 с длиной выхода 256 бит. 
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_HASH_2012_256_ALGID                L"GR 34.11-2012 256"

/// Идентификатор алгоритма хеширования ГОСТ Р 34.11-2012 с длиной выхода 512 бит.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_HASH_2012_512_ALGID                L"GR 34.11-2012 512"

/// Идентификатор алгоритма шифрования ГОСТ 28147-89. RFC 4357. 
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_ENCRYPT_89_ALGID                   L"GOST 28147-89" 

/// Идентификатор алгоритма для выработки ключа для экспорта ключа ГОСТ 28147-89.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_89_EXPORT_KEY_HOLDER_ALGID          L"GOST 28147-89 EXPORT KEY HOLDER"

/// Идентификатор алгоритма вычисления MAC. RFC 4357. ГОСТ 28147-89.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_MAC_89_ALGID                       L"GOST 28147-89 MAC"

/// Идентификатор алгоритма шифрования ГОСТ Р 34.12-2015 Магма.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_ENCRYPT_MAGMA_ALGID                 L"GOST R 34.12-2015 MAGMA"

/// Идентификатор алгоритма шифрования по ГОСТ Р 34.12-2015 Магма в режиме CTR с предварительной выработкой имитовставки
/// по ГОСТ Р 34.13-2015, OMAC1 при использовании шифра Магма. Алгоритм описан в документе по протоколу CMS.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_CMS_ENCRYPT_MAGMA_ALGID            L"MAGMA CMS ENCRYPT"

/// Идентификатор алгоритма для выработки ключа для экспорта ключа Магма по рекомендациям Р 1323565.1.017-2018 (KExp15).
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_MAGMA_EXPORT_KEY_HOLDER_ALGID       L"MAGMA EXPORT KEY HOLDER"

/// Идентификатор алгоритма выработки имитовставки по ГОСТ Р 34.13-2015, OMAC1 при использовании шифра Магма.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_MAC_MAGMA_ALGID                     L"GOST R 34.12-2015 MAGMA MAC"

/// Идентификатор алгоритма шифрования ГОСТ Р 34.12-2015 Кузнечик.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_ENCRYPT_KUZNYECHIK_ALGID            L"GOST R 34.12-2015 KUZNYECHIK" 

/// Идентификатор алгоритма шифрования по ГОСТ Р 34.12-2015 Кузнечик в режиме CTR с предварительной выработкой
/// имитовставки по ГОСТ Р 34.13-2015, OMAC1 при использовании шифра Кузнечик. Алгоритм описан в документе по протоколу CMS.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_CMS_ENCRYPT_KUZNYECHIK_ALGID       L"KUZNYECHIK CMS ENCRYPT"

/// Идентификатор алгоритма для выработки ключа для экспорта ключа Кузнечик по рекомендациям Р 1323565.1.017-2018 (KExp15).
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_KUZNYECHIK_EXPORT_KEY_HOLDER_ALGID  L"KUZNYECHIK EXPORT KEY HOLDER"

/// Идентификатор алгоритма выработки имитовставки по ГОСТ Р 34.13-2015, OMAC1 при использовании шифра Кузнечик.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_MAC_KUZNYECHIK_ALGID                L"GOST R 34.12-2015 KUZNYECHIK MAC"

/// Идентификатор алгоритма подписи ГОСТ Р 34.10-2001. RFC 4357. 
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_SIGN_2001_ALGID                    L"GOST R 34.10-2001"

/// Идентификатор алгоритма согласование ключей ГОСТ Р 34.10-2001. RFC 4357. 
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_DH_2001_ALGID                    L"DH 34.10-2001"

/// Идентификатор алгоритма подписи ГОСТ Р 34.10-2012 с длиной ключа 256 бит.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_SIGN_2012_256_ALGID                L"GR 34.10-2012 256"

/// Идентификатор алгоритма согласования ключей ГОСТ Р 34.10-2012 с длиной ключа 256 бит.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_DH_2012_256_ALGID                L"DH 34.10-2012 256"

/// Идентификатор алгоритма подписи ГОСТ Р 34.10-2012 с длиной ключа 512 бит.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_SIGN_2012_512_ALGID                L"GR 34.10-2012 512"

/// Идентификатор алгоритма согласования ключей ГОСТ Р 34.10-2012 с длиной ключа 512 бит.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_DH_2012_512_ALGID                L"DH 34.10-2012 512"

/// Идентификатор алгоритма генератора псевдо случайной последовательности, использующего генератор IV.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_RNG_ALGID                          L"ITCS-RNG-ALGORITHM"

/// Идентификатор алгоритма генератора псевдо случайной последовательности, использующего генератор сессионных ключей.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_KEY_RNG_ALGID                       L"ITCS-KEY-RNG-ALGORITHM"

/// Идентификатор алгоритма генератора псевдо случайной последовательности, использующего генератор масок.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_MASK_RNG_ALGID                      L"ITCS-MASK-RNG-ALGORITHM"

/// Идентификатор алгоритма генератора псевдо случайной последовательности, для генерации долговременных ключей.
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_ITCS_ADVANCED_RNG_ALGID                  L"ITCS-ADVANCED-RNG-ALGORITHM"

/// Идентификатор алгоритма ГОСТ TLS PRF
/// Используется в функции BCryptOpenAlgorithmProvider
#define BCRYPT_GOST_TLS_PRF_ALG_ID                     L"GOST-TLS-PRF"

/// Идентификатор алгоритма KDF диверсификации ключа по RFC 4357
/// Используется в функции BCryptDeriveKey
#define BCRYPT_KDF_RFC_4357                            L"KDF_RFC_4357"

/// Идентификатор алгоритма KDF диверсификации ключа по ГОСТ Р 50.1.113
/// Используется в функции BCryptDeriveKey
#define BCRYPT_KDF_GOSTR3411_2012_256                  L"KDF_GOSTR3411_2012_256"

/// Идентификатор алгоритма KDF диверсификации ключа по NIST SP 800-108 с HMAC в качестве PRF в режиме счетчика
/// Этот алгоритм превращается KDF_GOSTR3411_2012_256, если прив параметрах вызова DeriveKey не задавать алгоритм
/// хеширования (KDF_HASH_ALGORITHM) и размер поля счетчика (KDF_GOST_CTR_SIZE). Если не задавать только алгоритм
/// хеширования (KDF_HASH_ALGORITHM), а размер поля счетчика (KDF_GOST_CTR_SIZE) задать, то получим
/// KDF_TREE_GOSTR3411_2012_256
/// Используется в функции BCryptDeriveKey
/// Можно убрать после отказа от Win7, т.к. это стандартный идентификатор начиная с win8
#ifndef BCRYPT_SP800108_CTR_HMAC_ALGORITHM
#define BCRYPT_SP800108_CTR_HMAC_ALGORITHM              L"SP800_108_CTR_HMAC"
#endif

// ==================================================================
// Дополнительные типы блобов, используемые в функциях BCryptImportKey и BCryptExportKey 
// ==================================================================

/// Тип блоба для сериализации симметричного ГОСТ-ключа.
/// Используется в функциях BCryptImportKey и BCryptExportKey 
#define BCRYPT_ITCS_SIMPLE_KEY_BLOB                     L"ItcsBcryptSimpleKeyBlob"

/// Тип блоба совпадающего с форматом SIMPLEBLOB из CSP для ГОСТ алгоритмов.
/// Используется в функциях BCryptImportKey и BCryptExportKey 
#define LEGACY_GOST_SIMPLE_KEY_BLOB                    L"CAPIGostSimpleBlob"

/// Тип блоба совпадающего с форматом PUBLICKEYBLOB из CSP для ГОСТ алгоритмов.
/// Используется в функциях BCryptImportKey и BCryptExportKey 
#define LEGACY_GOST_PUBLIC_KEY_BLOB                    L"CAPIGostPublicKeyBlob"

/// Тип блоба совпадающего с форматом PRIVATEKEYBLOB из CSP для ГОСТ алгоритмов.
/// Используется в функциях BCryptImportKey и BCryptExportKey 
#define LEGACY_GOST_PRIVATE_KEY_BLOB                    L"CAPIGostPrivateKeyBlob"

#define BCRYPT_ITCS_SIMPLE_KEY_BLOB_MAGIC               0x534b424d  // SKBM
#define BCRYPT_ITCS_WRAPPED_KEY_BLOB_MAGIC              0x574b424d  // WKBM

// ==================================================================
// Magics для BCRYPT_PUBLIC_KEY_BLOB ГОСТ алгоритмов 
// ==================================================================

//"G01_"
#define GOST_2001_PUBLIC_KEY_BLOB_MAGIC 0x5F313047

//"G12S"
#define GOST_12_256_PUBLIC_KEY_BLOB_MAGIC 0x53323147

//"G12L"
#define GOST_12_512_PUBLIC_KEY_BLOB_MAGIC 0x4C323147

// ==================================================================
// Дополнительные имена свойтв используемых в функциях BCryptGetProperty и BCryptSetProperty
// ==================================================================

/// OID - идентификатор параметров хэширования.
/// Используется в функциях BCryptGetProperty и BCryptSetProperty
#define BCRYPT_ITCS_HASH_OID                       L"itcs-hash-oid"

/// OID - идентификатор параметров электронной подписи.
/// Используется в функциях BCryptGetProperty и BCryptSetProperty
#define BCRYPT_ITCS_SIGNATURE_OID                  L"itcs-signature-oid"

/// Параметры открытого ключа для алгоритмов электронной подписи.
/// Используется в функциях BCryptGetProperty и BCryptSetProperty
#define BCRYPT_ITCS_PUBLIC_KEY_PARAMETERS               L"itcs-publickey-parameters"

/// OID - идентификатор параметров шифрования.
/// Используется в функциях BCryptGetProperty и BCryptSetProperty
#define BCRYPT_ITCS_CIPHER_OID                     L"itcs-cipher-oid"

/// Признак того, что необходимо использования мешинга ключа.
/// Используется в функциях BCryptGetProperty и BCryptSetProperty 
#define BCRYPT_ITCS_USE_MECHING_PERIOD             L"itcs-use-meshing-period"

/// Период мешинга ключа.
/// Используется в функциях BCryptGetProperty и BCryptSetProperty 
#define BCRYPT_ITCS_MESHING_PERIOD                      L"itcs-meshing-period"

/// Значение закрытого ключа.
/// Используется в функции BCryptSetProperty 
#define BCRYPT_ITCS_PRIVATE_KEY_VALUE              L"itcs-private-key-value" 

/// Cериализованное состояние объекта хэширования.
/// Используется в функциях BCryptGetProperty и BCryptSetProperty 
#define BCRYPT_ITCS_HASH_STATE                     L"itcs-hash-state" //Состояние хэша

///Идентификатор экспорта симметричного ключа.
///Выставляется у ключа защиты(параметр hImportKey в функции BCryptImportKey и параметр hExportKey в функции BCryptExportKey), 
///на котором происходит экспорт / импорт другого симметричного ключа.
#define BCRYPT_ITCS_EXPORT_ID                      L"itcs-export-id"

/// Параметр алгоритм-провайдера - регламентный контроль ДСЧ.
#define BCRYPT_ITCS_RNG_REGLAMENT_CTRL            L"itcs-rng-reglament-ctrl"

/// UKM для VKO.
/// Используется в функции BCryptSetProperty 
#define BCRYPT_ITCS_VKO_UKM                             L"itcs-vko-ukm"


// ==================================================================
// Дополнительные значения свойства BCRYPT_CHAINING_MODE
// ==================================================================
/// Режим счетчика для алгоритма шифрования ГОСТ 28147-89
/// (для алгоритма шифрования ГОСТ 28147-89 соответствует режиму CRYPT_MODE_OFB в CSP).
#define BCRYPT_CHAIN_MODE_GOST89_CNT    L"ChainingModeGost89CNT"

/// Режим гаммирования по ГОСТ Р 34.13-2015, CTR.
#define BCRYPT_CHAIN_MODE_GOST_34_13_2015_CTR           L"ChainingModeGost34_13_2015_CTR"

// ==================================================================
// Значения свойства BCRYPT_ITCS_CIPHER_OID
// ==================================================================

/// Параметры алгоритма шифрования по ГОСТ 28147-89
/// A ParamSet. RFC 4357.
/// Значения свойства BCRYPT_ITCS_CIPHER_OID.
#define BCRYPT_ITCS_CIPHER_A_PARAM                 szOID_CPCSP_ENCR_DEF_PARAM_W

/// Параметры алгоритма шифрования по ГОСТ 28147-89 по умолчанию.
/// Значения свойства BCRYPT_ITCS_CIPHER_OID.
#define BCRYPT_ITCS_CIPHER_DEF_PARAM               BCRYPT_ITCS_CIPHER_A_PARAM

/// Параметры алгоритма шифрования по ГОСТ 28147-89
/// B ParamSet. RFC 4357.
/// Значения свойства BCRYPT_ITCS_CIPHER_OID.
#define BCRYPT_ITCS_CIPHER_B_PARAM                 szOID_CPCSP_ENCR_B_PARAM_W

/// Параметры алгоритма шифрования по ГОСТ 28147-89
/// С ParamSet. RFC 4357.
/// Значения свойства BCRYPT_ITCS_CIPHER_OID.
#define BCRYPT_ITCS_CIPHER_C_PARAM                 szOID_CPCSP_ENCR_C_PARAM_W

/// Параметры алгоритма шифрования по ГОСТ 28147-89
/// В ParamSet. RFC 4357.
/// Значения свойства BCRYPT_ITCS_CIPHER_OID.
#define BCRYPT_ITCS_CIPHER_D_PARAM                 szOID_CPCSP_ENCR_D_PARAM_W

/// Параметры алгоритма шифрования по ГОСТ 28147-89, введенные
/// одновременно с алгоритмами ГОСТ Р 34.10-2012 и ГОСТ Р 34.11-2012
/// в соответствии с Рекомендации по стандартизации
/// "Задание узлов замены блока подстановки алгоритма шифрования
/// ГОСТ 28147". Известный так же как ParamSet Z и ParamSet ISO.
/// Значения свойства BCRYPT_ITCS_CIPHER_OID.
#define BCRYPT_ITCS_CIPHER_ISO_GOST_28147          szOID_CSP2012_ENCRYPT_PARAM_W

// ==================================================================
// Значения свойства BCRYPT_ITCS_HASH_OID
// ==================================================================

/// Значение свойства BCRYPT_ITCS_SIGNATURE_OID.
/// Параметры алгоритма хеширования ГОСТ Р 34.11-94. 
/// Верба-О хеширования, значение по умолчанию. 
#define BCRYPT_ITCS_HASH_DEF_PARAM                 szOID_CPCSP_HASH_DEF_PARAM_W

// ==================================================================
// Значения свойства BCRYPT_ITCS_SIGNATURE_OID
// ==================================================================

/// Параметры алгоритма подписи по ГОСТ Р 34.10-2001
/// A ParamSet, значение по умолчанию. RFC 4357.
/// Значение свойства BCRYPT_ITCS_SIGNATURE_OID.
#define BCRYPT_ITCS_SIGNATURE_256_DEF_PARAM            szOID_CPCSP_EL_SIGN_DEF_PARAM_W

/// Параметры алгоритма подписи по ГОСТ Р 34.10-2001
/// B ParamSet, Оскар-2x. RFC 4357.
/// Значение свойства BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_256_B_PARAM              szOID_CPCSP_EL_SIGN_1_PARAM_W

/// Параметры алгоритма подписи по ГОСТ Р 34.10-2001
/// C ParamSet. RFC 4357. 
/// Значение свойства BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_256_C_PARAM              szOID_CPCSP_EL_SIGN_2_PARAM_W

/// Параметры алгоритма подписи по ГОСТ Р 34.10-2012
/// A ParamSet по Р 50.1.114-2016. Скрученные кривые Эдвардса.
/// Значение свойства BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_2012_256_A_PARAM         szOID_CSP2012_SIGN_256_PARAM_A_W

/// Параметры алгоритма подписи по ГОСТ Р 34.10-2012
/// B ParamSet. Документ не принят. 
/// Значение свойства BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_2012_256_B_PARAM         szOID_CSP2012_SIGN_256_PARAM_B_W

/// Параметры алгоритма подписи по ГОСТ Р 34.10-2012
/// C ParamSet. Документ не принят. 
/// Значение свойства BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_2012_256_C_PARAM         szOID_CSP2012_SIGN_256_PARAM_C_W

/// Параметры алгоритма подписи по ГОСТ Р 34.10-2012
/// D ParamSet. Документ не принят. 
/// Значение свойства BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_2012_256_D_PARAM         szOID_CSP2012_SIGN_256_PARAM_D_W

/// Параметры алгоритма подписи по ГОСТ Р 34.10-2012
/// A ParamSet по Р 50.1.114-2016.
/// Значение свойства BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_512_DEF_PARAM            szOID_CSP2012_SIGN_512_PARAM_A_W

/// Параметры алгоритма подписи по ГОСТ Р 34.10-2012
/// B ParamSet по Р 50.1.114-2016.
/// Значение свойства BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_512_B_PARAM              szOID_CSP2012_SIGN_512_PARAM_B_W

/// Параметры алгоритма подписи по ГОСТ Р 34.10-2012
/// C ParamSet по Р 50.1.114-2016.
/// Значение свойства BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_SIGNATURE_512_C_PARAM              szOID_CSP2012_SIGN_512_PARAM_C_W

/// Параметры алгоритма exchange по ГОСТ Р 34.10-2001
/// A ParamSet. RFC 4357.
/// Значение свойства BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_DH_256_DEF_PARAM                   szOID_CPCSP_EL_DH_DEF_PARAM_W

/// Параметры алгоритма exchange по ГОСТ Р 34.10-2001
/// B ParamSet. RFC 4357.
/// Значение свойства BCRYPT_ITCS_SIGNATURE_OID
#define BCRYPT_ITCS_DH_256_1_PARAM                     szOID_CPCSP_EL_DH_1_PARAM_W

// ==================================================================
// Значения свойства BCRYPT_ITCS_EXPORT_ID
// ==================================================================

/// Указывает на то, что при экспорте/импорте ключа надо использовать
/// алгоритм по RFC 4357  (п. 6.3).
/// Значения свойства BCRYPT_ITCS_EXPORT_ID
#define BCRYPT_ITCS_CRYPTO_PRO_EXPORT L"itcs-crypto-pro-export"

/// Указывает на то, что при экспорте/импорте ключа надо использовать
/// алгоритм по Р 50.1.113-2016.
/// Значения свойства BCRYPT_ITCS_EXPORT_ID
#define BCRYPT_ITCS_CRYPTO_PRO12_EXPORT L"itcs-crypto-pro12-export" 

/// Указывает на то, что при экспорте/импорте ключа надо использовать
/// алгоритм по RFC 4357  (п. 6.1)
/// применяется для хранения и конвертации ключей.
/// Значения свойства BCRYPT_ITCS_EXPORT_ID
#define BCRYPT_ITCS_SIMPLE_EXPORT L"itcs-simple-export" 

#if defined( _WIN32 ) || ( defined( __unix__ ) && !defined ( __KERNEL__ ) )

/// Структура, определяющая используемый паддинг данных
/// для блочных режимов симметричного шифрования алгоритма BCRYPT_ITCS_ENCRYPT_89_ALGID.
/// Указатель на нее задается в парамтре pPaddingInfo функций BCryptEncrypt и BCryptDecrypt
/// (блочные режимы шифрования: BCRYPT_CHAIN_MODE_ECB и BCRYPT_CHAIN_MODE_CBC).
typedef struct __BCRYPT_ITCS_PADDING_INFO
{
     /// Идентификатор паддинга
     /// Может принимать одно из следующих значений:
     /// -     BCRYPT_ITCS_PADDING_DEFAULT - паддинг по умолчанию (совпадает с BCRYPT_ITCS_PADDING_PKCS5_16 для
     /// "ГОСТ Р 34.12-2015 Кузнечик" и с BCRYPT_ITCS_PADDING_PKCS5 для всех остальных алгоритмов)
     /// -     BCRYPT_ITCS_PADDING_PKCS5 - PKCS5 паддинг
     /// -     BCRYPT_ITCS_PADDING_PKCS5_16 - PKCS5 паддинг с длиной блока 16 байт
     /// -     BCRYPT_ITCS_PADDING_ZERO - паддинг нулями
     /// -     BCRYPT_ITCS_PADDING_UEC - UEC паддинг
     /// -     BCRYPT_ITCS_PADDING_NO - паддинг не используется.
     const wchar_t*   szPaddingType;
} BCRYPT_ITCS_PADDING_INFO, *PBCRYPT_ITCS_PADDING_INFO;

#endif

// ==================================================================
// Значения выставляемые в szPaddingType BCRYPT_ITCS_PADDING_INFO
// ==================================================================

/// Паддинг не используется.
/// Значение выставляемые в szPaddingType BCRYPT_ITCS_PADDING_INFO.
#define BCRYPT_ITCS_PADDING_NO                     L"itcs-no-padding"

/// Паддинг по умолчанию (совпадает с BCRYPT_ITCS_PADDING_PKCS5).
/// Значение выставляемые в szPaddingType BCRYPT_ITCS_PADDING_INFO.
#define BCRYPT_ITCS_PADDING_DEFAULT                L"itcs-default-padding"

/// PKCS5 паддинг.
/// Значение выставляемые в szPaddingType BCRYPT_ITCS_PADDING_INFO.
#define BCRYPT_ITCS_PADDING_PKCS5                  L"itcs-PKCS5-padding"

/// PKCS5 паддинг (вариант с блоком длины 16 байт).
/// Значение выставляемые в szPaddingType BCRYPT_ITCS_PADDING_INFO.
#define BCRYPT_ITCS_PADDING_PKCS5_16                    L"itcs-PKCS5-16-padding"

/// Паддинг нулями.
/// Значение выставляемые в szPaddingType BCRYPT_ITCS_PADDING_INFO.
#define BCRYPT_ITCS_PADDING_ZERO                   L"itcs-zero-padding"

/// UEC паддинг.
/// Значение выставляемые в szPaddingType BCRYPT_ITCS_PADDING_INFO.
#define BCRYPT_ITCS_PADDING_UEC                    L"itcs-UEC-padding"

// ==================================================================
// Дополнительные типы KDF BufferTypes
// ==================================================================
#define KDF_GOST_UKM      0x80000001
#define KDF_GOST_CIPHER_OID                             0x80000002
#define KDF_GOST_CTR_SIZE                               0x80000003

// можно убрать после отказа от Win7
#ifndef KDF_LABEL
#define KDF_LABEL                                       0xD
#endif


//Используется в функции BCryptDeriveKey и определяет, что функция должна выдать сам ключ,
//полученный из алгоритма согласования ключей.
//Данная константа определана в bcrypt.h начиная с WSDK версии 10 и только для Win8.1 и старше. 
#ifndef BCRYPT_KDF_RAW_SECRET
#define BCRYPT_KDF_RAW_SECRET               L"TRUNCATE"
#endif

#endif
