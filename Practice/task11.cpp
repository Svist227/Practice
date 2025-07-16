#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

const int N = 40;

// ���������� ������� �� �����
bool readTournamentTable(const string& filename, int table[N][N]) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "�� ������� ������� ����!" << endl;
        return false;
    }

    string line;
    int row = 0;
    while (getline(inFile, line) && row < N) {
        stringstream ss(line);
        string cell;
        int col = 0;

        while (ss >> cell && col < N) {
            if (cell == "X")
                table[row][col] = -1; // ��� � ����� �����
            else
                table[row][col] = stoi(cell);
            ++col;
        }
        ++row;
    }

    inFile.close();
    return true;
}

// ������� �����
void countWins(const int table[N][N], int wins[N]) {
    for (int i = 0; i < N; ++i) {
        wins[i] = 0;
        for (int j = 0; j < N; ++j) {
            if (table[i][j] == 1)
                ++wins[i];
        }
    }
}

// ����� ������ �������� � ������ �������
void findStrongestAndWeakest(const int wins[N], int& strongest, int& weakest) {
    strongest = weakest = 0;
    for (int i = 1; i < N; ++i) {
        if (wins[i] > wins[strongest])
            strongest = i;
        if (wins[i] < wins[weakest])
            weakest = i;
    }
}

int main14() {
    setlocale(LC_ALL, "RU");
    int table[N][N];
    int wins[N];

    if (!readTournamentTable("tournament.txt", table))
        return 1;

    countWins(table, wins);

    int strongest, weakest;
    findStrongestAndWeakest(wins, strongest, weakest);

    cout << "����� ������� ���������: #" << strongest + 1
        << " (�����: " << wins[strongest] << ")" << endl;
    cout << "����� ������ ���������: #" << weakest + 1
        << " (�����: " << wins[weakest] << ")" << endl;

    return 0;
}
