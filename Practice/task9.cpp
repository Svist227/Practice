#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// ��������� �����
struct Point {
    double x, y;
};

// ������� ��� ���������� ���������� ����� ����� �������
double distance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// ������� ����� ������� �����
void inputPointss(Point* points, int count) {
    for (int i = 0; i < count; ++i) {
        cout << "������� ���������� ����� #" << i + 1 << " (x y): ";
        cin >> points[i].x >> points[i].y;
    }
}

// ������� ���������� ������� ����������
void buildDistanceMatrix(const Point* points, double** matrix, int count) {
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            matrix[i][j] = distance(points[i], points[j]);
        }
    }
}

// ����� ����������� ���������� � �������� �����
void findMaxDistance(double** matrix, int count, int& iMax, int& jMax, double& maxDist) {
    maxDist = 0;
    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) { // �� ���������
            if (matrix[i][j] > maxDist) {
                maxDist = matrix[i][j];
                iMax = i;
                jMax = j;
            }
        }
    }
}

// ����� �������
void printMatrix(double** matrix, int count) {
    cout << fixed << setprecision(2);
    cout << "\n������� ����������:\n";
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
    cout << "������� ���������� �����: ";
    cin >> p;

    Point* points = new Point[p];

    inputPointss(points, p);

    // ��������� ������ ��� ������� ����������
    double** matrix = new double* [p];
    for (int i = 0; i < p; ++i)
        matrix[i] = new double[p];

    buildDistanceMatrix(points, matrix, p);
    printMatrix(matrix, p);

    int iMax, jMax;
    double maxDistance;
    findMaxDistance(matrix, p, iMax, jMax, maxDistance);

    cout << "\n���������� ����������: " << fixed << setprecision(2) << maxDistance << endl;
    cout << "����� ������� #" << iMax + 1 << " � #" << jMax + 1 << endl;

    // ������������ ������
    for (int i = 0; i < p; ++i)
        delete[] matrix[i];
    delete[] matrix;
    delete[] points;

    return 0;
}
