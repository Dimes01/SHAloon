using System.Runtime.InteropServices;

namespace SHAloon_CSharp;

public class Cryptoprovider	{
	#region Поля и свойства

	public IList<Certificate> Certificates => CertificateStorage.Certificates;

    #endregion
    #region Конструкторы

    public Cryptoprovider() {
		ImportsDLL.InitShaloon();
		CertificateStorage.getAllCertificates();
		ImportsDLL.FinishShaloon();
	}

	#endregion
	#region Методы

	public void SignDocument() { }
	public void CheckSignDocument() { }
	public void EncodeDocument() { }
	public void DecodeDocument() { }

	#endregion
}