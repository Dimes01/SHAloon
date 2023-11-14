#ifndef _PKCS11_TC26_15_H_INCLUDED_
#define _PKCS11_TC26_15_H_INCLUDED_

#ifndef CK_VENDOR_PKCS11_RU_TEAM_TC26
#define NSSCK_VENDOR_PKCS11_RU_TEAM             0xD4321000 /* 0x80000000 | 0x54321000 */
#define CK_VENDOR_PKCS11_RU_TEAM_TC26           NSSCK_VENDOR_PKCS11_RU_TEAM
#endif // CK_VENDOR_PKCS11_RU_TEAM_TC26

#define CKK_KUZNECHIK                           (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x004)
#define CKK_MAGMA                               (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x005)

#define CKM_KUZNECHIK_KEY_GEN                   (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x019)
#define CKM_KUZNECHIK_ECB                       (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x01A)
#define CKM_KUZNECHIK_CTR                       (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x01B)
//#define CKM_KUZNECHIK_CFB                       (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x01C)
//#define CKM_KUZNECHIK_OFB                       (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x01D)
//#define CKM_KUZNECHIK_CBC                       (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x01E)
#define CKM_KUZNECHIK_MAC                       (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x01F)

//#define CKM_MAGMA_ECB                           CKM_GOST28147_ECB
#define CKM_MAGMA_CTR                           (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x020)
//#define CKM_MAGMA_CFB                           (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x021)
//#define CKM_MAGMA_OFB                           (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x022)
//#define CKM_MAGMA_CBC                           (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x023)
#define CKM_MAGMA_MAC                           (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x024)

#define CKM_KDF_4357                            (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x025)
#define CKM_KDF_GOSTR3411_2012_256              (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x026)
#define CKM_KDF_GOSTR3411_EXPORT                (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x027)

#define CKM_GOST28147_CNT                       (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x028)

#define CKM_MAGMA_ECB                           (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x029)
#define CKM_MAGMA_KEY_GEN                       (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x02A)
#define CKM_MAGMA_KEY_WRAP                      (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x02B)

#define CKM_KUZNECHIK_KEY_WRAP                  (CK_VENDOR_PKCS11_RU_TEAM_TC26 |0x02C)

#endif//_PKCS11_TC26_15_H_INCLUDED_
