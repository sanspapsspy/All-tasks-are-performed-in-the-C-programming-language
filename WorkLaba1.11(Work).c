#include <stdio.h>
#include<locale.h>

// Реализация функции сравнения строк, аналогично стандартной strcmp
int my_strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) { // идём, пока оба символа равны и не достигли конца строки
        str1++; // двигаемся вперёд по первой строке
        str2++; // двигаемся вперёд по второй строке
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2; // возвращаем разницу первых различающихся символов
}

int main() {
    setlocale(LC_ALL, "Russian");
    char string1[] = "яблоко";
    char string2[] = "Код";
    char string3[] = "Существо";
    char string4[] = "Сработало";
    char string5[] = "Проверка";
    char string6[] = "Живой";

    int result;

    // Сравним разные строки
    result = my_strcmp(string1, string2); // сравниваем "яблоко" и "абрикос"
    if (result > 0) {
        printf("\"%s\" больше \"%s\"\n", string1, string2);
    }
    else if (result < 0) {
        printf("\"%s\" меньше \"%s\"\n", string1, string2);
    }
    else {
        printf("\"%s\" равно \"%s\"\n", string1, string2);
    }

    result = my_strcmp(string2, string3);
    if (result > 0) {
        printf("\"%s\" больше \"%s\"\n", string2, string3);
    }
    else if (result < 0) {
        printf("\"%s\" меньше \"%s\"\n", string2, string3);
    }
    else {
        printf("\"%s\" равно \"%s\"\n", string2, string3);
    }

    result = my_strcmp(string4, string5);
    if (result > 0) {
        printf("\"%s\" больше \"%s\"\n", string4, string5);
    }
    else if (result < 0) {
        printf("\"%s\" меньше \"%s\"\n", string4, string5);
    }
    else {
        printf("\"%s\" равно \"%s\"\n", string4, string5);
    }

    result = my_strcmp(string5, string6);
    if (result > 0) {
        printf("\"%s\" больше \"%s\"\n", string5, string6);
    }
    else if (result < 0) {
        printf("\"%s\" меньше \"%s\"\n", string5, string6);
    }
    else {
        printf("\"%s\" равно \"%s\"\n", string5, string6);
    }

    return 0;
}
