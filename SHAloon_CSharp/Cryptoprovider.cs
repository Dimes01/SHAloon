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
		private static extern IntPtr GetFirstCertificate();


        [DllImport(path_to_dll_cryptoprovider, CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr GetNextCertificate();

		#endregion
		#region Конструкторы

		public Cryptoprovider() {
			initShaloon();
			getAllCertificates();
		}

        #endregion
        #region Методы

		private void initShaloon() {
			InitShaloon();
		}

        private void getAllCertificates() {
			var ptr = GetFirstCertificate();
			if (ptr == IntPtr.Zero) return;


			if (Marshal.PtrToStructure<Certificate>(ptr) is not Certificate certificate) return;
			Certificates.Add(certificate);

            while ((ptr = GetNextCertificate()) != IntPtr.Zero) {
				if (Marshal.PtrToStructure<Certificate>(ptr) is not Certificate nextCertificate) return;
				Certificates.Add(nextCertificate);
            }
        }

		#endregion
	}
}