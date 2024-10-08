﻿namespace SHAloon_CSharp;

public class Cryptoprovider : IDisposable {
    #region Поля и свойства

    public IList<Certificate> Certificates => CertificateStorage.Certificates;

    #endregion
    #region Конструкторы

    public Cryptoprovider() {
        ImportsDLL.InitShaloon();
    }

    #endregion
    #region Методы

    public void GetAllCertificates() {
        CertificateStorage.getAllCertificates();
    }

    public void SignDocument(Certificate cert, string absoluteFilePath, string absoluteSignaturePath) { 
        ImportsDLL.SignDocument(cert.CppPointer, absoluteFilePath, absoluteSignaturePath);
    }

    public Certificate? VerifySignature(string absoluteFilePath, string absoluteSignaturePath) {
        var pcert = ImportsDLL.VerifySignature(absoluteFilePath, absoluteSignaturePath);
        return Certificate.FromCppPtr(pcert);
    }

    public void EncryptDocument(Certificate cert, string absoluteSourcePath, string absoluteEncryptedPath) {
        ImportsDLL.EncryptDocument(cert.CppPointer, absoluteSourcePath, absoluteEncryptedPath);
    }

    public Certificate? DecryptDocument(string absoluteEncryptedPath, string absoluteDecryptedPath) {
        var pcert = ImportsDLL.DecryptDocument(absoluteEncryptedPath, absoluteDecryptedPath);
        return Certificate.FromCppPtr(pcert);
    }

    public void Dispose() {
        ImportsDLL.FinishShaloon();
    }

    #endregion
}