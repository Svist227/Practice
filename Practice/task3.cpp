#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main4() {
    setlocale(LC_ALL, "Russian");

    int number, correctAnswers, userAnswer;
    string tryAgain;

    srand(time(0));  // ������������� ���������� ��������� �����

    do {
        // ����������� ���������� ����� �� ��� ���, ���� �� ������� 1�10
        do {
            cout << "�������� ����� �� 1 �� 10 ��� ������� ���������: ";
            cin >> number;
            if (number < 1 || number > 10)
                cout << "������: ������� ����� �� 1 �� 10.\n";
        } while (number < 1 || number > 10);

        correctAnswers = 0;

        for (int i = 0; i < 10; ++i) {
            int randomMultiplier = rand() % 10 + 1; // �� 1 �� 10

            cout << number << " x " << randomMultiplier << " = ";
            cin >> userAnswer;

            if (userAnswer == number * randomMultiplier) {
                correctAnswers++;
            }
        }

        cout << "\n�� ��������� �������� �� " << correctAnswers << " �� 10.\n";

        if (correctAnswers == 10)
            cout << "������: �������\n";
        else if (correctAnswers == 9)
            cout << "������: ������\n";
        else if (correctAnswers >= 7)
            cout << "������: �����������������\n";
        else
            cout << "������: �������������������\n";

        cout << "\n������ ����������� �����? (yes/no): ";
        cin >> tryAgain;

    } while (tryAgain == "yes" || tryAgain == "Yes");

    cout << "�� ��������!\n";
    return 0;
}
