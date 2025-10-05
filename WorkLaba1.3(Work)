#include <stdio.h>

// Функция возведения числа a в степень b
double power(double a, int b) {
    double result = 1.0;
    for(int i = 0; i < b; ++i)
        result *= a;
    return result;
}

void print_power_table() {
    // Таблица степеней от 1 до 6 чисел, степени от 1 до 10
    printf("Основание\\t");
    for(int j = 1; j <= 10; ++j)
        printf("| Степень %d\\t", j);
    printf("\\n");
    
    for(int base = 1; base <= 6; ++base) {   // Основания от 1 до 6
        printf("%d\\t\\t", base);              // Столбец с основанием
        
        for(int exp = 1; exp <= 10; ++exp) { // Строки с результатами возведения в степень
            printf("| %.0f\\t", power(base, exp));
        }
        printf("\\n");                        // Переход на новую строку
    }
}

int main() {
    print_power_table();
    return 0;
}
