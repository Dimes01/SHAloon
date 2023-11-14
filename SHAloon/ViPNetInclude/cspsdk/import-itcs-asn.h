/// @file 
/// @brief Файл содержит объявления типов, необходимых для кодирования/декодирования расширений, реализованных в ViPNet CSP.
///
/// @copyright Copyright (c) InfoTeCS. All Rights Reserved.

#ifndef _IMPORT_ITCS_ASN_H_
#define _IMPORT_ITCS_ASN_H_

#include <windows.h>
#include <cspsdk/itcs-cades-defs.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/// Структура представляет расширение сертификата, представляющее период действия закрытого ключа, 
/// соответствующего сертификата.
/// Подробнее см. RFC 3280 Internet X.509 Public Key Infrastructure Certificate and Certificate Revocation List(CRL) Profile
/// 4.2.1.4  Private Key Usage Period
/// **** EDIT ****
typedef CERT_PRIVATE_KEY_VALIDITY PRIVATE_KEY_USAGE_PERIOD, *PPRIVATE_KEY_USAGE_PERIOD;

typedef const CERT_PRIVATE_KEY_VALIDITY *PCPRIVATE_KEY_USAGE_PERIOD;

// ==================================================================
// Pасширения ESS signing-certificate и ESS signing-certificate-v2 
// ==================================================================

#if defined(_WIN32)

/// Константа используется в функциях CryptEncodeObject(Ex)/CryptDecodeObject(Ex) в параметре lpszStructType.
/// Константа указывает, что параметр pvStructInfo является указателем на структуру типа ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR,
/// соответвует структуре id-aa-signingCertificate OBJECT IDENTIFIER ::= { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 12 }.
/// Подробнее см. RFC 2634 Enhanced Security Services for S/MIME и RFC 5126 CMS Advanced Electronic Signatures (CAdES) "5.7.3.1.  ESS signing-certificate Attribute Definition".
#  define ITCS_STRUCT_TYPE_ESS_SIGNING_CERTIFICATE_ATTR "{A010E44A-53E3-4e45-ACDB-272FF57EAA8C}"

/// Константа используется в функциях CryptEncodeObject(Ex)/CryptDecodeObject(Ex) в параметре lpszStructType.
/// Константа указывает, что параметр pvStructInfo является указателем на структуру типа ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2,
/// соответвует структуре id-aa-signingCertificateV2 OBJECT IDENTIFIER :: = { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 47 }
/// Подробнее см. RFC 5035 Enhanced Security Services (ESS) Update: Adding CertID Algorithm Agility "5.4.1.  Signing Certificate Attribute Definition Version 2".
#  define ITCS_STRUCT_TYPE_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2 "{B82662AD-F1FF-42c3-86EC-F9B532E6C4C2}"

#else

/// Константа используется в функциях CryptEncodeObject(Ex)/CryptDecodeObject(Ex) в параметре lpszStructType.
/// Константа указывает, что параметр pvStructInfo является указателем на структуру типа ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR,
/// соответвует структуре id-aa-signingCertificate OBJECT IDENTIFIER ::= { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 12 }.
/// Подробнее см. RFC 2634 Enhanced Security Services for S/MIME и RFC 5126 CMS Advanced Electronic Signatures (CAdES) "5.7.3.1.  ESS signing-certificate Attribute Definition".
#  define ITCS_STRUCT_TYPE_ESS_SIGNING_CERTIFICATE_ATTR szOID_ITCS_ESS_SIGNING_CERTIFICATE_ATTR

/// Константа используется в функциях CryptEncodeObject(Ex)/CryptDecodeObject(Ex) в параметре lpszStructType.
/// Константа указывает, что параметр pvStructInfo является указателем на структуру типа ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2,
/// соответвует структуре id-aa-signingCertificateV2 OBJECT IDENTIFIER :: = { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 47 }
/// Подробнее см. RFC 5035 Enhanced Security Services (ESS) Update: Adding CertID Algorithm Agility "5.4.1.  Signing Certificate Attribute Definition Version 2".
#  define ITCS_STRUCT_TYPE_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2 szOID_ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2

#endif

