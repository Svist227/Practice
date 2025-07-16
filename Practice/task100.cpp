#include <iostream>
#include <string>
using namespace std;

// �������, ������� ������� ����� � ��������� ����� ������ �� ���
string extractDigits(const string& s, int& digitCount) {
    string result;
    digitCount = 0;
    for (char c : s) {
        if (isdigit(c)) {
            result += c;
            ++digitCount;
        }
    }
    return result;
}

int main12() {
    setlocale(LC_ALL, "RU");
    string input;
    cout << "������� ������: ";
    getline(cin, input);

    int count = 0;
    string digits = extractDigits(input, count);

    cout << "���� �������: " << count << endl;
    cout << "������ �� ����: " << digits << endl;

    return 0;
}
