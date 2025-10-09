#include <stdio.h>
#include <stdlib.h>

// Тип матрицы
typedef struct Matrix {
    int rows;     // Количество строк
    int cols;     // Количество столбцов
    double **data; // Динамический массив указателей на строки
} Matrix;

// Функция инициализации матрицы
Matrix create_matrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double **)malloc(rows * sizeof(double *)); // выделение памяти для строк
    for (int i = 0; i < rows; i++) {
        m.data[i] = (double *)malloc(cols * sizeof(double)); // выделение памяти для каждого столбца
    }
    return m;
}

// Функция освобождения памяти матрицы
void destroy_matrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        free(m.data[i]); // освобождение памяти каждого столбца
    }
    free(m.data); // освобождение памяти строк
}

// Функция печати матрицы
void print_matrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%6.2f ", m.data[i][j]);
        }
        printf("\n");
    }
}

// Функция сложения матриц
Matrix add_matrices(Matrix mat1, Matrix mat2) {
    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        printf("Размеры матриц не совпадают! Невозможно сложить.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = create_matrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }
    return result;
}

// Функция умножения матриц
Matrix multiply_matrices(Matrix mat1, Matrix mat2) {
    if (mat1.cols != mat2.rows) {
        printf("Количество столбцов первой матрицы не совпадает с количеством строк второй! Невозможно умножить.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = create_matrix(mat1.rows, mat2.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            result.data[i][j] = 0.0;
            for (int k = 0; k < mat1.cols; k++) {
                result.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
        }
    }
    return result;
}

// Основная функция для демонстрации работы
int main() {
    // Заданные матрицы
    Matrix mat1 = create_matrix(2, 3);
    mat1.data[0][0] = 1.0; mat1.data[0][1] = 2.0; mat1.data[0][2] = 3.0;
    mat1.data[1][0] = 4.0; mat1.data[1][1] = 5.0; mat1.data[1][2] = 6.0;

    Matrix mat2 = create_matrix(2, 3);
    mat2.data[0][0] = 7.0; mat2.data[0][1] = 8.0; mat2.data[0][2] = 9.0;
    mat2.data[1][0] = 10.0; mat2.data[1][1] = 11.0; mat2.data[1][2] = 12.0;

    // 1. Сложение матриц
    Matrix result_add = add_matrices(mat1, mat2);
    printf("Сложение матриц:\n");
    print_matrix(result_add);
    destroy_matrix(result_add);

    // 2. Умножение матриц
    Matrix mat3 = create_matrix(3, 2);
    mat3.data[0][0] = 1.0; mat3.data[0][1] = 2.0;
    mat3.data[1][0] = 3.0; mat3.data[1][1] = 4.0;
    mat3.data[2][0] = 5.0; mat3.data[2][1] = 6.0;

    Matrix mat4 = create_matrix(2, 3);
    mat4.data[0][0] = 7.0; mat4.data[0][1] = 8.0; mat4.data[0][2] = 9.0;
    mat4.data[1][0] = 10.0; mat4.data[1][1] = 11.0; mat4.data[1][2] = 12.0;

    Matrix result_mul = multiply_matrices(mat3, mat4);
    printf("\nУмножение матриц:\n");
    print_matrix(result_mul);
    destroy_matrix(result_mul);

    // Освобождение памяти исходных матриц
    destroy_matrix(mat1);
    destroy_matrix(mat2);
    destroy_matrix(mat3);
    destroy_matrix(mat4);

    return 0;
}
