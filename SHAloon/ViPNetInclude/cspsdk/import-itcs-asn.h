/// @file 
/// @brief ���� �������� ���������� �����, ����������� ��� �����������/������������� ����������, ������������� � ViPNet CSP.
///
/// @copyright Copyright (c) InfoTeCS. All Rights Reserved.

#ifndef _IMPORT_ITCS_ASN_H_
#define _IMPORT_ITCS_ASN_H_

#include <windows.h>
#include <cspsdk/itcs-cades-defs.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/// ��������� ������������ ���������� �����������, �������������� ������ �������� ��������� �����, 
/// ���������������� �����������.
/// ��������� ��. RFC 3280 Internet X.509 Public Key Infrastructure Certificate and Certificate Revocation List(CRL) Profile
/// 4.2.1.4  Private Key Usage Period
/// **** EDIT ****
typedef CERT_PRIVATE_KEY_VALIDITY PRIVATE_KEY_USAGE_PERIOD, *PPRIVATE_KEY_USAGE_PERIOD;

typedef const CERT_PRIVATE_KEY_VALIDITY *PCPRIVATE_KEY_USAGE_PERIOD;

// ==================================================================
// P��������� ESS signing-certificate � ESS signing-certificate-v2 
// ==================================================================

#if defined(_WIN32)

/// ��������� ������������ � �������� CryptEncodeObject(Ex)/CryptDecodeObject(Ex) � ��������� lpszStructType.
/// ��������� ���������, ��� �������� pvStructInfo �������� ���������� �� ��������� ���� ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR,
/// ����������� ��������� id-aa-signingCertificate OBJECT IDENTIFIER ::= { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 12 }.
/// ��������� ��. RFC 2634 Enhanced Security Services for S/MIME � RFC 5126 CMS Advanced Electronic Signatures (CAdES) "5.7.3.1.  ESS signing-certificate Attribute Definition".
#  define ITCS_STRUCT_TYPE_ESS_SIGNING_CERTIFICATE_ATTR "{A010E44A-53E3-4e45-ACDB-272FF57EAA8C}"

/// ��������� ������������ � �������� CryptEncodeObject(Ex)/CryptDecodeObject(Ex) � ��������� lpszStructType.
/// ��������� ���������, ��� �������� pvStructInfo �������� ���������� �� ��������� ���� ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2,
/// ����������� ��������� id-aa-signingCertificateV2 OBJECT IDENTIFIER :: = { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 47 }
/// ��������� ��. RFC 5035 Enhanced Security Services (ESS) Update: Adding CertID Algorithm Agility "5.4.1.  Signing Certificate Attribute Definition Version 2".
#  define ITCS_STRUCT_TYPE_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2 "{B82662AD-F1FF-42c3-86EC-F9B532E6C4C2}"

#else

/// ��������� ������������ � �������� CryptEncodeObject(Ex)/CryptDecodeObject(Ex) � ��������� lpszStructType.
/// ��������� ���������, ��� �������� pvStructInfo �������� ���������� �� ��������� ���� ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR,
/// ����������� ��������� id-aa-signingCertificate OBJECT IDENTIFIER ::= { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 12 }.
/// ��������� ��. RFC 2634 Enhanced Security Services for S/MIME � RFC 5126 CMS Advanced Electronic Signatures (CAdES) "5.7.3.1.  ESS signing-certificate Attribute Definition".
#  define ITCS_STRUCT_TYPE_ESS_SIGNING_CERTIFICATE_ATTR szOID_ITCS_ESS_SIGNING_CERTIFICATE_ATTR

/// ��������� ������������ � �������� CryptEncodeObject(Ex)/CryptDecodeObject(Ex) � ��������� lpszStructType.
/// ��������� ���������, ��� �������� pvStructInfo �������� ���������� �� ��������� ���� ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2,
/// ����������� ��������� id-aa-signingCertificateV2 OBJECT IDENTIFIER :: = { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 47 }
/// ��������� ��. RFC 5035 Enhanced Security Services (ESS) Update: Adding CertID Algorithm Agility "5.4.1.  Signing Certificate Attribute Definition Version 2".
#  define ITCS_STRUCT_TYPE_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2 szOID_ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2

#endif

