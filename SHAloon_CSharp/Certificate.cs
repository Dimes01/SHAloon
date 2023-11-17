using System.Runtime.ConstrainedExecution;
using System.Runtime.InteropServices;

namespace SHAloon_CSharp;

public class Certificate {
    public IntPtr CppPointer { get; internal set; } = IntPtr.Zero;

    public string SubjectName { get; internal set; } = "";
    public string IssuerName { get; internal set; } = "";
    public string SerialNumber { get; internal set; } = "";
    public string NotAfter { get; internal set; } = "";

    public static Certificate? FromCppPtr(IntPtr pcert) {
        if (pcert == IntPtr.Zero) return null;

        return new Certificate() {
            CppPointer = pcert,
            SubjectName = Marshal.PtrToStringAuto(ImportsDLL.GetCertificateSubject(pcert)) ?? "",
            IssuerName = Marshal.PtrToStringAuto(ImportsDLL.GetCertificateIssuer(pcert)) ?? "",
            SerialNumber = Marshal.PtrToStringAuto(ImportsDLL.GetCertificateSerialNumber(pcert)) ?? "",
            NotAfter = Marshal.PtrToStringAuto(ImportsDLL.GetCertificateNotAfter(pcert)) ?? ""
        };
    }
}

