using System.Runtime.InteropServices;

namespace SHAloon_CSharp;

internal static class ImportsDLL {
    internal const string path_to_dll_cryptoprovider = "cpplib\\SHAloon.dll";

    [DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
    internal static extern void InitShaloon();

    [DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
    internal static extern void FinishShaloon();

    [DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
    internal static extern IntPtr GetFirstCertificate();

    [DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
    internal static extern IntPtr GetNextCertificate();

    [DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
    internal static extern IntPtr GetCertificateSubject(IntPtr cert);

    [DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
    internal static extern IntPtr GetCertificateIssuer(IntPtr cert);

    [DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
    internal static extern IntPtr GetCertificateSerialNumber(IntPtr cert);

    [DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
    internal static extern IntPtr GetCertificateNotAfter(IntPtr cert);

    [DllImport(path_to_dll_cryptoprovider, CharSet=CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern void SignDocument(IntPtr cert, string absoluteFileName, string absoluteSignatureName);

    [DllImport(path_to_dll_cryptoprovider, CharSet=CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern IntPtr VerifySignature(string absoluteFileName, string absoluteSignatureName);
}