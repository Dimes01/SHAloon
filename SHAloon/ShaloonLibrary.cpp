#include "pch.h"
#include "ShaloonLibrary.h"

void InitShaloon() {
    /*
    TODO:
        1. ����������, ����� ��������������� ������ ������������
        2. �� ��������� ���������� ���� 1 ���������������� ������ "cryptoprovider"
    */

    cryptoprovider = new CryptoProCSP(); // ��������
}

Certificate* GetFirstCertificate() {
    return cryptoprovider->GetFirstCertificate();
}

Certificate* GetNextCertificate() {
    return cryptoprovider->GetNextCertificate();
}

void SignDocument(Certificate* certificate, const char* absoluteFilePath) {
    /*
    TODO:
        1. ��������� �������� �� �������������
        2. ���� �������� �� ����������, �������� ��� � ��� ��������� ����������� ��������: �������
        3. ���������� � ���������������� �� ������� ���������, ���� �������� ����������
        4. �������� ��������� ���������� � ��� ��������� ����������� ��������: �����
    */
}