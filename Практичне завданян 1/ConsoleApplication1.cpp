#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <ctime>

using namespace std;
using namespace std::chrono;

void generateArray(int arr[], int n);
void bubbleSort(int arr[], int n);
void countingSort(int arr[], int n);
void shellSort(int arr[], int n);
void runTest(int n);

int main() {
   
    system("chcp 1251 > nul");

    
    srand(static_cast<unsigned int>(time(0)));

    int sizes[] = { 12, 125, 1500, 7000, 35000, 170000 };

    for (int n : sizes) {
        runTest(n);
    }

    cout << "\nПрограму завершено успішно! Натисніть Enter...";
    cin.ignore();
    cin.get();
    return 0;
}

void runTest(int n) {
    cout << "\n>>> Тестування для n = " << n << endl;
    int* original = new int[n];
    int* temp = new int[n];
    generateArray(original, n);

    
    for (int i = 0; i < n; i++) temp[i] = original[i];
    auto s1 = high_resolution_clock::now();
    shellSort(temp, n);
    auto e1 = high_resolution_clock::now();
    cout << "Shell Sort:    " << duration_cast<microseconds>(e1 - s1).count() << " mks" << endl;

    
    for (int i = 0; i < n; i++) temp[i] = original[i];
    auto s2 = high_resolution_clock::now();
    countingSort(temp, n);
    auto e2 = high_resolution_clock::now();
    cout << "Counting Sort: " << duration_cast<microseconds>(e2 - s2).count() << " mks" << endl;

    if (n <= 35000) {
        for (int i = 0; i < n; i++) temp[i] = original[i];
        auto s3 = high_resolution_clock::now();
        bubbleSort(temp, n);
        auto e3 = high_resolution_clock::now();
        cout << "Bubble Sort:   " << duration_cast<milliseconds>(e3 - s3).count() << " ms" << endl;
    }
    else {
        cout << "Bubble Sort:   Пропущено (занадто довго)" << endl;
    }

    delete[] original;
    delete[] temp;
}
void generateArray(int arr[], int n) { for (int i = 0; i < n; i++) arr[i] = rand() % 10000; }

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}

void countingSort(int arr[], int n) {
    if (n <= 0) return;
    int maxV = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > maxV) maxV = arr[i];
    vector<int> c(maxV + 1, 0);
    for (int i = 0; i < n; i++) c[arr[i]]++;
    for (int i = 0, k = 0; i <= maxV; i++) while (c[i]-- > 0) arr[k++] = i;
}

void shellSort(int arr[], int n) {
    for (int g = n / 2; g > 0; g /= 2)
        for (int i = g; i < n; i++) {
            int t = arr[i], j;
            for (j = i; j >= g && arr[j - g] > t; j -= g) arr[j] = arr[j - g];
            arr[j] = t;
        }
}