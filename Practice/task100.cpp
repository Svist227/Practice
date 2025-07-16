#include <iostream>
#include <string>
using namespace std;

// Функция, которая считает цифры и формирует новую строку из них
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
    cout << "Введите строку: ";
    getline(cin, input);

    int count = 0;
    string digits = extractDigits(input, count);

    cout << "Цифр найдено: " << count << endl;
    cout << "Строка из цифр: " << digits << endl;

    return 0;
}
