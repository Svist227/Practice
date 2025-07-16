#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Структура для представления материальной точки
struct Point {
    double x;     // координата
    double mass;  // масса
};

// Функция ввода массива точек
void inputPoints(Point* points, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Введите координату и массу точки #" << i + 1 << " через пробел: ";
        while (!(cin >> points[i].x >> points[i].mass)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ошибка ввода. Повторите ввод координаты и массы точки #" << i + 1 << ": ";
        }
    }
}

// Функция вывода массива точек
void outputPoints(const Point* points, int n) {
    cout << setw(5) << "№"
        << setw(15) << "Координата"
        << setw(15) << "Масса" << endl;

    for (int i = 0; i < n; ++i) {
        cout << setw(5) << i + 1
            << setw(15) << fixed << setprecision(2) << points[i].x
            << setw(15) << fixed << setprecision(2) << points[i].mass << endl;
    }
}

// Функция находит координату центра тяжести
double findCenterOfGravity(const Point* points, int n) {
    double sumMassX = 0.0;
    double sumMass = 0.0;

    for (int i = 0; i < n; ++i) {
        sumMassX += points[i].x * points[i].mass;
        sumMass += points[i].mass;
    }

    if (sumMass == 0) {
        cerr << "Ошибка: суммарная масса равна нулю!" << endl;
        return 0.0;
    }

    return sumMassX / sumMass;
}

// Функция находит индекс точки, ближайшей к центру тяжести
int findClosestPoint(const Point* points, int n, double center) {
    int closestIndex = 0;
    double minDistance = abs(points[0].x - center);

    for (int i = 1; i < n; ++i) {
        double distance = abs(points[i].x - center);
        if (distance < minDistance) {
            minDistance = distance;
            closestIndex = i;
        }
    }

    return closestIndex;
}

// Функция удаляет точку по индексу из массива
void removePoint(Point*& points, int& n, int index) {
    if (index < 0 || index >= n) {
        cerr << "Ошибка: неверный индекс точки для удаления." << endl;
        return;
    }

    Point* newPoints = new Point[n - 1];
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (i != index) {
            newPoints[j++] = points[i];
        }
    }

    delete[] points;
    points = newPoints;
    --n;
}


int main8() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите количество материальных точек: ";
    while (!(cin >> n) || n <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка: введите положительное целое число: ";
    }

    Point* points = new Point[n];
    inputPoints(points, n);

    cout << "\nВведённые точки:\n";
    outputPoints(points, n);

    double center = findCenterOfGravity(points, n);
    cout << "\nКоордината центра тяжести: " << fixed << setprecision(2) << center << endl;

    int closestIndex = findClosestPoint(points, n, center);
    cout << "Ближайшая точка к центру тяжести — №" << closestIndex + 1 << endl;

    removePoint(points, n, closestIndex);

    cout << "\nТочки после удаления ближайшей к центру тяжести:\n";
    outputPoints(points, n);

    delete[] points;
    return 0;
}