/// Структура представляет идентификатор сертификата, 
/// соответствующая структуре ESSCertID (см. RFC 2634 Enhanced Security Services for S/MIME "5.4.1 Certificate Identification").
typedef struct _ITCS_ESS_CERTIFICATE_ID
{
     ///Значение хэш-функции от сертификата
     CRYPT_DER_BLOB      Hash;
     ///Информация об издателе сертификата
     CERT_ALT_NAME_INFO  Issuer;
     ///Серийный номер сертификата
     CRYPT_INTEGER_BLOB  SerialNumber;
}ITCS_ESS_CERTIFICATE_ID, *PITCS_ESS_CERTIFICATE_ID;

/// Структура представляет массив структур типа ITCS_ESS_CERTIFICATE_ID.
typedef struct _ITCS_ESS_CERTIFICATE_IDS
{
     /// Число элементов в массиве
     DWORD cCertId;
#ifdef _WIN32
     __field_ecount(cCertId)
#endif
     /// Указатель на массив структур
     PITCS_ESS_CERTIFICATE_ID rgCertId;
} ITCS_ESS_CERTIFICATE_IDS, *PITCS_ESS_CERTIFICATE_IDS;

/// Структура представляет декодированную ASN структуру 
/// id-aa-signingCertificate OBJECT IDENTIFIER ::= { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 12 }.
/// Подробнее см. RFC 2634 Enhanced Security Services for S/MIME и RFC 5126 CMS Advanced Electronic Signatures (CAdES) "5.7.3.1.  ESS signing-certificate Attribute Definition".
/// В функциях CryptEncodeObject(Ex)/CryptDecodeObject(Ex) задаётся идентификатором ITCS_STRUCT_TYPE_ESS_SIGNING_CERTIFICATE_ATTR.
typedef struct _ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR
{
     /// Массив струтур, представляющих идентифкаторы сертификата
     ITCS_ESS_CERTIFICATE_IDS CertIds;
     /// Массив структур типа CERT_POLICY_INFO.
     /// (структура CERT_POLICY_INFO содержит идентификатор полититики и необязательный массив спецификаторов политик).
     CERT_POLICIES_INFO PoliciesInfo;
} ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR, *PITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR;

/// Структура представляет идентификатор сертификата версии 2, 
/// соответствующей структуре ESSCertID2
/// (см. RFC 5035 Enhanced Security Services (ESS) Update: Adding CertID Algorithm Agility "5.4.1.1 Certificate Identification Version 2").
typedef struct _ITCS_ESS_CERTIFICATE_ID_V2
{
     /// Алгоритм хеширования
     CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
     /// Значение хэш-функции
     CRYPT_DER_BLOB             Hash;
     /// Издатель сертификата.
     CERT_ALT_NAME_INFO         Issuer;
     /// Серийный номер сертификата.
     CRYPT_INTEGER_BLOB         SerialNumber;
} ITCS_ESS_CERTIFICATE_ID_V2, *PITCS_ESS_CERTIFICATE_ID_V2;

/// Структура представляет массив структур типа ITCS_ESS_CERTIFICATE_ID_V2
typedef struct _ITCS_ESS_CERTIFICATE_IDS_V2
{
     /// Число элементов в массиве
     DWORD cCertId;
#ifdef _WIN32
     __field_ecount(cCertId)
#endif
     /// Указатель на массив структур
     PITCS_ESS_CERTIFICATE_ID_V2 rgCertId;
} ITCS_ESS_CERTIFICATE_IDS_V2, *PITCS_ESS_CERTIFICATE_IDS_V2;

/// Структура представляет декодированную ASN структуру 
/// id-aa-signingCertificateV2 OBJECT IDENTIFIER :: = { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 47 }
/// Подробнее см. RFC 5035 Enhanced Security Services (ESS) Update: Adding CertID Algorithm Agility "5.4.1.  Signing Certificate Attribute Definition Version 2".
/// В функциях CryptEncodeObject(Ex)/CryptDecodeObject(Ex) задается идентификатором ITCS_STRUCT_TYPE_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2.
typedef struct _ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2
{
     /// Массив струтур представляющих идентифкаторы сертификата версии 2
     ITCS_ESS_CERTIFICATE_IDS_V2 CertIds;
     /// Массив структур типа CERT_POLICY_INFO
     /// (Структура CERT_POLICY_INFO содержит идентификатор полититики и опциональный массив спецификаторов политик).
     CERT_POLICIES_INFO PoliciesInfo;
} ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2, *PITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _IMPORT_ITCS_ASN_H_
