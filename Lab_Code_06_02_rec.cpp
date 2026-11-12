// Lab 6.2.rec
// Variant 13

#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void Create(int* a, const int n, const int Low, const int High, int i = 0) {
    if (i >= n)
        return;
    a[i] = Low + rand() % (High - Low + 1);
    Create(a, n, Low, High, i + 1);
}

void Print(int* a, const int n, int i = 0)
{
    if (i >= n) {
        cout << endl;
        return;
    }
    cout << setw(4) << a[i];
    Print(a, n, i + 1);
}

int Max(int* a, const int n, int i = 0) {
    if (i == n - 1)
        return a[i];
    int max = Max(a, n, i + 1);
    return a[i] > max ? a[i] : max;
}

int Min(int* a, const int n, int i = 0) {
    if (i == n - 1)
        return a[i];
    int min = Min(a, n, i + 1);
    return a[i] < min ? a[i] : min;
}

// Середнє арифметичне максимального та мінімального елементів
double AverageMaxMin(int* a, const int n) {
    return (Max(a, n) + Min(a, n)) / 2.0;
}

int main() {

    srand((unsigned)time(NULL));

    const int n = 24;
    int a[n];

    int Low = -20;
    int High = 50;

    Create(a, n, Low, High);
    cout << "Array: ";
    Print(a, n);
    cout << endl;

    cout << "Max element: " << Max(a, n) << endl;
    cout << "Min element: " << Min(a, n) << endl;
    cout << "Average of max and min: " << fixed << setprecision(2)
         << AverageMaxMin(a, n) << endl;

    return 0;
}