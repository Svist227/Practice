#include <vector>
#include <iostream>
#include <climits>
using namespace std;

float srednee(int X, int Y, float sum) {
    return (sum / (X * Y));
}

int sredElement(int matrix[100][100], int N, int M, float average) {
    int closest = matrix[0][0];
    int min_diff = abs(matrix[0][0] - average); // 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int diff = abs(matrix[i][j] - average);
            if (diff < min_diff) {
                min_diff = diff;
                closest = matrix[i][j];
            }
        }
    }

    return closest;
}
int main7() {
    setlocale(LC_ALL, "RU");
    int N, M;
    int summ = 0;
    cin >> N >> M;
    int array[100][100];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int el;
            cin >> el;
            summ += el;
            array[i][j] = el;
        }
    }
    cout << "Среднее арифм: " << srednee(N, M, summ) << endl;
    cout << "Ближайший к среднему: " << sredElement(array, N, M, srednee(N, M, summ));

    return 0;
}