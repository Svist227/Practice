#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Функция генерации массива случайных чисел
void generateRandomArray(int* arr, int size, int minVal = 0, int maxVal = 100) {
    for (int i = 0; i < size; ++i) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

// Функция вывода массива
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция фильтрации массива с использованием указателей
void filterArray(const int* source, int size, char sign, int*& result, int& resultSize) {
    // 1. Вычисление среднего арифметического
    double avg = 0;
    for (int i = 0; i < size; ++i) {
        avg += source[i];
    }
    avg /= size;

    // 2. Подсчёт подходящих элементов
    resultSize = 0;
    for (int i = 0; i < size; ++i) {
        if ((sign == '>' && source[i] > avg) || (sign == '<' && source[i] < avg)) {
            ++resultSize;
        }
    }

    // 3. Выделение памяти для нового массива
    result = new int[resultSize];
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if ((sign == '>' && source[i] > avg) || (sign == '<' && source[i] < avg)) {
            result[j++] = source[i];
        }
    }

    cout << "Среднее арифметическое: " << fixed << setprecision(2) << avg << endl;
}

int main9() {
    setlocale(LC_ALL, "RU");
    srand(time(0)); // Инициализация генератора случайных чисел

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* arr = new int[n];
    generateRandomArray(arr, n);

    cout << "Сгенерированный массив: ";
    printArray(arr, n);

    char sign;
    cout << "Введите знак ('>' или '<'): ";
    cin >> sign;

    if (sign != '>' && sign != '<') {
        cerr << "Ошибка: допустимы только символы '>' или '<'!" << endl;
        delete[] arr;
        return 1;
    }

    int* filtered = nullptr;
    int filteredSize = 0;
    filterArray(arr, n, sign, filtered, filteredSize);

    cout << "Результирующий массив: ";
    printArray(filtered, filteredSize);

    delete[] arr;
    delete[] filtered;
    return 0;
}
