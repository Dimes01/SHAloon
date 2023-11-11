#include "pch.h"
#include "Certificate.h"

Certificate::Certificate(const std::string& _subject, const std::string& _public_key)
    : subject(_subject), public_key(_public_key) {}

void Certificate::SetSubject(const std::string& _subject) {
    subject = _subject;
}

std::string Certificate::GetSubject() {
    return subject;
}