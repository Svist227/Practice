#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// ������� ����� ���������� �� ������
string removePunctuation(const string& s) {
    string result;
    for (char c : s) {
        if (!ispunct(c)) {
            result += c;
        }
    }
    return result;
}

int main13() {
    setlocale(LC_ALL, "RU");
    ifstream inFile("F1.txt");
    ofstream outFile("F2.txt");

    if (!inFile.is_open()) {
        cerr << "�� ������� ������� F1.txt!" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        string cleaned = removePunctuation(line);
        outFile << cleaned << endl;
    }

    cout << "��������� ���������. ��������� ������� � F2.txt." << endl;

    inFile.close();
    outFile.close();

    return 0;
}
