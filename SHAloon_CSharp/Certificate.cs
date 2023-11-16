namespace SHAloon_CSharp;

public class Certificate {
    public IntPtr CppPointer { get; internal set; } = IntPtr.Zero;

    public string SubjectName { get; internal set; } = "";
    public string IssuerName { get; internal set; } = "";
    public string SerialNumber { get; internal set; } = "";
    public string NotAfter { get; internal set; } = "";
}

