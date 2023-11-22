namespace SHAloon_CSharp;

public class Certificate {
    public IntPtr CppPointer { get; internal set; } = IntPtr.Zero;

    public string SubjectName { get; internal set; } = string.Empty;
    public string IssuerName { get; internal set; } = string.Empty;
    public string SerialNumber { get; internal set; } = string.Empty;
    public string NotAfter { get; internal set; } = string.Empty;

    public static Certificate? FromCppPtr(IntPtr pcert) {
        if (pcert == IntPtr.Zero) return null;

        return new Certificate() {
            CppPointer = pcert,
            SubjectName = ImportsDLL.GetCertificateSubject(pcert),
            IssuerName = ImportsDLL.GetCertificateIssuer(pcert),
            SerialNumber = ImportsDLL.GetCertificateSerialNumber(pcert),
            NotAfter = ImportsDLL.GetCertificateNotAfter(pcert)
        };
    }
}

