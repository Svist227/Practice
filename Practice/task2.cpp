#include <iostream>
#include <cmath>
using namespace std;

int main3() {
    setlocale(LC_ALL, "RU");
    int x, y;
    cin >> x >> y;
    if (x > 0 and y > 0) {
        cout << "������ ���������";
    }
    if (x < 0 and y > 0) {
        cout << "������ ���������";
    }
    if (x < 0 and y < 0) {
        cout << "������ ���������";
    }
    if (x > 0 and y < 0) {
        cout << "��������� ���������";
    }

    return 0;
}