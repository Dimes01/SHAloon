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

    tstring mSha1Hash;

    void setSubject();
    void setIssuer();
    void setNotAfter();
    void setSerialNumber();

    void setSha1Hash();

public:
    Certificate(PCCERT_CONTEXT validPcCertContext);

    tstring GetSubject();
    tstring GetIssuer();
    tstring GetSerialNumber();
    tstring GetNotAfter();
    PCCERT_CONTEXT GetCertContext();

    ~Certificate();
};

