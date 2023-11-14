/// @file
/// @brief ���������� ��������� ��������������� CAdES ���������.
///
/// @copyright Copyright (c) InfoTeCS. All Rights Reserved.

#ifndef ITCS_CADES_DEFS_H
#define ITCS_CADES_DEFS_H

/// ��������� �������������, ������������ signatureTimeStampToken ������� (����� �������) ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "6.1.1.  signature-time-stamp Attribute Definition"
/// id - aa - signatureTimeStampToken OBJECT IDENTIFIER :: = { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs - 9(9) smime(16) id - aa(2) 14 }.
/// Ascii ������.
#define szOID_RSA_SMIME_SignatureTimeStamp "1.2.840.113549.1.9.16.2.14"
/// ��������� �������������, ������������ signatureTimeStampToken ������� (����� �������) ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "6.1.1.  signature-time-stamp Attribute Definition"
/// id - aa - signatureTimeStampToken OBJECT IDENTIFIER :: = { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs - 9(9) smime(16) id - aa(2) 14 }.
/// Unicode ������.
#define szOID_RSA_SMIME_SignatureTimeStamp_W L"1.2.840.113549.1.9.16.2.14"

/// ��������� �������������, ������������ signingCertificate ������� ������������ ���������.
/// ��������� ��. RFC 2634 Enhanced Security Services for S/MIME � RFC 5126 CMS Advanced Electronic Signatures (CAdES) "5.7.3.1.  ESS signing-certificate Attribute Definition"
/// id-aa-signingCertificate OBJECT IDENTIFIER ::= { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 12 }.
/// Ascii ������.
#define szOID_ITCS_ESS_SIGNING_CERTIFICATE_ATTR "1.2.840.113549.1.9.16.2.12"
/// ��������� �������������, ������������ signingCertificate ������� ������������ ���������.
/// ��������� ��. RFC 2634 Enhanced Security Services for S/MIME � RFC 5126 CMS Advanced Electronic Signatures (CAdES) "5.7.3.1.  ESS signing-certificate Attribute Definition"
/// id-aa-signingCertificate OBJECT IDENTIFIER ::= { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 12 }.
/// Unicode ������.
#define szOID_ITCS_ESS_SIGNING_CERTIFICATE_ATTR_W L"1.2.840.113549.1.9.16.2.12"

/// ��������� �������������, ������������ signingCertificateV2 ������� ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "5.7.3.2. ESS signing-certificate-v2 Attribute Definition"
/// id - aa - signingCertificateV2 OBJECT IDENTIFIER :: = { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 47 }.
/// Ascii ������.
#define szOID_ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2 "1.2.840.113549.1.9.16.2.47"
/// ��������� �������������, ������������ signingCertificateV2 ������� ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "5.7.3.2. ESS signing-certificate-v2 Attribute Definition"
/// id - aa - signingCertificateV2 OBJECT IDENTIFIER :: = { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs9(9) smime(16) id - aa(2) 47 }.
/// Unicode ������.
#define szOID_ITCS_ESS_SIGNING_CERTCERTIFICATE_ATTR_V2_W L"1.2.840.113549.1.9.16.2.47"

/// ��������� �������������, ������������ ets-certificateRefs ������� ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "6.2.1. complete - certificate - references Attribute Definition"
/// id-aa-ets-certificateRefs OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs - 9(9) smime(16) id - aa(2) 21 }.
/// Ascii ������.
#define szOID_RSA_SMIME_CompleteCertRefs "1.2.840.113549.1.9.16.2.21"
/// ��������� �������������, ������������ ets-certificateRefs ������� ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "6.2.1. complete - certificate - references Attribute Definition"
/// id-aa-ets-certificateRefs OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs - 9(9) smime(16) id - aa(2) 21 }.
/// Unicode ������.
#define szOID_RSA_SMIME_CompleteCertRefs_W L"1.2.840.113549.1.9.16.2.21"

