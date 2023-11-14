#pragma once

class Certificate
{
private:
    std::string mSubject;
    std::string mIssuer;
    std::string mSerialNumber;
    std::string mNotAfter;

public:
    Certificate();

    void SetSubject(const std::string& subject);
    std::string GetSubject();

    void SetIssuer(const std::string& issuer);
    std::string GetIssuer();

    void SetSerialNumber(const std::string& serialNumber);
    std::string GetSerialNumber();

    void SetNotAfter(const std::string& notAfter);
    std::string GetNotAfter();
};

