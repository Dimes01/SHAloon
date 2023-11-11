#pragma once

#include <string>

class Certificate
{
private:
    std::string mSubject;
    std::string mPublicKey;

public:
    Certificate(const std::string& subject, const std::string& publicKey);

    void SetSubject(const std::string& subject);
    std::string GetSubject();
};

