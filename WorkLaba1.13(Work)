#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include<locale.h>

// Максимальная длина строки для удобства
#define MAX_LENGTH 100

// Функция конвертирует строку в числе из базы base в десятичную систему
int convertToDecimal(const char* numberStr, int base) {
    // Проверьте корректность оснований
    if (base < 2 || base > 36) {
        printf("Ошибка: неверное основание (%d).\n", base);
        return INT_MIN; // Возвращаем минимальное возможное значение int
    }

    long result = 0; // Используем long для промежуточных вычислений
    size_t len = strlen(numberStr); // Длина строки

    // Перебираем каждый символ строки справа налево
    for (size_t i = 0; i < len; ++i) {
        char ch = tolower(numberStr[i]); // Приводим к нижнему регистру

        // Получаем цифровое значение символа
        int digit_value;
        if ('0' <= ch && ch <= '9') {
            digit_value = ch - '0';
        }
        else if ('a' <= ch && ch <= 'z') {
            digit_value = ch - 'a' + 10;
        }
        else {
            printf("Ошибка: Недопустимый символ '%c'.\n", ch);
            return INT_MIN;
        }

        // Проверяем, соответствует ли символ данному основанию
        if (digit_value >= base) {
            printf("Ошибка: символ '%c' вне допустимого диапазона.\n", ch);
            return INT_MIN;
        }

        // Формирование результата
        result *= base;
        result += digit_value;

        // Проверка переполнения
        if ((result >> 31) != 0) {
            printf("Ошибка: Результат превышает максимальное значение int.\n");
            return INT_MIN;
        }
    }

    return (int)result;
}

// Тестовая программа
int main() {
    setlocale(LC_ALL, "Russia");
    const char test_cases[][MAX_LENGTH] = { "10100110", "FF", "ZZ", "A1B" };
    int bases[] = { 2, 16, 36, 16 };

    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); ++i) {
        int decimalNumber = convertToDecimal(test_cases[i], bases[i]);
        if (decimalNumber != INT_MIN) {
            printf("%s в базе %d равно %d\n", test_cases[i], bases[i], decimalNumber);
        }
    }

    return 0;
}
