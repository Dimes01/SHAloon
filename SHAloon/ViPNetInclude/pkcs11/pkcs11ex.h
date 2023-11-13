/// @file 
/// @brief ���������� ���������� pkcs11 2.40, �� �������� � ���������� �� tc26.
/// 
/// @copyright Copyright (c) Infotecs. All Rights Reserved.

#ifndef _PKCS11EX_H_
#define _PKCS11EX_H_

#include <pkcs11/pkcs11tc26.h>

#pragma pack(push, cryptoki, 1)

/// ����������������� ������������ ��������������� ��� ���������� ���������.
/// ������������ ��� ����������� ���� ���������� ����� ���������, ����������, ����� ������ � ��. 
/// ���������� ��� ��������� ������������� ���������� ��� ������������� ���������� PKCS#11. 
///
/// ��������:
/// 
/// #define ITCS_MY_VENDOR      (CKA_VENDOR_DEFINED | 0x12300000)
/// #define CKA_ITCS_MY_ATTR    (ITCS_MY_VENDOR     | 0x321)

/// @brief ������������ ��������������� ��� ����������� ������ pkcs11_vccc (soft_token, pkcs11_vccc_sdk_iface � ������). 
#define ITCS_P11_VCCC_VENDOR  (CKA_VENDOR_DEFINED | 0x27300000)
/// @brief ������������ ��������������� ��� ���
#define ITCS_HSM_VENDOR       (CKA_VENDOR_DEFINED | 0x27400000)

/// �����������, ������� �����-�� ���� � ���������� PKCS#11 ��26, �� ����� ���� ������ ������.
/// ��������� ����� ��� �������������. 

// ������� CKA_GOSTR3410_512PARAMS ��� � pkcs11tc26.h, �� ������.
// ���� ����� ���, ��� ���������� ���������� �������������
#define CKA_GOSTR3410_512PARAMS            (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x004)

// �������������� ������� ��� ����, ����� �������� ��������� � TLS
// ����� ��������� � ���������: � TLS ������������ ����� OFB,
// � � ����������� ������ ������� ���������� - CFB.
// ENCRYPT_MODE (CFB ��� OFB) ������������ � ������ DomainParameters,
// ������� �������� � OID. ����� �������, � ������ OID ����� ���� ������
// ����, ������������� ENCRYPT_MODE. �������� ��������������� ��������
// CKA_ENCRYPT_MODE ��������� ���������� ENCRYPT_MODE, �������� � OID.
// �� �������� � RFC-4357, �������� ����� ���������:
// 0 - OFB;
// 1 - CFB;
// 2 - CBC
#define CKA_ENCRYPT_MODE                        (NSSCK_VENDOR_PKCS11_RU_TEAM |0x001)

#pragma pack(pop, cryptoki)

#endif
