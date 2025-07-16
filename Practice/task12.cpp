#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Структура для даты и события
struct EventDate {
    int day;
    string month;
    int year;
    string eventName;
};

// Карта названий месяцев в числовой порядок
int getMonthNumber(const string& month) {
    const string months[] = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
        "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };
    for (int i = 0; i < 12; ++i)
        if (month == months[i]) return i + 1;
    return 0; // если не найдено
}

// Ввод одной даты
EventDate inputDate() {
    EventDate d;
    cout << "Введите событие: ";
    getline(cin, d.eventName);
    cout << "Введите дату (день месяц год): ";
    cin >> d.day >> d.month >> d.year;
    cin.ignore(); // очистка буфера
    return d;
}

// Вывод даты в формате ДД.ММ.ГГ
void printShortFormat(const EventDate& d) {
    int mm = getMonthNumber(d.month);
    cout << setw(2) << setfill('0') << d.day << "."
        << setw(2) << setfill('0') << mm << "."
        << d.year;
}

// Вывод даты в формате ДД Месяц ГГ
void printLongFormat(const EventDate& d) {
    cout << d.day << " " << d.month << " " << d.year;
}

// Сортировка по дате
bool compareByDate(const EventDate& a, const EventDate& b) {
    if (a.year != b.year) return a.year < b.year;
    if (getMonthNumber(a.month) != getMonthNumber(b.month))
        return getMonthNumber(a.month) < getMonthNumber(b.month);
    return a.day < b.day;
}

// Сортировка по названию события
bool compareByEventName(const EventDate& a, const EventDate& b) {
    return a.eventName < b.eventName;
}

// Вывод всех событий
void printAll(const vector<EventDate>& dates, bool shortFormat = true) {
    for (const auto& d : dates) {
        cout << "- " << d.eventName << " — ";
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
    cout << "Сколько дат хотите ввести? ";
    cin >> n;
    cin.ignore(); // очистка буфера

    for (int i = 0; i < n; ++i) {
        cout << "\nДата #" << i + 1 << endl;
        events.push_back(inputDate());
    }

    cout << "\nВывод в коротком формате:\n";
    printAll(events, true);

    cout << "\nВывод в длинном формате:\n";
    printAll(events, false);

    sort(events.begin(), events.end(), compareByDate);
    cout << "\nСортировка по дате:\n";
    printAll(events, false);

    sort(events.begin(), events.end(), compareByEventName);
    cout << "\nСортировка по названию события:\n";
    printAll(events, false);

    return 0;
}
