#include "pch.h"
#include <string>

#define SHALOONAPI __declspec(dllexport)

class Certificate
{
private:
    std::string subject;
    std::string public_key;

public:
    Certificate(const std::string& _subject, const std::string& _public_key)
    {
        subject = _subject;
        public_key = _public_key;
    }

    void set_subject(const std::string _new_subject)
    {
        subject = std::string(_new_subject);
    }

    std::string get_subject()
    {
        return subject;
    }
};

extern "C" 
{
    SHALOONAPI Certificate* Certificate_Constructor(const char* _subject, const char* _public_key)
    {
        return new Certificate(std::string(_subject), std::string(_public_key));
    }

    SHALOONAPI void Certificate_Set_subject(Certificate* instance, const char* _new_subject)
    {
        instance->set_subject(std::string(_new_subject));
    }

    SHALOONAPI char* Certificate_Get_subject(Certificate* instance)
    {
        std::string res_string = instance->get_subject();
        int length = res_string.size();
        char* res = new char[length + 1];
        strcpy_s(res, length + 1, res_string.c_str());
        return res;
    }

    // ƒемонстраци€ конвертации из массива символов в строку и обратно
    SHALOONAPI char* test_string(const char* str)
    {
        std::string res(str);
        res += "csharp";

        // а вот здесь начинаетс€ маги€, так как дл€ освобождени€ пам€ти не понадобитс€ delete
        char* arr = new char[res.size() + 1];
        strcpy_s(arr, res.size() + 1, res.c_str());
        return arr;
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    return TRUE;
}
