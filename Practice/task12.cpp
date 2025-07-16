#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ��������� ��� ���� � �������
struct EventDate {
    int day;
    string month;
    int year;
    string eventName;
};

// ����� �������� ������� � �������� �������
int getMonthNumber(const string& month) {
    const string months[] = {
        "������", "�������", "����", "������", "���", "����",
        "����", "������", "��������", "�������", "������", "�������"
    };
    for (int i = 0; i < 12; ++i)
        if (month == months[i]) return i + 1;
    return 0; // ���� �� �������
}

// ���� ����� ����
EventDate inputDate() {
    EventDate d;
    cout << "������� �������: ";
    getline(cin, d.eventName);
    cout << "������� ���� (���� ����� ���): ";
    cin >> d.day >> d.month >> d.year;
    cin.ignore(); // ������� ������
    return d;
}

// ����� ���� � ������� ��.��.��
void printShortFormat(const EventDate& d) {
    int mm = getMonthNumber(d.month);
    cout << setw(2) << setfill('0') << d.day << "."
        << setw(2) << setfill('0') << mm << "."
        << d.year;
}

// ����� ���� � ������� �� ����� ��
void printLongFormat(const EventDate& d) {
    cout << d.day << " " << d.month << " " << d.year;
}

// ���������� �� ����
bool compareByDate(const EventDate& a, const EventDate& b) {
    if (a.year != b.year) return a.year < b.year;
    if (getMonthNumber(a.month) != getMonthNumber(b.month))
        return getMonthNumber(a.month) < getMonthNumber(b.month);
    return a.day < b.day;
}

// ���������� �� �������� �������
bool compareByEventName(const EventDate& a, const EventDate& b) {
    return a.eventName < b.eventName;
}

// ����� ���� �������
void printAll(const vector<EventDate>& dates, bool shortFormat = true) {
    for (const auto& d : dates) {
        cout << "- " << d.eventName << " � ";
        if (shortFormat)
            printShortFormat(d);
        else
            printLongFormat(d);
        cout << endl;
    }
}

int main15() {
    setlocale(LC_ALL, "RU");
    vector<EventDate> events;
    int n;
    cout << "������� ��� ������ ������? ";
    cin >> n;
    cin.ignore(); // ������� ������

    for (int i = 0; i < n; ++i) {
        cout << "\n���� #" << i + 1 << endl;
        events.push_back(inputDate());
    }

    cout << "\n����� � �������� �������:\n";
    printAll(events, true);

    cout << "\n����� � ������� �������:\n";
    printAll(events, false);

    sort(events.begin(), events.end(), compareByDate);
    cout << "\n���������� �� ����:\n";
    printAll(events, false);

    sort(events.begin(), events.end(), compareByEventName);
    cout << "\n���������� �� �������� �������:\n";
    printAll(events, false);

    return 0;
}
