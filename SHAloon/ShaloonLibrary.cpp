#include "pch.h"
#include "ShaloonLibrary.h"

void InitShaloon() {
    /*
    TODO:
        1. Определить, какой криптопровайдер сейчас используется
        2. На основании результата шага 1 инициализировать объект "cryptoprovider"
    */

    cryptoprovider = new CryptoProCSP(); // Заглушка
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
        1. Проверить документ на существование
        2. Если документ не существует, записать это в лог последней совершённой операции: неудача
        3. Обратиться к криптопровайдеру на подпись документа, если документ существует
        4. Записать результат подписания в лог последней совершённой операции: успех
    */
}