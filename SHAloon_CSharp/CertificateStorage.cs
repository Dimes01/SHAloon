using System.Runtime.InteropServices;

namespace SHAloon_CSharp;

internal static class CertificateStorage {
    internal static IList<Certificate> Certificates { get; private set; } = new List<Certificate>();

    internal static void getAllCertificates() {
        IntPtr pcert = ImportsDLL.GetFirstCertificate();
        if (pcert == IntPtr.Zero) return;

        addCertificate(pcert);

        while ((pcert = ImportsDLL.GetNextCertificate()) != IntPtr.Zero) {
            addCertificate(pcert);
        }
    }

    private static void addCertificate(IntPtr pcert) {
        Certificate cert = new() {
            CppPointer = pcert,
            SubjectName = Marshal.PtrToStringAuto(ImportsDLL.GetCertificateSubject(pcert)) ?? "",
            IssuerName = Marshal.PtrToStringAuto(ImportsDLL.GetCertificateIssuer(pcert)) ?? "",
            SerialNumber = Marshal.PtrToStringAuto(ImportsDLL.GetCertificateSerialNumber(pcert)) ?? "",
            NotAfter = Marshal.PtrToStringAuto(ImportsDLL.GetCertificateNotAfter(pcert)) ?? ""
        };

        Certificates.Add(cert);
    }
}