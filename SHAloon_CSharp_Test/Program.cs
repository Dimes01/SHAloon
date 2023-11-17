using SHAloon_CSharp;

Cryptoprovider cryptoprovider = new();
IList<Certificate> certificates = cryptoprovider.Certificates;

Console.WriteLine($"Length of certificates: {certificates.Count}");

if (certificates.Count == 0) {
    Console.WriteLine("No certificates found!");
    return;
}

for (int i = 0; i < certificates.Count; i++) {
    Console.WriteLine($"Сертификат #{i}:");
    Console.WriteLine($"Владелец: {certificates[i].SubjectName}");
    Console.WriteLine($"Издатель: {certificates[i].IssuerName}");
    Console.WriteLine($"Серийный номер: {certificates[i].SerialNumber}");
    Console.WriteLine($"Использование до: {certificates[i].NotAfter}");
    Console.WriteLine();
}

// Если захочется потестить, поменять названия на свои

//string file = @"C:/Users/CryptoProUser/Desktop/Folder/ForSign.txt";
//string signature = @"C:/Users/CryptoProUser/Desktop/Folder/Signature.p7s";

//IntPtr certPtr = cryptoprovider.VerifySignature(file, signature);

//if (certPtr != IntPtr.Zero) {
//    Certificate cert = Certificate.FromCppPtr(certPtr)!;
//    Console.WriteLine("Подпись успешно проверена.");
//    Console.WriteLine($"Владелец: {cert.SubjectName}");
//    Console.WriteLine($"Издатель: {cert.IssuerName}");
//    Console.WriteLine($"Серийный номер: {cert.SerialNumber}");
//    Console.WriteLine($"Использование до: {cert.NotAfter}");
//    Console.WriteLine();
//}

cryptoprovider.Dispose();