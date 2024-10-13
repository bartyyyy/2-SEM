#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fileA = NULL;
    FILE* fileB = NULL;
    char buffer[256];
    int num;

    if (fopen_s(&fileA, "fileA.txt", "r") != 0 || fileA == NULL) {
        printf("Ошибка открытия файла fileA\n");
        return 1;
    }

    if (fopen_s(&fileB, "fileB.txt", "w") != 0 || fileB == NULL) {
        printf("Ошибка открытия файла fileB\n");
        if (fileA) fclose(fileA);
        return 1;
    }

    while (fgets(buffer, 256, fileA) != NULL) {
        num = atoi(buffer);
        if (num > 0) {
            fprintf(fileB, "%d\n", num);
        }
    }

    printf("Файл fileB успешно создан\n");

    if (fileA) fclose(fileA);
    if (fileB) fclose(fileB);

    return 0;
}