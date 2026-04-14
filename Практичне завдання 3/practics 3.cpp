#include <iostream>
#include <windows.h> 

int my_abs(int x) {
    if (x < 0) return -x;
    return x;
}

unsigned long int random_seed = 12345;
int my_rand() {
    random_seed = random_seed * 1103515245 + 12345;
    return (unsigned int)(random_seed / 65536) % 32768;
}

int** Masiv(int rows, int cols) {
    if (rows > 0 && cols > 0) {
        int** ptr = new int* [rows];
        for (int i = 0; i < rows; i++) {
            ptr[i] = new int[cols];
        }
        return ptr;
    }
    return nullptr;
}

void deleteMasiv(int** ptr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;
}

void fillMasivSimple(int** ptr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ptr[i][j] = (my_rand() % 21) - 10;
        }
    }
}

void printMasiv(int** ptr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << ptr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n;
    std::cout << "Введiть розмiр матрицi n x n: ";
    std::cin >> n;

    int** ptr = Masiv(n, n);
    fillMasivSimple(ptr, n, n);

    std::cout << "\nПочаткова матриця:\n";
    printMasiv(ptr, n, n);

    int max_neg_val = -9999;
    int max_neg_row = -1, max_neg_col = -1;
    bool found_neg = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j && i < n - 1 - j) {
                if (ptr[i][j] < 0) {
                    if (!found_neg || ptr[i][j] > max_neg_val) {
                        max_neg_val = ptr[i][j];
                        max_neg_row = i;
                        max_neg_col = j;
                        found_neg = true;
                    }
                }
            }
        }
    }

    if (found_neg) {
        std::cout << "Сектор 6. Найбiльший вiд'ємний: " << max_neg_val
            << " (рядок " << max_neg_row + 1 << ", стовпець " << max_neg_col + 1 << ")\n\n";
    }
    else {
        std::cout << "Сектор 6. Вiд'ємних елементiв немає.\n\n";
    }

    int min_abs_value = my_abs(ptr[0][0]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (my_abs(ptr[i][j]) < min_abs_value) {
                min_abs_value = my_abs(ptr[i][j]);
            }
        }
    }

    int count_sect4 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j && i < n - 1 - j) {
                count_sect4++;
                ptr[i][j] = min_abs_value;
            }
        }
    }

    std::cout << "Сектор 4. Кiлькiсть елементiв: " << count_sect4 << "\n";
    std::cout << "Мiнiмальне по модулю значення матрицi: " << min_abs_value << "\n\n";

    std::cout << "Матриця пiсля замiн:\n";
    printMasiv(ptr, n, n);

    deleteMasiv(ptr, n);

    return 0;
}