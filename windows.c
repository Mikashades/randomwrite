#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    char filePath[260];
    FILE *file;
    int ch;
    
    printf("Lütfen bir .txt dosyasının tam yolunu girin: ");
    scanf("%259s", filePath);

    file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Dosya açılamadı. Lütfen doğru bir yol girin.\n");
        return 1;
    }

    printf("Dosya basariyla acildi. Klavyeden herhangi bir tusa basarak dosyanin icerigini yazdirabilirsiniz.\n");
    printf("ESC tusuna basarsaniz program kapanir.\n");
  
    while ((ch = fgetc(file)) != EOF) {
        int key = _getch();
        if (key == 27) {
            printf("\nProgram kapatiliyor...\n");
            fclose(file);
            return 0;
        }
        printf("%c", ch);
    }

    printf("\nDosyanin sonuna ulasildi. Program kapanıyor...\n");
    fclose(file);
    return 0;
}
