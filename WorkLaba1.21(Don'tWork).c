#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>

// Определение максимального размера матрицы
#define MAX_SIZE 100

// Структура для хранения матрицы
struct Matrix {
    int rows;
    int cols;
    int elements[MAX_SIZE][MAX_SIZE];
};

// Чтение матрицы из файла
void read_matrix_from_file(struct Matrix* matrix, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Ошибка открытия файла!\n");
        exit(EXIT_FAILURE);
    }

    int row = 0, col = 0;
    char line[MAX_SIZE * 10]; // Допускаем большие строки

    // Считывание строк файла
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, " \t\n\r\f\v"); // Разделение строки по пробелам и табуляциям
        while (token) {
            matrix->elements[row][col++] = atoi(token);
            token = strtok(NULL, " \t\n\r\f\v");
        }
        row++;
        col = 0;
    }

    matrix->rows = row;
    matrix->cols = col;

    fclose(file);
}

// Метод Гаусса-Жордана для вычисления ранга матрицы
int calculate_rank(struct Matrix* matrix) {
    int rank = 0;
    int lead = 0;
    int rows = matrix->rows;
    int cols = matrix->cols;

    for (int r = 0; r < rows; r++) {
        if (lead >= cols) break;
        int i = r;
        while (matrix->elements[i][lead] == 0) {
            i++;
            if (i == rows) {
                i = r;
                lead++;
                if (cols == lead) return rank;
            }
        }

        // Меняем строки, если нужно
        if (i != r) {
            for (int j = 0; j < cols; j++) {
                int temp = matrix->elements[r][j];
                matrix->elements[r][j] = matrix->elements[i][j];
                matrix->elements[i][j] = temp;
            }
        }

        // Нулевые строки пропускаем
        if (matrix->elements[r][lead] == 0) continue;

        // Нормализуем ведущую строку
        int pivot = matrix->elements[r][lead];
        for (int j = lead; j < cols; j++) {
            matrix->elements[r][j] /= pivot;
        }

        // Удаляем другие ненулевые коэффициенты в колонке
        for (int i = 0; i < rows; i++) {
            if (i != r) {
                int factor = matrix->elements[i][lead];
                for (int j = lead; j < cols; j++) {
                    matrix->elements[i][j] -= factor * matrix->elements[r][j];
                }
            }
        }

        lead++;
        rank++;
    }

    return rank;
}

// Нахождение седловых точек
void find_saddle_points(struct Matrix* matrix) {
    int rows = matrix->rows;
    int cols = matrix->cols;

    for (int i = 0; i < rows; i++) {
        int min_in_row = matrix->elements[i][0];
        int min_col = 0;
        for (int j = 1; j < cols; j++) {
            if (matrix->elements[i][j] < min_in_row) {
                min_in_row = matrix->elements[i][j];
                min_col = j;
            }
        }

        // Проверяем, является ли минимальный элемент строки максимальным в своем столбце
        int max_in_column = 1;
        for (int k = 0; k < rows; k++) {
            if (matrix->elements[k][min_col] > min_in_row) {
                max_in_column = 0;
                break;
            }
        }

        if (max_in_column) {
            printf("Седловая точка: [%d,%d]: %d\n", i, min_col, min_in_row);
        }
    }
}

// Вычисление следа матрицы
int trace_of_matrix(struct Matrix* matrix) {
    if (matrix->rows != matrix->cols) {
        printf("Ошибка: Матрица не квадратная. След невозможно вычислить.\n");
        return -1;
    }

    int trace = 0;
    for (int i = 0; i < matrix->rows; i++) {
        trace += matrix->elements[i][i];
    }
    return trace;
}

// Основная функция
int main() {
    setlocale(LC_ALL, "Rus");
    struct Matrix matrix;
    read_matrix_from_file(&matrix, "matrix.txt");

    // a) Ранг матрицы
    int rank = calculate_rank(&matrix);
    printf("Ранг матрицы: %d\n", rank);

    // b) Седловые точки
    printf("Седловые точки:\n");
    find_saddle_points(&matrix);

    // c) След матрицы
    int trace = trace_of_matrix(&matrix);
    if (trace != -1) {
        printf("След матрицы: %d\n", trace);
    }

    return 0;
}
