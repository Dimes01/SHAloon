#pragma once

#include "Logger.h"

constexpr auto CertificateSerialNumberByteFormat = _T("{:02x}");
constexpr auto CertificateTimeFormat = _T("{}-{:02}-{:02}");

class Certificate
{
private:
    PCCERT_CONTEXT mCertContext;

    tstring mSubject;
    tstring mIssuer;
    tstring mSerialNumberString;
    tstring mNotAfter;

    void setSubject();
    void setIssuer();
    void setNotAfter();
    void setSerialNumber();

public:
    Certificate(PCCERT_CONTEXT validPcCertContext);

    tstring GetSubject();
    tstring GetIssuer();
    tstring GetSerialNumber();
    tstring GetNotAfter();
    PCCERT_CONTEXT GetCertContext();

    ~Certificate();
};

