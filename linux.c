#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

int getch(void) {
    struct termios oldt, newt;
    int ch;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int main() {
    char filePath[260];
    FILE *file;
    int ch;

    printf("Lütfen bir .txt dosyasının tam yolunu girin: ");
    scanf("%259s", filePath);

    // Dosyayı açmayı deniyoruz
    file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Dosya açılamadı. Lütfen doğru bir yol girin.\n");
        return 1;
    }

    printf("Dosya basariyla acildi. Klavyeden herhangi bir tusa basarak dosyanin icerigini yazdirabilirsiniz.\n");
    printf("ESC tusuna basarsaniz program kapanir.\n");

    while ((ch = fgetc(file)) != EOF) {
        // Tuş bekleme
        int key = getch();
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
