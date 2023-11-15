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
