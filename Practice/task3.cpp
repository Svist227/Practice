#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main4() {
    setlocale(LC_ALL, "Russian");

    int number, correctAnswers, userAnswer;
    string tryAgain;

    srand(time(0));  // инициализация генератора случайных чисел

    do {
        // Запрашиваем корректное число до тех пор, пока не введено 1–10
        do {
            cout << "Выберите число от 1 до 10 для таблицы умножения: ";
            cin >> number;
            if (number < 1 || number > 10)
                cout << "Ошибка: введите число от 1 до 10.\n";
        } while (number < 1 || number > 10);

        correctAnswers = 0;

        for (int i = 0; i < 10; ++i) {
            int randomMultiplier = rand() % 10 + 1; // от 1 до 10

            cout << number << " x " << randomMultiplier << " = ";
            cin >> userAnswer;

            if (userAnswer == number * randomMultiplier) {
                correctAnswers++;
            }
        }

        cout << "\nВы правильно ответили на " << correctAnswers << " из 10.\n";

        if (correctAnswers == 10)
            cout << "Оценка: отлично\n";
        else if (correctAnswers == 9)
            cout << "Оценка: хорошо\n";
        else if (correctAnswers >= 7)
            cout << "Оценка: удовлетворительно\n";
        else
            cout << "Оценка: неудовлетворительно\n";

        cout << "\nХотите попробовать снова? (yes/no): ";
        cin >> tryAgain;

    } while (tryAgain == "yes" || tryAgain == "Yes");

    cout << "До свидания!\n";
    return 0;
}
