#pragma once

#include <string>

class Certificate
{
private:
    std::string subject;
    std::string public_key;

public:
    Certificate(const std::string& _subject, const std::string& _public_key);

    void SetSubject(const std::string& _subject);
    std::string GetSubject();
};

