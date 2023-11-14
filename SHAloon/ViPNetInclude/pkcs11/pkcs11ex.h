/// @file 
/// @brief Расширение интерфейса pkcs11 2.40, не входящее в расширения от tc26.
/// 
/// @copyright Copyright (c) Infotecs. All Rights Reserved.

#ifndef _PKCS11EX_H_
#define _PKCS11EX_H_

#include <pkcs11/pkcs11tc26.h>

#pragma pack(push, cryptoki, 1)

/// Зарезервированные пространства идентификаторов для конкретных компонент.
/// Используются для определения всех внутренних типов атрибутов, механизмов, кодов ошибок и пр. 
/// Необходимы для избежания потенциальных конфликтов при использовании интерфейса PKCS#11. 
///
/// Например:
/// 
/// #define ITCS_MY_VENDOR      (CKA_VENDOR_DEFINED | 0x12300000)
/// #define CKA_ITCS_MY_ATTR    (ITCS_MY_VENDOR     | 0x321)

/// @brief Пространство идентификаторов для компонентов группы pkcs11_vccc (soft_token, pkcs11_vccc_sdk_iface и другие). 
#define ITCS_P11_VCCC_VENDOR  (CKA_VENDOR_DEFINED | 0x27300000)
/// @brief Пространство идентификаторов для ХСМ
#define ITCS_HSM_VENDOR       (CKA_VENDOR_DEFINED | 0x27400000)

/// Определения, которые когда-то были в документах PKCS#11 ТК26, но потом были оттуда убраны.
/// Оставлены здесь для совместимости. 

// Атрибут CKA_GOSTR3410_512PARAMS был в pkcs11tc26.h, но удален.
// Пока будет тут, для временного сохранения совместимости
#define CKA_GOSTR3410_512PARAMS            (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x004)

// Дополнительный атрибут для того, чтобы избежать заморочек в TLS
// Смысл заморочек в следующем: в TLS используется режим OFB,
// а в большинстве других режимов шифрования - CFB.
// ENCRYPT_MODE (CFB или OFB) определяется в наборе DomainParameters,
// который привязан к OID. Таким образом, у одного OID может быть только
// один, фиксированный ENCRYPT_MODE. Введение дополнительного атрибута
// CKA_ENCRYPT_MODE позволяет перешибить ENCRYPT_MODE, заданный в OID.
// По аналогии с RFC-4357, значения будут следующие:
// 0 - OFB;
// 1 - CFB;
// 2 - CBC
#define CKA_ENCRYPT_MODE                        (NSSCK_VENDOR_PKCS11_RU_TEAM |0x001)

#pragma pack(pop, cryptoki)

#endif
