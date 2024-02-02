#include <iostream>
#include <iomanip>  // Для управления выводом чисел с плавающей точкой
#include <limits>   // Для ограничения ввода

// Шаблон функции для ввода матрицы
template <typename T>
void inputMatrix(T matrix[][6], int rows, int cols) {
    std::cout << "Введите элементы матрицы " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

// Шаблон функции для вывода матрицы
template <typename T>
void printMatrix(const T matrix[][6], int rows, int cols) {
    std::cout << "Матрица " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Шаблон функции для формирования массива из минимальных элементов столбцов
template <typename T>
void minElementsArray(const T matrix[][6], int rows, int cols, T resultArray[]) {
    for (int j = 0; j < cols; ++j) {
        T minElement = matrix[0][j];
        for (int i = 1; i < rows; ++i) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
            }
        }
        resultArray[j] = minElement;
    }
}

// Функция для вывода массива целых чисел
void printIntArray(const int arr[], int size) {
    std::cout << "Массив из минимальных элементов столбцов:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Функция для вывода массива вещественных чисел
void printDoubleArray(const double arr[], int size) {
    std::cout << "Массив из минимальных элементов столбцов:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << std::fixed << std::setprecision(2) << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int rowsA = 6, colsA = 6;
    const int rowsB = 4, colsB = 4;

    // Матрицы
    int matrixA[rowsA][6];
    double matrixB[rowsB][6];

    // Ввод матриц
    inputMatrix(matrixA, rowsA, colsA);
    inputMatrix(matrixB, rowsB, colsB);

    // Вывод матриц
    printMatrix(matrixA, rowsA, colsA);
    printMatrix(matrixB, rowsB, colsB);

    // Массивы минимальных элементов столбцов
    int resultArrayA[colsA];
    double resultArrayB[colsB];

    // Вызов функции для формирования массива из минимальных элементов столбцов
    minElementsArray(matrixA, rowsA, colsA, resultArrayA);
    minElementsArray(matrixB, rowsB, colsB, resultArrayB);

    // Вывод массивов
    printIntArray(resultArrayA, colsA);
    printDoubleArray(resultArrayB, colsB);

    return 0;
}