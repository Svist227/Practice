#include <iostream>
using namespace std;

int Min(int x, int y, int z) {
    int min;
    if (x > y) {
        min = y;
    }
    else {
        min = x;
    }

    if (z < min) {
        min = z;
    }
    return min;

}
int main6() {

    bool flag = true;
    while (flag == true) {
        int a, b, c, d;
        string str;
        cout << "Enter three numbers: ";
        cin >> a >> b >> c;
        cout << "Calculate the minimum number? ";
        cin >> str;
        if (str == "Yes" || str == "yes") {
            d = Min(a, b, c);
            cout << "Minimum number: " << d;
            break;
        }
        else {
            continue;
        }
    }

    return 0;
}