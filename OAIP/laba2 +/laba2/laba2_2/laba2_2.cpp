#include <stdio.h>

int main() {
    FILE* fileF, * fileG;
    int number, threshold;

    errno_t err = fopen_s(&fileF, "f.txt", "r");
    if (err != 0 || fileF == NULL) {
        printf("Ошибка открытия файла f.txt\n");
        return 1;
    }

    err = fopen_s(&fileG, "g.txt", "w");
    if (err != 0 || fileG == NULL) {
        printf("Ошибка открытия файла g.txt\n");
        fclose(fileF);
        return 1;
    }

    printf("Введите пороговое число: ");
    scanf_s("%d", &threshold);

    while (fscanf_s(fileF, "%d", &number) == 1) {
        if (number > threshold) {
            fprintf(fileG, "%d\n", number);
        }
    }

    fclose(fileF);
    fclose(fileG);

    printf("Файл g.txt успешно создан\n");

    return 0;
}