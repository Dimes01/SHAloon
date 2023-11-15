namespace SHAloon_CSharp;

public class Certificate {
    public IntPtr CppPointer { get; set; } = IntPtr.Zero;

    public string SubjectName { get; set; } = "";
    public string IssuerName { get; set; } = "";
    public string SerialNumber { get; set; } = "";
    public string NotAfter { get; set; } = "";
}

