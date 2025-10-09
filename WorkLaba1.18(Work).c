#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include<locale.h>

// Устанавливаем степень точности для сравнения вещественных чисел
#define EPSILON 1e-6

// Функция для сравнения вещественных чисел с допуском
bool almost_equal(double a, double b) {
    return fabs(a - b) < EPSILON;
}

// Функция для удаления дубликатов из массива double
double* remove_duplicates(double src[], int length, int* new_length) {
    // Выделяем память под новый массив, предварительно резервируя столько же места
    double* unique_array = (double*)malloc(length * sizeof(double));
    if (!unique_array) {
        fprintf(stderr, "Ошибка выделения памяти!\n");
        exit(EXIT_FAILURE);
    }

    // Начнём заполнять уникальный массив
    int count_unique = 0;

    // Проходим по всему исходному массиву
    for (int i = 0; i < length; i++) {
        bool duplicate_found = false;
        // Проверяем, есть ли такой элемент уже в уникальном массиве
        for (int j = 0; j < count_unique; j++) {
            if (almost_equal(src[i], unique_array[j])) {
                duplicate_found = true;
                break;
            }
        }
        // Если элемент уникален, добавляем его в новый массив
        if (!duplicate_found) {
            unique_array[count_unique++] = src[i];
        }
    }

    // Установим новое количество элементов
    *new_length = count_unique;

    // Уменьшим объем выделенной памяти до нужного объема
    unique_array = realloc(unique_array, count_unique * sizeof(double));
    if (!unique_array) {
        fprintf(stderr, "Ошибка перераспределения памяти!\n");
        exit(EXIT_FAILURE);
    }

    return unique_array;
}

// Основная функция для демонстрации работы
int main() {
    setlocale(LC_ALL, "Rus");
    double source[] = { 1.1, 2.2, 3.3, 1.1, 4.4, 2.2, 5.5 ,1.1 ,3.3, 6.6, 3.3 };
    int length = sizeof(source) / sizeof(source[0]);

    int new_length;
    double* unique_array = remove_duplicates(source, length, &new_length);

    // Вывод оригинала
    printf("Оригинал: ");
    for (int i = 0; i < length; i++) {
        printf("%.1lf ", source[i]);
    }
    printf("\n");

    // Вывод массива без дубликатов
    printf("Без дубликатов: ");
    for (int i = 0; i < new_length; i++) {
        printf("%.1lf ", unique_array[i]);
    }
    printf("\n");

    // Освобождаем память
    free(unique_array);

    return 0;
}