/// ��������� �������������, ������������ ets-revocationRefs ������� ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "6.2.2. complete-revocation-references Attribute Definition"
/// id-aa-ets-revocationRefs OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs - 9(9) smime(16) id - aa(2) 22 }.
/// Ascii ������.
#define szOID_RSA_SMIME_CompleteRevocationRefs "1.2.840.113549.1.9.16.2.22"
/// ��������� �������������, ������������ ets-revocationRefs ������� ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "6.2.2. complete-revocation-references Attribute Definition"
/// id-aa-ets-revocationRefs OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs - 9(9) smime(16) id - aa(2) 22 }.
/// Unicode ������.
#define szOID_RSA_SMIME_CompleteRevocationRefs_W L"1.2.840.113549.1.9.16.2.22"

/// ��������� �������������, ������������ ets-certValues ������� ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "6.3.3. certificate-values Attribute Definition"
/// id-aa-ets-certValues OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs - 9(9) smime(16) id - aa(2) 23 }.
/// Ascii ������.
#define szOID_RSA_SMIME_CompleteCertValues "1.2.840.113549.1.9.16.2.23"
/// ��������� �������������, ������������ ets-certValues ������� ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "6.3.3. certificate-values Attribute Definition"
/// id-aa-ets-certValues OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs - 9(9) smime(16) id - aa(2) 23 }.
/// Unicode ������.
#define szOID_RSA_SMIME_CompleteCertValues_W L"1.2.840.113549.1.9.16.2.23"

/// ��������� �������������, ������������ ets-revocationValues ������� ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "6.3.4. revocation-values Attribute Definition"
/// id-aa-ets-revocationValues OBJECT IDENTIFIER ::= { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs - 9(9) smime(16) id - aa(2) 24 }.
/// Ascii ������.
#define szOID_RSA_SMIME_CompleteRevocationValues "1.2.840.113549.1.9.16.2.24"
/// ��������� �������������, ������������ ets-revocationValues ������� ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "6.3.4. revocation-values Attribute Definition"
/// id-aa-ets-revocationValues OBJECT IDENTIFIER ::= { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs - 9(9) smime(16) id - aa(2) 24 }.
/// Unicode ������.
#define szOID_RSA_SMIME_CompleteRevocationValues_W L"1.2.840.113549.1.9.16.2.24"

/// ��������� �������������, ������������ ets-escTimeStamp ������� ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "6.3.5. CAdES-C-time-stamp Attribute Definition"
/// id-aa-ets-escTimeStamp OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs - 9(9) smime(16) id - aa(2) 25 }.
/// Ascii ������.
#define szOID_RSA_SMIME_CadesCTimeStamp "1.2.840.113549.1.9.16.2.25"
/// ��������� �������������, ������������ ets-escTimeStamp ������� ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "6.3.5. CAdES-C-time-stamp Attribute Definition"
/// id-aa-ets-escTimeStamp OBJECT IDENTIFIER ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs - 9(9) smime(16) id - aa(2) 25 }.
/// Unicode ������.
#define szOID_RSA_SMIME_CadesCTimeStamp_W L"1.2.840.113549.1.9.16.2.25"

/// ��������� �������������, ������������ ets-certCRLTimestamp ������� ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "6.3.6. time-stamped-certs-crls-references Attribute Definition"
/// id-aa-ets-certCRLTimestamp OBJECT IDENTIFIER ::= { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs - 9(9) smime(16) id - aa(2) 26 }.
/// Ascii ������.
#define szOID_RSA_SMIME_CadesCTimeStampedCertsCrlsRefs "1.2.840.113549.1.9.16.2.26"
/// ��������� �������������, ������������ ets-certCRLTimestamp ������� ������������ ���������.
/// ��������� ��. RFC 5126 CMS Advanced Electronic Signatures (CAdES) "6.3.6. time-stamped-certs-crls-references Attribute Definition"
/// id-aa-ets-certCRLTimestamp OBJECT IDENTIFIER ::= { iso(1) member - body(2) us(840) rsadsi(113549) pkcs(1) pkcs - 9(9) smime(16) id - aa(2) 26 }.
/// Unicode ������.
#define szOID_RSA_SMIME_CadesCTimeStampedCertsCrlsRefs_W L"1.2.840.113549.1.9.16.2.26"

#endif // ITCS_CADES_DEFS_H
