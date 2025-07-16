#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Структура точки
struct Point {
    double x, y;
};

// Функция для вычисления расстояния между двумя точками
double distance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Функция ввода массива точек
void inputPointss(Point* points, int count) {
    for (int i = 0; i < count; ++i) {
        cout << "Введите координаты точки #" << i + 1 << " (x y): ";
        cin >> points[i].x >> points[i].y;
    }
}

// Функция заполнения матрицы расстояний
void buildDistanceMatrix(const Point* points, double** matrix, int count) {
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            matrix[i][j] = distance(points[i], points[j]);
        }
    }
}

// Поиск наибольшего расстояния и индексов точек
void findMaxDistance(double** matrix, int count, int& iMax, int& jMax, double& maxDist) {
    maxDist = 0;
    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) { // не дублируем
            if (matrix[i][j] > maxDist) {
                maxDist = matrix[i][j];
                iMax = i;
                jMax = j;
            }
        }
    }
}

// Вывод матрицы
void printMatrix(double** matrix, int count) {
    cout << fixed << setprecision(2);
    cout << "\nМатрица расстояний:\n";
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            cout << setw(8) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main11() {
    setlocale(LC_ALL, "RU");
    int p;
    cout << "Введите количество точек: ";
    cin >> p;

    Point* points = new Point[p];

    inputPointss(points, p);

    // Выделение памяти под матрицу расстояний
    double** matrix = new double* [p];
    for (int i = 0; i < p; ++i)
        matrix[i] = new double[p];

    buildDistanceMatrix(points, matrix, p);
    printMatrix(matrix, p);

    int iMax, jMax;
    double maxDistance;
    findMaxDistance(matrix, p, iMax, jMax, maxDistance);

    cout << "\nНаибольшее расстояние: " << fixed << setprecision(2) << maxDistance << endl;
    cout << "Между точками #" << iMax + 1 << " и #" << jMax + 1 << endl;

    // Освобождение памяти
    for (int i = 0; i < p; ++i)
        delete[] matrix[i];
    delete[] matrix;
    delete[] points;

    return 0;
}
