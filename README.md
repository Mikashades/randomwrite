# randomwrite

Klavyeden girilen rastgele tuşlarla istediğiniz herhangi bir yazıyı yazmanızı sağlayan bir program

# Kullanım

İlk olarak kullandığınız bilgisayara göre windows.c veya mac_linux.c dosyalarından birini indirin ardından kod içerisinde belirtilmiş olan yere istediğiniz yazıyı barındıran .txt dosyasının yolunu girin.
Ardından **Derleme ve Çalıştırma** kısmını okuyarak nasıl çalıştıracağınızı öğrenip çalıştırın. Kodu çalıştırdığınızda .txt dosyası içerisinde ki yazı bittiğinde program otomatik olarak duracaktır.
Programı durdurmak için `ESC` tuşunu kullanın. `ESC` tuşu dışında ki tüm tuşlar yazı yazmaya devam eder, fakat `ESC` tuşu programı durdurur.

# Derleme ve Çalıştırma

## Linux ve MacOS

Derleme

    gcc -o mac_linux mac_linux.c

Çalıştırma

    ./mac_linux

## Windows

MinGW'yi yükleyin (yükleme sırasında **gcc** derleyicisini seçin)
Yüklendikten sonra MinGW terminalini açın ve

    gcc -o windows windows.c

komutunu kullanın ardından çalıştırmak içinde

    ./windows

komutunu kullanın.
