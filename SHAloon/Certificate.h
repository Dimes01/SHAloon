#pragma once

#include "Logger.h"

class Certificate
{
private:

    // ** or 0*
    constexpr static auto CertificateDataByteFormat = _T("{:02x}");

    // YYYY-MM-DD or YYYY-0M-0D
    constexpr static auto CertificateTimeFormat = _T("{}-{:02}-{:02}");

    PCCERT_CONTEXT mCertContext;

    tstring mSubject;
    tstring mIssuer;
    tstring mSerialNumberString;
    tstring mNotAfter;

    tstring mNotBefore;
    tstring mSha1Hash;
    tstring mPublicKeyBytes;
    std::basic_string<WCHAR> mPublicKeyAlgorithm;
    std::basic_string<WCHAR> mSignatureAlgorithm;
    std::basic_string<WCHAR> mFullSubject;
    std::basic_string<WCHAR> mFullIssuer;

    std::basic_string<WCHAR> getNameRDNAttrName(const CERT_RDN_ATTR& attr);

    void setSubject();
    void setIssuer();
    void setNotAfter();
    void setSerialNumber();

    void setNotBefore();
    void setSha1Hash();
    void setPublicKeyBytes();
    void setPublicKeyAlgorithm();
    void setSignatureAlgorithm();
    void setFullName(const CERT_NAME_BLOB& person, std::basic_string<WCHAR>& name);
    void setFullSubject();
    void setFullIssuer();

public:
    Certificate(PCCERT_CONTEXT validPcCertContext);

    tstring GetSubject();
    tstring GetIssuer();
    tstring GetSerialNumber();
    tstring GetNotAfter();
    PCCERT_CONTEXT GetCertContext();

    tstring GetNotBefore();
    tstring GetSha1Hash();
    tstring GetPublicKeyBytes();
    std::basic_string<WCHAR> GetPublicKeyAlgorithm();
    std::basic_string<WCHAR> GetSignatureAlgorithm();

    ~Certificate();
};

