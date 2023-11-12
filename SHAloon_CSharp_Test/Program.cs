using SHAloon_CSharp;

Cryptoprovider cryptoprovider = new Cryptoprovider();
IList<Certificate> certificates = cryptoprovider.Certificates;
Console.WriteLine($"Владелец: {certificates[0].Subject}");
Console.WriteLine($"Ключ: {certificates[0].PublicKey}");