#ifndef __BASEARITHMDEF_H
#define	__BASEARITHMDEF_H

#ifdef _WIN32
typedef __int64 int64_t, *pint64_t;
typedef __int32 int32_t, *pint32_t;
typedef __int16 int16_t, *pint16_t;
typedef signed __int8  int8_t,  *pint8_t;

typedef unsigned __int64 uint64_t, *puint64_t;
typedef unsigned __int32 uint32_t, *puint32_t;
typedef unsigned __int16 uint16_t, *puint16_t;
typedef unsigned __int8  uint8_t,  *puint8_t;

#ifndef INT64_MIN
#define	INT64_MIN		(-0x7fffffffffffffffLL - 1)
#endif

#ifndef INT32_C
#   define	INT32_C(_c)	(_c)
#endif
#ifndef INT64_C
#   define	INT64_C(_c)	(##_cLL)
#endif
#ifndef UINT32_C
#   define	UINT32_C(_c)	(##_cU)
#endif
#ifndef UINT64_C
#   define	UINT64_C(_c)	(##_cULL)
#endif

#else /*_WIN32*/
#include <stdint.h>

typedef int64_t *pint64_t;
typedef int32_t *pint32_t;
typedef int16_t *pint16_t;
typedef int8_t  *pint8_t;

typedef uint64_t *puint64_t;
typedef uint32_t *puint32_t;
typedef uint16_t *puint16_t;
typedef uint8_t  *puint8_t;

#endif /*_WIN32*/

typedef union uint128_t {
    uint64_t    ui64[2];
    uint32_t    ui32[4];
    uint32_t       dw[4];
    uint16_t    ui16[8];
    uint8_t     ui8[16];
} uint128_t, *puint128_t;


#define hi64(w128) (w128.ui64[1])
#define lo64(w128) (w128.ui64[0])
#define phi64(pw128) (((puint64_t)pw128)+1)
#define plo64(pw128) ((puint64_t)pw128)

/*
*   Патформа LITTLENDIAN:
*      uint64_t = (uint32_t_hi,uint32_t_lo)
*   Патформа BIGENDIAN:
*      uint64_t = (uint32_t_lo,uint32_t_hi)
*
*   согасование порядка uint32_t слов в uint64_t
*   в модуле support.c
*/
#ifdef OLD_VPOPOV_CODE
#if defined (WORDS_BIGENDIAN)
#define hi32(w64) *((uint32_t *)&w64)
#define lo32(w64) *(((uint32_t*)&w64)+1)//(uint32_t)(w64>>32)
#define lo32(w64) (uint32_t)w64
#define phi32(pw64) (((puint32_t)pw64)+1)
#define plo32(pw64) ((puint32_t)pw64)
#define TOP 0
#define BOT 1
#else /*defined (WORDS_BIGENDIAN)*/
#define hi32(w64) *(((uint32_t*)&w64)+1)/*(uint32_t)(w64>>32)*/
#define lo32(w64) (uint32_t)w64
#define phi32(pw64) ((puint32_t)pw64)
#define plo32(pw64) (((puint32_t)pw64)+1)
#define TOP 1
#define BOT 0
#endif /*defined (WORDS_BIGENDIAN)*/
#else
#define MASK_HIGH_32 0xFFFFFFFF00000000ULL
#define MASK_LOW_32  0xFFFFFFFFULL
#define hi32(w64) ((uint32_t)((w64)>>32))
#define lo32(w64) ((uint32_t)(w64))
#define dw2qw(dw1,dw2) ((((uint64_t)(dw1))<<32)|((uint64_t)(dw2)))
#endif


typedef uint64_t uint64_64_t[2];
typedef uint64_64_t *puint64_64_t;

typedef uint32_t uint32_32_t[2];

#ifdef OLD_VPOPOV_CODE

typedef union _int_32_64_ {
    uint64_t    ui64;
    uint32_t	ui32[2];
} uint32_64,*puint32_64;

#define dw_qw(u64,i) ((uint32_t)((uint32_64)u64).ui32[i])
#define dw_pqw(pu64,i) ((uint32_t)((uint32_64*)pu64)->ui32[i])
#define pdw_pqw(pu64,i) ((uint32_t*)&((uint32_64*)pu64)->ui32[i])
#define pdw_qw(pu64,i) ((uint32_t*)&((uint32_64)pu64).ui32[i])
#endif


/* Максимальный размер сомножителя в байтах */
#define MAX_N_BYTE 128
#define MAX_N_DW 32
#define MAX_N_QW 16



#endif /*__BASEARITHMDEF_H*/

