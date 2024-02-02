#include <iostream>

void inputArray(int arr[], int size) {
    std::cout << "input array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "arr[" << i << "]: ";
        std::cin >> arr[i];
    }
}

void printArray(const int arr[], int size) {
    std::cout << "array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int sumPositiveEvenIndices(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i += 2) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    const int arraySize = 6;
    int array1[arraySize];
    int array2[arraySize];

    inputArray(array1, arraySize);
    inputArray(array2, arraySize);

    printArray(array1, arraySize);
    printArray(array2, arraySize);

    int sum1 = sumPositiveEvenIndices(array1, arraySize);
    int sum2 = sumPositiveEvenIndices(array2, arraySize);

    std::cout << "sum1: " << sum1 << std::endl;
    std::cout << "sum2: " << sum2 << std::endl;

    return 0;
}