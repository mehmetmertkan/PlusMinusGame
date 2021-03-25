# PlusMinusGame
Derleme
Seçenek 1) Visual studio üzerinden solution dosyası açılıp build denerek derlenir.
Seçenek 2) Proje dizininde bir command prompt açtıktan sonra g++ main.cpp Game.cpp Number.cpp PlusMinus.cpp komutu ile derlenir.

Çalıştırma
Derleme sonucu bir exe dosyası çıkacaktır. 
Dosyaya çift tıklanarak çalıştırılır. 
Açıldığında debug veya release seçimi yapılır. 
Debug modunda bilgisayarın seçtiği sayı en üstte görülür. Release modunda gizlidir. 
Seçimi yaptıktan sonra bilgisayar ilk tahminini yapar. 
Kullanıcı tırnaklar olmayacak şekilde "+p -m" şeklinde bir cevap döner.
Önce plusSign sayısı sonra minusSign sayısı girilmelidir 
(Örnekler "+2 -1", "0 -2").
Daha sonra kullanıcı bir tahmin yapar (Örnek "1024", "2045").
Buna göre bilgisayar bunun sonucundaki + - sayılarını döner. 
İlk +4 0 yapan oyunu kazanmış olur.
