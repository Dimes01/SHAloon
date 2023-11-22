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

    [DllImport(path_to_dll_cryptoprovider, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern string GetCertificateSubject(IntPtr cert);

    [DllImport(path_to_dll_cryptoprovider, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern string GetCertificateIssuer(IntPtr cert);

    [DllImport(path_to_dll_cryptoprovider, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern string GetCertificateSerialNumber(IntPtr cert);

    [DllImport(path_to_dll_cryptoprovider, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern string GetCertificateNotAfter(IntPtr cert);

    [DllImport(path_to_dll_cryptoprovider, CharSet=CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern void SignDocument(IntPtr cert, string absoluteFileName, string absoluteSignatureName);

    [DllImport(path_to_dll_cryptoprovider, CharSet=CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern IntPtr VerifySignature(string absoluteFileName, string absoluteSignatureName);

    [DllImport(path_to_dll_cryptoprovider, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern void EncryptDocument(IntPtr cert, string absoluteSourcePath, string absoluteEncryptedPath);

    [DllImport(path_to_dll_cryptoprovider, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern void DecryptDocument(string absoluteEncryptedPath, string absoluteDecryptedPath);


    [DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
    internal static extern bool GetLogSuccess();

    [DllImport(path_to_dll_cryptoprovider, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern string GetLogSource();

    [DllImport(path_to_dll_cryptoprovider, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern string GetLogSummary();

    [DllImport(path_to_dll_cryptoprovider, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern string GetLogMessage();

    [DllImport(path_to_dll_cryptoprovider, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern string GetLogTime();

    [DllImport(path_to_dll_cryptoprovider, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
    internal static extern string GetLogLevel();
}