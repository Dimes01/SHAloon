namespace SHAloon_CSharp;

public class Cryptoprovider : IDisposable {
    #region Поля и свойства

    public IList<Certificate> Certificates => CertificateStorage.Certificates;

    #endregion
    #region Конструкторы

    public Cryptoprovider() {
        ImportsDLL.InitShaloon();
        CertificateStorage.getAllCertificates();
    }

    #endregion
    #region Методы

    public void SignDocument(IntPtr cert, string absoluteFilePath, string absoluteSignaturePath) { 
        ImportsDLL.SignDocument(cert, absoluteFilePath, absoluteSignaturePath);
    }
    public IntPtr VerifySignature(string absoluteFilePath, string absoluteSignaturePath) {
        return ImportsDLL.VerifySignature(absoluteFilePath, absoluteSignaturePath);
    }
    public void EncodeDocument() { }
    public void DecodeDocument() { }

    public void Dispose() {
        ImportsDLL.FinishShaloon();
    }

    #endregion
}