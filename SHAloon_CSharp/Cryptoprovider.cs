using System.Collections.ObjectModel;
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
		private static extern IntPtr GetFirstCertificate();


        [DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr GetLNextCertificate();

		#endregion
		#region Конструкторы

		public Cryptoprovider() {
			getAllCertificates();
		}

        #endregion
        #region Методы

        private void getAllCertificates() {
			var certificate = (Certificate)Marshal.PtrToStructure(GetFirstCertificate(), typeof(Certificate));
			if (certificate == null) return;
			Certificates.Add(certificate);
            while (certificate != null) {
                certificate = (Certificate)Marshal.PtrToStructure(GetLNextCertificate(), typeof(Certificate));
				Certificates.Add(certificate);
            }
        }

		#endregion
	}
}