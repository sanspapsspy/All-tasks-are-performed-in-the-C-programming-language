#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include<locale.h>

// Функция проверки строки на палиндром
bool isPalindrome(const char* str) {
    int left = 0;              // Левый индекс
    int right = strlen(str) - 1; // Правый индекс

    while (left < right) {
        if (str[left++] != str[right--]) {
            return false;       // Если нашли разные символы, возвращаем false
        }
    }
    return true;               // Все символы совпадают, строка — палиндром
}

// Основная демонстрационная функция
int main() {
    setlocale(LC_ALL, "Rus");
    char testStrings[][50] = { "racecar", "hello", "madam", "abba", "world", "Work!!", "YEpy"};

    for (int i = 0; i < sizeof(testStrings) / sizeof(testStrings[0]); i++) {
        bool result = isPalindrome(testStrings[i]);
        printf("\"%s\" %s палиндромом.\n",
            testStrings[i],
            result ? "является" : "не является");
    }

    return 0;
}
