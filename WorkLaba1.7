#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Набор русских и латинских гласных букв
const char vowels[] = {'A', 'E', 'I', 'O', 'U', 'Y',
                      'А', 'Е', 'Ё', 'И', 'О', 'У', 'Ы', 'Э', 'Ю', 'Я'};

// Функция проверки простого числа
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// Главная функция изменения регистра
char* transform_string(char* str) {
    int length = strlen(str);
    for (int pos = 1; pos <= length; pos++) {  // Положение в строке считаем с 1
        char ch = str[pos - 1];                 // Текущий символ
        
        bool is_vowel = false;
        for (int i = 0; vowels[i]; i++) {
            if (ch == vowels[i] || ch == vowels[i] + ('a'-'A')) {
                is_vowel = true;
                break;
            }
        }
        
        // Правило преобразования регистра
        if (pos % 2 == 0 && is_vowel) {      // Четная позиция, гласная буква
            str[pos - 1] = toupper(ch);
        } else if (is_prime(pos) && !is_vowel){ // Простая позиция, согласная буква
            str[pos - 1] = tolower(ch);
        }
    }
    return str;
}

// Основная функция для демонстрации работы
int main() {
    char input[100];  // Буфер для ввода строки длиной до 100 символов
    
    // Просим пользователя ввести слово
    printf("Введите слово: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\\n")] = '\\0';  // Убираем перенос строки

    // Выполняем преобразование и выводим результат
    char transformed[sizeof(input)];
    strcpy(transformed, input);  // Копируем исходную строку, чтобы сохранить оригинал
    transform_string(transformed);
    printf("Преобразованное слово: %s\\n", transformed);

    return 0;
}
