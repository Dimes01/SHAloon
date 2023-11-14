#ifndef ___CRYPTOKI_EX_H_INC___
#define ___CRYPTOKI_EX_H_INC___


#ifdef __GNUC__
  #define ITCAD_ATTR_PACKED        __attribute__((__packed__))
  #define ITCAD_ATTR_ALIGNED(T_)   __attribute__((__aligned__(__alignof__(T_))))
#else
  #define ITCAD_ATTR_PACKED
  #define ITCAD_ATTR_ALIGNED(T_)
#endif

/* ---------------------------------------------------------------------------
 *
 * Генерация упакованного CK_FUNCTION_LIST.
 */
#undef CK_PKCS11_FUNCTION_INFO
#undef CK_NEED_ARG_LIST

#ifdef _MSC_VER
  #pragma pack(push, 1)
#endif

struct Packed_FUNCTION_LIST
{
      CK_VERSION version;

      #define CK_PKCS11_FUNCTION_INFO(X_) \
           void * X_ ITCAD_ATTR_PACKED;

      #include <pkcs11/pkcs11f.h>
}
    ITCAD_ATTR_PACKED
    ;

#ifdef _MSC_VER
  #pragma pack(pop)
#endif

#undef CK_PKCS11_FUNCTION_INFO
#undef CK_NEED_ARG_LIST

/* ---------------------------------------------------------------------------
 *
 * Генерация неупакованного CK_FUNCTION_LIST.
 */
#undef CK_PKCS11_FUNCTION_INFO
#undef CK_NEED_ARG_LIST

#ifdef _MSC_VER
  #pragma pack(push)
#endif

struct Aligned_FUNCTION_LIST
{
      CK_VERSION version ITCAD_ATTR_ALIGNED(CK_VERSION);

      #define CK_PKCS11_FUNCTION_INFO(X_) \
           void * X_ ITCAD_ATTR_ALIGNED(void *);

      #include <pkcs11/pkcs11f.h>
};

#ifdef _MSC_VER
  #pragma pack(pop)
#endif

#undef CK_PKCS11_FUNCTION_INFO
#undef CK_NEED_ARG_LIST

#endif // ___CRYPTOKI_EX_H_INC___