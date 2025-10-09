#include <stdio.h>
#include <string.h>
#include<locale.h>

// Функция конкатенации двух строк (аналог стандартной функции strcat)
char* my_strcat(char* dest, const char* src) {
    // Перемещаемся в конец первой строки
    while (*dest != '\0') dest++;

    // Копируем символы второй строки в конец первой
    while ((*dest++ = *src++) != '\0');

    return dest;
}

int main() {
    setlocale(LC_ALL, "Russian");
    char str1[100] = "Оно";
    char str2[] = ", Живое, ура!";

    printf("До слияния:\n");
    printf("Строка 1: %s\n", str1);
    printf("Строка 2: %s\n", str2);

    // Используем нашу собственную реализацию функции strcat
    my_strcat(str1, str2);

    printf("\nПосле слияния:\n");
    printf("Итоговая строка: %s\n", str1);

    return 0;
}
