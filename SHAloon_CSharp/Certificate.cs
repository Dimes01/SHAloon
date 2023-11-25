namespace SHAloon_CSharp;

public class Certificate {
    public IntPtr CppPointer { get; internal set; } = IntPtr.Zero;

    public string SubjectName { get; internal set; } = string.Empty;
    public string IssuerName { get; internal set; } = string.Empty;
    public string SerialNumber { get; internal set; } = string.Empty;
    public string NotAfter { get; internal set; } = string.Empty;
    
    public string NotBefore { get; internal set; } = string.Empty;
    public string Sha1Hash { get; internal set; } = string.Empty;
    public string PublicKeyBytes { get; internal set; } = string.Empty;
    public string PublicKeyAlgorithm { get; internal set; } = string.Empty;
    public string SignatureAlgorithm { get; internal set; } = string.Empty;
    public string FullSubjectName { get; internal set; } = string.Empty;
    public string FullIssuerName { get; internal set; } = string.Empty;

    public static Certificate? FromCppPtr(IntPtr pcert) {
        if (pcert == IntPtr.Zero) return null;

        return new Certificate() {
            CppPointer = pcert,
            SubjectName = ImportsDLL.GetCertificateSubject(pcert),
            IssuerName = ImportsDLL.GetCertificateIssuer(pcert),
            SerialNumber = ImportsDLL.GetCertificateSerialNumber(pcert),
            NotAfter = ImportsDLL.GetCertificateNotAfter(pcert),
            NotBefore = ImportsDLL.GetCertificateNotBefore(pcert),
            Sha1Hash = ImportsDLL.GetCertificateSha1Hash(pcert),
            PublicKeyBytes = ImportsDLL.GetCertificatePublicKeyBytes(pcert),
            PublicKeyAlgorithm = ImportsDLL.GetCertificatePublicKeyAlgorithm(pcert),
            SignatureAlgorithm = ImportsDLL.GetCertificateSignatureAlgorithm(pcert),
            FullSubjectName = ImportsDLL.GetCertificateFullSubject(pcert),
            FullIssuerName = ImportsDLL.GetCertificateFullIssuer(pcert)
        };
    }
}

