#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<locale.h>

// Максимальный размер массива
#define MAX_SIZE 128

// Функция для проверки простоты числа
int is_prime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

// Функция для расчёта среднего арифметического
double arithmetic_mean(int arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Функция для расчета среднего геометрического
double geometric_mean(int arr[], int n) {
    double product = 1.0;
    for (int i = 0; i < n; i++) {
        product *= arr[i];
    }
    return pow(product, 1.0 / n);
}

// Функция для расчета среднего гармонического
double harmonic_mean(int arr[], int n) {
    double sum_reciprocals = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            sum_reciprocals += 1.0 / arr[i];
        }
    }
    return n / sum_reciprocals;
}

// Функция для нахождения размаха массива
int range_of_elements(int arr[], int n) {
    int max_val = arr[0], min_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) max_val = arr[i];
        if (arr[i] < min_val) min_val = arr[i];
    }
    return max_val - min_val;
}

// Функция для подсчета разницы сумм простых и четных положительных элементов
int difference_sum_primes_and_even_positive(int arr[], int n) {
    int prime_sum = 0, even_pos_sum = 0;
    for (int i = 0; i < n; i++) {
        if (is_prime(arr[i])) prime_sum += arr[i];
        if ((arr[i] > 0) && (arr[i] % 2 == 0)) even_pos_sum += arr[i];
    }
    return prime_sum - even_pos_sum;
}

// Основная функция
int main() {
    setlocale(LC_ALL, "Rus");
    FILE* file = fopen("input.txt", "r");  // Открываем файл для чтения
    if (file == NULL) {
        perror("Ошибка открытия файла!");
        return EXIT_FAILURE;
    }

    int data[MAX_SIZE];  // Массив для считанных данных
    int cnt = 0;         // Счётчик прочитанных элементов

    // Читаем целые числа из файла
    while (cnt < MAX_SIZE && fscanf(file, "%d", &data[cnt]) == 1) {
        cnt++;           // Увеличим счётчик количества элементов
    }

    fclose(file);  // Закрываем файл

    // a) Новый массив с числами на простых индексах
    int primes_data[MAX_SIZE], primes_cnt = 0;
    for (int i = 0; i < cnt; i++) {
        if (is_prime(i)) {
            primes_data[primes_cnt++] = data[i];
        }
    }

    // b) Новый массив с нечётными числами
    int odd_numbers[MAX_SIZE], odd_cnt = 0;
    for (int i = 0; i < cnt; i++) {
        if (data[i] % 2 != 0) {
            odd_numbers[odd_cnt++] = data[i];
        }
    }

    // c) Среднее арифметическое
    double arith_mean = arithmetic_mean(data, cnt);

    // d) Среднее геометрическое
    double geom_mean = geometric_mean(data, cnt);

    // e) Среднее гармоническое
    double harm_mean = harmonic_mean(data, cnt);

    // f) Размах массива
    int range = range_of_elements(data, cnt);

    // g) Разность сумм простых и четных положительных элементов
    int diff_sum = difference_sum_primes_and_even_positive(data, cnt);

    // Вывод результатов
    printf("Исходный массив: ");
    for (int i = 0; i < cnt; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    printf("Числа на простых позициях: ");
    for (int i = 0; i < primes_cnt; i++) {
        printf("%d ", primes_data[i]);
    }
    printf("\n");

    printf("Нечётные числа: ");
    for (int i = 0; i < odd_cnt; i++) {
        printf("%d ", odd_numbers[i]);
    }
    printf("\n");

    printf("Среднее арифметическое: %.2f\n", arith_mean);
    printf("Среднее геометрическое: %.2f\n", geom_mean);
    printf("Среднее гармоническое: %.2f\n", harm_mean);
    printf("Размах элементов: %d\n", range);
    printf("Разность сумм простых и четных положительных элементов: %d\n", diff_sum);

    return 0;
}
