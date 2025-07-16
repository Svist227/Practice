#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

const int HOURS = 24;

// ��������� ��������� ���������� (��������, �� 210 �� 250 �)
void generateVoltages(double voltages[], int size, double minV = 210, double maxV = 250) {
    for (int i = 0; i < size; ++i) {
        voltages[i] = minV + (rand() % 1000) / 1000.0 * (maxV - minV);
    }
}

// ����� ���������� �� �����
void printVoltages(const double voltages[], int size) {
    cout << "����\t����������\n";
    for (int i = 0; i < size; ++i) {
        cout << i << ":00\t" << voltages[i] << " �\n";
    }
}

// ������ ������� � ������� ����������
void analyzeChanges(const double voltages[], int size) {
    double maxJump = 0;
    int jumpHour = -1;

    double maxDrop = 0;
    int dropHour = -1;

    for (int i = 1; i < size; ++i) {
        double delta = voltages[i] - voltages[i - 1];
        if (delta > maxJump) {
            maxJump = delta;
            jumpHour = i;
        }
        if (delta < maxDrop) {
            maxDrop = delta;
            dropHour = i;
        }
    }

    cout << "\n������������ ������ ����������: +" << maxJump
        << " � � " << jumpHour << ":00" << endl;
    cout << "���������� ������� ����������: " << maxDrop
        << " � � " << dropHour << ":00" << endl;
}

int main10() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    double voltages[HOURS];
    generateVoltages(voltages, HOURS);
    printVoltages(voltages, HOURS);
    analyzeChanges(voltages, HOURS);

    return 0;
}
