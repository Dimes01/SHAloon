using System.Runtime.InteropServices;

namespace SHAloon_CSharp;

public class Cryptoprovider	{
	#region Поля и свойства

	private const string path_to_dll_cryptoprovider = "SHAloon.dll";

	public IList<Certificate> Certificates { get; private set; } = new List<Certificate>();

	#endregion
	#region Импортируемые функции

	[DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
	private static extern void InitShaloon();

	[DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
	private static extern void FinishShaloon();
							   
	[DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
	private static extern IntPtr GetFirstCertificate();

    [DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
    private static extern IntPtr GetNextCertificate();

	[DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
	private static extern IntPtr GetCertificateSubject(IntPtr cert);

	[DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
	private static extern IntPtr GetCertificateIssuer(IntPtr cert);

	[DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
	private static extern IntPtr GetCertificateSerialNumber(IntPtr cert);

	[DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
	private static extern IntPtr GetCertificateNotAfter(IntPtr cert);

    #endregion
    #region Конструкторы

    public Cryptoprovider() {
		InitShaloon();
		getAllCertificates();
		FinishShaloon();
	}

	#endregion
	#region Методы

	private void getAllCertificates() {
		IntPtr pcert = GetFirstCertificate();
		if (pcert == IntPtr.Zero) return;

		addCertificate(pcert);

        while ((pcert = GetNextCertificate()) != IntPtr.Zero) {
			addCertificate(pcert);
		}
    }

	private void addCertificate(IntPtr pcert) {
        Certificate cert = new() {
			CppPointer = pcert,
            SubjectName = Marshal.PtrToStringAuto(GetCertificateSubject(pcert)) ?? "",
            IssuerName = Marshal.PtrToStringAuto(GetCertificateIssuer(pcert)) ?? "",
            SerialNumber = Marshal.PtrToStringAuto(GetCertificateSerialNumber(pcert)) ?? "",
            NotAfter = Marshal.PtrToStringAuto(GetCertificateNotAfter(pcert)) ?? ""
        };

        Certificates.Add(cert);
	}

	#endregion
}