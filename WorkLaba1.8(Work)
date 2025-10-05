#include <stdio.h>
#include <string.h>
#include <locale.h>

// Функция для переворота строки in-place
void reverse_string(char* str) {
    int start = 0;
    int end = strlen(str) - 1;

    // Меняем местами символы, двигаясь навстречу друг другу
    while (start < end) {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
}

// Основная функция для демонстрации работы
int main() {
    char user_input[100];  // Буфер для строки пользователя (до 100 символов)

    // Просим пользователя ввести строку
    printf("Введите строку для переворота: ");
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\\n")] = '\\0';  // Удаляем символ перевода строки, если он есть

    printf("Исходная строка: %s\\n", user_input);
    reverse_string(user_input);                   // Переворачиваем строку
    printf("Обработанная строка: %s\\n", user_input);

    return 0;
}
