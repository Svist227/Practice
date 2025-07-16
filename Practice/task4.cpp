#include <iostream>
using namespace std;

int main5() {
    setlocale(LC_ALL, "RU");
    int thisYears = 2025;
    int a1 = thisYears;
    for (int i = 0; i < 15; i++) {
        if ((thisYears - a1) % 3 == 0 && (thisYears + 6 - a1) % 5 == 0) {
            cout << thisYears << " Убыточный и прибыльный" << endl;
        }
        else if ((thisYears - a1) % 3 == 0) {

            cout << thisYears << " Убыточный" << endl;
        }
        else if ((thisYears + 6 - a1) % 5 == 0) {

            cout << thisYears << " Прибыльный" << endl;
        }
        else {
            cout << thisYears << " Обычный" << endl;
        }
        thisYears++;
    }



    return 0;
}