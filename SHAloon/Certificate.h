#pragma once

class Certificate
{
private:
    BYTE* mSerialNumberBinary = nullptr;

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

    ~Certificate();
};

