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
        Certificate cert = Certificate.FromCppPtr(pcert)!;
        Certificates.Add(cert);
    }
}