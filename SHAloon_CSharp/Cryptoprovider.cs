using System.Runtime.InteropServices;

namespace SHAloon_CSharp
{
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
			initShaloon();
			getAllCertificates();
			finishShaloon();
		}

        #endregion
        #region Методы

		private void initShaloon() {
			InitShaloon();
		}

		private void finishShaloon() {
			FinishShaloon();
		}

		private IntPtr getFirstCertificate() {
			IntPtr pcert = GetFirstCertificate();
            if (pcert == IntPtr.Zero) return IntPtr.Zero;

			addCertificate(pcert);
			return pcert;
        }

        private void getAllCertificates() {
			IntPtr pcert = getFirstCertificate();

            while ((pcert = GetNextCertificate()) != IntPtr.Zero) {
				addCertificate(pcert);
            }
        }

		private void addCertificate(IntPtr pcert) {
			var subject = GetCertificateSubject(pcert);
			var issuer = GetCertificateIssuer(pcert);
			var serialNumber = GetCertificateSerialNumber(pcert);
			var notAfter = GetCertificateNotAfter(pcert);

            Certificate cert = new() {
                SubjectName = Marshal.PtrToStringAuto(subject) ?? "",
                IssuerName = Marshal.PtrToStringAuto(issuer) ?? "",
                SerialNumber = Marshal.PtrToStringAuto(serialNumber) ?? "",
                NotAfter = Marshal.PtrToStringAuto(notAfter) ?? ""
            };

            Certificates.Add(cert);
		}

		#endregion
	}
}