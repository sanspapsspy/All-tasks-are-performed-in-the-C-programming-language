#include <stdio.h>

int is_triangle(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int is_right_triangle(int a, int b, int c) {
    return (a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a);
}

int is_arithmetic_progression(int a, int b, int c) {
    return (b - a) == (c - b);
}

int is_geometric_progression(int a, int b, int c) {
    return (b != 0 && c != 0) && (b * b == a * c);
}

int is_fibonacci(int n) {
    int a = 0, b = 1, temp;
    while (b < n) {
        temp = b;
        b += a;
        a = temp;
    }
    return b == n;
}

int are_consecutive_fibonacci(int a, int b, int c) {
    return (is_fibonacci(a) && is_fibonacci(b) && is_fibonacci(c) &&
        ((b == a + 1 && c == b + 1) || (c == a + 2 && b == a + 1)));
}

int main() {
    int a, b, c;

    printf("Введите три целых неотрицательных числа: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3 || a < 0 || b < 0 || c < 0) {
        printf("Ошибка ввода. Пожалуйста, введите три неотрицательных целых числа.\n");
        return 1;
    }

    printf("Стороны треугольника: %s\n", is_triangle(a, b, c) ? "Да" : "Нет");
    printf("Стороны прямоугольного треугольника: %s\n", is_right_triangle(a, b, c) ? "Да" : "Нет");
    printf("Элементы арифметической прогрессии: %s\n", is_arithmetic_progression(a, b, c) ? "Да" : "Нет");
    printf("Элементы геометрической прогрессии: %s\n", is_geometric_progression(a, b, c) ? "Да" : "Нет");
    printf("Элементы последовательности Фибоначчи: %s\n", is_fibonacci(a) && is_fibonacci(b) && is_fibonacci(c) ? "Да" : "Нет");
    printf("Подряд идущие элементы последовательности Фибоначчи: %s\n", are_consecutive_fibonacci(a, b, c) ? "Да" : "Нет");

    return 0;
}
