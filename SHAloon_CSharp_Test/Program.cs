using SHAloon_CSharp;

Cryptoprovider cryptoprovider = new();
IList<Certificate> certificates = cryptoprovider.Certificates;

if (certificates.Count == 0) {
    Console.WriteLine("No certificates found!");
    return;
}

Console.WriteLine($"Владелец: {certificates[0].Subject}");
Console.WriteLine($"Ключ: {certificates[0].PublicKey}");