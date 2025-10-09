#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>

// Вспомогательная функция сравнения целых чисел
int compare_int(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Функция сортировки пузырьком
void bubble_sort(void* arr, size_t nitems, size_t size,
    int (*compar)(const void*, const void*)) {
    unsigned char* p = arr;
    for (size_t i = 0; i < nitems - 1; i++) {
        for (size_t j = 0; j < nitems - i - 1; j++) {
            if (compar(p + j * size, p + (j + 1) * size) > 0) {
                void* temp = malloc(size);
                memcpy(temp, p + j * size, size);
                memcpy(p + j * size, p + (j + 1) * size, size);
                memcpy(p + (j + 1) * size, temp, size);
                free(temp);
            }
        }
    }
}

// Функция сортировки выбором
void selection_sort(void* arr, size_t nitems, size_t size,
    int (*compar)(const void*, const void*)) {
    unsigned char* p = arr;
    for (size_t i = 0; i < nitems - 1; i++) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < nitems; j++) {
            if (compar(p + j * size, p + min_idx * size) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            void* temp = malloc(size);
            memcpy(temp, p + i * size, size);
            memcpy(p + i * size, p + min_idx * size, size);
            memcpy(p + min_idx * size, temp, size);
            free(temp);
        }
    }
}

// Функция сортировки вставками
void insertion_sort(void* arr, size_t nitems, size_t size,
    int (*compar)(const void*, const void*)) {
    unsigned char* p = arr;
    for (size_t i = 1; i < nitems; i++) {
        void* key = malloc(size);
        memcpy(key, p + i * size, size);
        size_t j = i - 1;
        while (j >= 0 && compar(p + j * size, key) > 0) {
            memcpy(p + (j + 1) * size, p + j * size, size);
            j--;
        }
        memcpy(p + (j + 1) * size, key, size);
        free(key);
    }
}

// Вспомогательная функция перестройки кучи
static void heapify(void* arr, size_t idx, size_t size, size_t nitems,
    int (*compar)(const void*, const void*)) {
    unsigned char* p = arr;
    size_t largest = idx;
    size_t left = 2 * idx + 1;
    size_t right = 2 * idx + 2;

    if (left < nitems &&
        compar(p + left * size, p + largest * size) > 0) {
        largest = left;
    }

    if (right < nitems &&
        compar(p + right * size, p + largest * size) > 0) {
        largest = right;
    }

    if (largest != idx) {
        void* temp = malloc(size);
        memcpy(temp, p + idx * size, size);
        memcpy(p + idx * size, p + largest * size, size);
        memcpy(p + largest * size, temp, size);
        free(temp);
        heapify(arr, largest, size, nitems, compar);
    }
}

// Функция пирамидальной сортировки
void heap_sort(void* arr, size_t nitems, size_t size,
    int (*compar)(const void*, const void*)) {
    unsigned char* p = arr;
    // Строим кучу (heapify)
    for (size_t i = nitems / 2 - 1; i >= 0; i--) {
        heapify(arr, i, size, nitems, compar);
    }

    // Извлекаем элементы из кучи
    for (size_t i = nitems - 1; i > 0; i--) {
        void* temp = malloc(size);
        memcpy(temp, p, size);
        memcpy(p, p + i * size, size);
        memcpy(p + i * size, temp, size);
        free(temp);
        heapify(arr, 0, size, i, compar);
    }
}

// Главная функция для демонстрации работы сортировок
int main() {
    setlocale(LC_ALL, "Rus");
    int array[] = { 5, 2, 9, 1, 5, 6 }; // Исходный массив
    size_t n = sizeof(array) / sizeof(array[0]); // Число элементов

    // Печать исходного массива
    printf("Исходный массив:\n");
    for (size_t i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    // Бубликовая сортировка
    bubble_sort(array, n, sizeof(int), compare_int);
    printf("Отсортированный массив (Bubble Sort):\n");
    for (size_t i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    // Восстанавливаем исходный порядок
    memcpy(array, (int[]) { 5, 2, 9, 1, 5, 6 }, sizeof(array));

    // Сортировка выбором
    selection_sort(array, n, sizeof(int), compare_int);
    printf("Отсортированный массив (Selection Sort):\n");
    for (size_t i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    // Восстанавливаем исходный порядок
    memcpy(array, (int[]) { 5, 2, 9, 1, 5, 6 }, sizeof(array));

    // Сортировка вставками
    insertion_sort(array, n, sizeof(int), compare_int);
    printf("Отсортированный массив (Insertion Sort):\n");
    for (size_t i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    // Восстанавливаем исходный порядок
    memcpy(array, (int[]) { 5, 2, 9, 1, 5, 6 }, sizeof(array));

    // Пирамидальная сортировка
    heap_sort(array, n, sizeof(int), compare_int);
    printf("Отсортированный массив (Heap Sort):\n");
    for (size_t i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}
