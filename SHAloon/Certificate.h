#pragma once

class Certificate
{
private:
    PCCERT_CONTEXT mCertContext;

    tstring mSubject;
    tstring mIssuer;
    tstring mSerialNumberString;
    tstring mNotAfter;

public:
    Certificate();

    void SetSubject(const tstring& subject);
    tstring GetSubject();

    void SetIssuer(const tstring& issuer);
    tstring GetIssuer();

    void SetSerialNumber(const BYTE* serialNumber, const DWORD serialNumberSize);
    tstring GetSerialNumber();

    void SetNotAfter(const tstring& notAfter);
    tstring GetNotAfter();

    void SetCertContext(PCCERT_CONTEXT certContext);
    PCCERT_CONTEXT GetCertContext();

    ~Certificate();
};

