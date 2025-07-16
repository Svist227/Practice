#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// ��������� ��� ������������� ������������ �����
struct Point {
    double x;     // ����������
    double mass;  // �����
};

// ������� ����� ������� �����
void inputPoints(Point* points, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "������� ���������� � ����� ����� #" << i + 1 << " ����� ������: ";
        while (!(cin >> points[i].x >> points[i].mass)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "������ �����. ��������� ���� ���������� � ����� ����� #" << i + 1 << ": ";
        }
    }
}

// ������� ������ ������� �����
void outputPoints(const Point* points, int n) {
    cout << setw(5) << "�"
        << setw(15) << "����������"
        << setw(15) << "�����" << endl;

    for (int i = 0; i < n; ++i) {
        cout << setw(5) << i + 1
            << setw(15) << fixed << setprecision(2) << points[i].x
            << setw(15) << fixed << setprecision(2) << points[i].mass << endl;
    }
}

// ������� ������� ���������� ������ �������
double findCenterOfGravity(const Point* points, int n) {
    double sumMassX = 0.0;
    double sumMass = 0.0;

    for (int i = 0; i < n; ++i) {
        sumMassX += points[i].x * points[i].mass;
        sumMass += points[i].mass;
    }

    if (sumMass == 0) {
        cerr << "������: ��������� ����� ����� ����!" << endl;
        return 0.0;
    }

    return sumMassX / sumMass;
}

// ������� ������� ������ �����, ��������� � ������ �������
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

// ������� ������� ����� �� ������� �� �������
void removePoint(Point*& points, int& n, int index) {
    if (index < 0 || index >= n) {
        cerr << "������: �������� ������ ����� ��� ��������." << endl;
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
    cout << "������� ���������� ������������ �����: ";
    while (!(cin >> n) || n <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "������: ������� ������������� ����� �����: ";
    }

    Point* points = new Point[n];
    inputPoints(points, n);

    cout << "\n�������� �����:\n";
    outputPoints(points, n);

    double center = findCenterOfGravity(points, n);
    cout << "\n���������� ������ �������: " << fixed << setprecision(2) << center << endl;

    int closestIndex = findClosestPoint(points, n, center);
    cout << "��������� ����� � ������ ������� � �" << closestIndex + 1 << endl;

    removePoint(points, n, closestIndex);

    cout << "\n����� ����� �������� ��������� � ������ �������:\n";
    outputPoints(points, n);

    delete[] points;
    return 0;
}
