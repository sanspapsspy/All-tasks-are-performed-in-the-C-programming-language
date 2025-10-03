#include <stdio.h>
#include <string.h>
#include <assert.h>

// Константа для максимальной длины строки результата
#define MAX_STR_LEN 64

// Функция преобразования числа в произвольную систему счисления
char* convert_to_base(int num, int base) {
    assert(base >= 2 && base <= 36);  // Проверка допустимости основания

    static char result[MAX_STR_LEN];  // Резервируем статическое хранилище для строки
    int index = 0;

    do {
        int remainder = abs(num % base);  // Берём абсолютное значение остатка
        if (remainder < 10) {
            result[index++] = '0' + remainder;  // Для цифр от 0 до 9
        } else {
            result[index++] = 'A' + (remainder - 10);  // Буквы от A до Z для чисел от 10 до 35
        }
        num /= base;  // Следующая итерация деления
    } while (num != 0);

    // Если число отрицательное, ставим минус впереди
    if (num < 0) {
        result[index++] = '-';
    }

    // Добавляем завершающий символ строки
    result[index] = '\\0';

    // Переворачиваем строку, так как цифры идут в обратном порядке
    for (int i = 0, j = index - 1; i < j; i++, j--) {
        char tmp = result[i];
        result[i] = result[j];
        result[j] = tmp;
    }

    return result;
}

// Тестовая функция для демонстрации работы
int main() {
    int number;
    int base;

    // Запрашиваем у пользователя число и основание системы счисления
    printf("Введите целое число: ");
    scanf("%d", &number);

    printf("Введите основание системы счисления (от 2 до 36): ");
    scanf("%d", &base);

    // Проверьте, что база находится в пределах от 2 до 36
    if (base < 2 || base > 36) {
        printf("Недопустимая система счисления.\\n");
        return 1;
    }

    // Преобразуем число и выводим результат
    char* converted = convert_to_base(number, base);
    printf("Представление числа %d в системе счисления с основанием %d: %s\\n", number, base, converted);

    return 0;
}