/// ��������� ������������ ������������� �����������, 
/// ��������������� ��������� ESSCertID (��. RFC 2634 Enhanced Security Services for S/MIME "5.4.1 Certificate Identification").
typedef struct _ITCS_ESS_CERTIFICATE_ID
{
     ///�������� ���-������� �� �����������
     CRYPT_DER_BLOB      Hash;
     ///���������� �� �������� �����������
     CERT_ALT_NAME_INFO  Issuer;
     ///�������� ����� �����������
     CRYPT_INTEGER_BLOB  SerialNumber;
}ITCS_ESS_CERTIFICATE_ID, *PITCS_ESS_CERTIFICATE_ID;

/// ��������� ������������ ������ �������� ���� ITCS_ESS_CERTIFICATE_ID.
typedef struct _ITCS_ESS_CERTIFICATE_IDS
{
     /// ����� ��������� � �������
     DWORD cCertId;
#ifdef _WIN32
     __field_ecount(cCertId)
#endif
     /// ��������� �� ������ ��������
     PITCS_ESS_CERTIFICATE_ID rgCertId;
} ITCS_ESS_CERTIFICATE_IDS, *PITCS_ESS_CERTIFICATE_IDS;

/// ��������� ������������ �������������� ASN ��������� 
/// id-aa-signingCertificate OBJECT IDENTIFIER ::= { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 12 }.
/// ��������� ��. RFC 2634 Enhanced Security Services for S/MIME � RFC 5126 CMS Advanced Electronic Signatures (CAdES) "5.7.3.1.  ESS signing-certificate Attribute Definition".
/// � �������� CryptEncodeObject(Ex)/CryptDecodeObject(Ex) ������� ��������������� ITCS_STRUCT_TYPE_ESS_SIGNING_CERTIFICATE_ATTR.
typedef struct _ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR
{
     /// ������ �������, �������������� ������������� �����������
     ITCS_ESS_CERTIFICATE_IDS CertIds;
     /// ������ �������� ���� CERT_POLICY_INFO.
     /// (��������� CERT_POLICY_INFO �������� ������������� ���������� � �������������� ������ �������������� �������).
     CERT_POLICIES_INFO PoliciesInfo;
} ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR, *PITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR;

/// ��������� ������������ ������������� ����������� ������ 2, 
/// ��������������� ��������� ESSCertID2
/// (��. RFC 5035 Enhanced Security Services (ESS) Update: Adding CertID Algorithm Agility "5.4.1.1 Certificate Identification Version 2").
typedef struct _ITCS_ESS_CERTIFICATE_ID_V2
{
     /// �������� �����������
     CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
     /// �������� ���-�������
     CRYPT_DER_BLOB             Hash;
     /// �������� �����������.
     CERT_ALT_NAME_INFO         Issuer;
     /// �������� ����� �����������.
     CRYPT_INTEGER_BLOB         SerialNumber;
} ITCS_ESS_CERTIFICATE_ID_V2, *PITCS_ESS_CERTIFICATE_ID_V2;

/// ��������� ������������ ������ �������� ���� ITCS_ESS_CERTIFICATE_ID_V2
typedef struct _ITCS_ESS_CERTIFICATE_IDS_V2
{
     /// ����� ��������� � �������
     DWORD cCertId;
#ifdef _WIN32
     __field_ecount(cCertId)
#endif
     /// ��������� �� ������ ��������
     PITCS_ESS_CERTIFICATE_ID_V2 rgCertId;
} ITCS_ESS_CERTIFICATE_IDS_V2, *PITCS_ESS_CERTIFICATE_IDS_V2;

/// ��������� ������������ �������������� ASN ��������� 
/// id-aa-signingCertificateV2 OBJECT IDENTIFIER :: = { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 47 }
/// ��������� ��. RFC 5035 Enhanced Security Services (ESS) Update: Adding CertID Algorithm Agility "5.4.1.  Signing Certificate Attribute Definition Version 2".
/// � �������� CryptEncodeObject(Ex)/CryptDecodeObject(Ex) �������� ��������������� ITCS_STRUCT_TYPE_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2.
typedef struct _ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2
{
     /// ������ ������� �������������� ������������� ����������� ������ 2
     ITCS_ESS_CERTIFICATE_IDS_V2 CertIds;
     /// ������ �������� ���� CERT_POLICY_INFO
     /// (��������� CERT_POLICY_INFO �������� ������������� ���������� � ������������ ������ �������������� �������).
     CERT_POLICIES_INFO PoliciesInfo;
} ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2, *PITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _IMPORT_ITCS_ASN_H_
