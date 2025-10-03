#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256

// Функция для чтения целого числа с проверкой валидности
long long valid_read_long(const char* prompt) {
    char input[MAX_INPUT_SIZE];
    while (1) {
        printf("%s\\n", prompt);
        fgets(input, sizeof(input), stdin);

        // Удаляем завершающий символ '\\n', оставшийся от fgets()
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\\n') {
            input[len - 1] = '\\0';
        }

        // Проверяем, что вся строка состоит только из цифр
        int has_digits = 0;
        for (size_t i = 0; i < len; ++i) {
            if (!isdigit(input[i]) || (input[i] == '-' && i != 0)) {
                fprintf(stderr, "Ошибка: введённые данные содержат недопустимые символы. Повторите попытку.\\n");
                continue;
            }
            has_digits = 1;
        }

        // Конвертируем строку в длинное целое число
        long long num = strtoll(input, NULL, 10);
        if (errno == ERANGE || num == LLONG_MIN || num == LLONG_MAX) {
            fprintf(stderr, "Ошибка: число выходит за диапазон допустимых значений. Повторите попытку.\\n");
            errno = 0;
            continue;
        }

        return num;
    }
}

// Быстрая функция возведения в степень
long long fast_pow(long long base, unsigned int exponent) {
    long long result = 1LL;
    while (exponent > 0) {
        if ((exponent & 1) != 0) { // Проверяем младший бит
            result *= base;
        }
        base *= base;               // Квадратируем базу
        exponent >>= 1;             // Двигаемся вправо на 1 разряд
    }
    return result;
}

int main() {
    long long base;
    unsigned int exponent;

    base = valid_read_long("Введите базовое число:");
    exponent = valid_read_long("Введите показатель степени:");

    long long result = fast_pow(base, exponent);
    printf("%lld ^ %u = %lld\\n", base, exponent, result);

    return 0;
}
