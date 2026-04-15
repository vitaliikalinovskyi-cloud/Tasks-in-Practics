#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

struct Building {
    std::string address;
    int floors;
    std::string purpose;
    double area;
    int year;
};

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::vector<Building> buildings;
    Building temp;

    std::cout << "Введіть адресу: ";
    std::getline(std::cin, temp.address);
    std::cout << "Введіть кількість поверхів: ";
    std::cin >> temp.floors;
    std::cin.ignore();
    std::cout << "Введіть призначення: ";
    std::getline(std::cin, temp.purpose);
    std::cout << "Введіть площу: ";
    std::cin >> temp.area;
    std::cout << "Введіть рік введення: ";
    std::cin >> temp.year;

    buildings.push_back(temp);

    std::ofstream outFile("data.txt");
    for (size_t i = 0; i < buildings.size(); i++) {
        outFile << buildings[i].address << '\n'
            << buildings[i].floors << '\n'
            << buildings[i].purpose << '\n'
            << buildings[i].area << '\n'
            << buildings[i].year << '\n';
    }
    outFile.close();

    std::vector<Building> loadedData;
    std::ifstream inFile("data.txt");
    Building b;

    while (std::getline(inFile, b.address)) {
        inFile >> b.floors;
        inFile.ignore();
        std::getline(inFile, b.purpose);
        inFile >> b.area;
        inFile >> b.year;
        inFile.ignore();

        loadedData.push_back(b);
    }
    inFile.close();

    std::cout << "\n--- Всі зчитані будівлі ---\n";
    for (size_t i = 0; i < loadedData.size(); i++) {
        std::cout << loadedData[i].address << " (" << loadedData[i].year << " рік, " << loadedData[i].floors << " поверхів)\n";
    }

    std::cout << "\n--- РЕЗУЛЬТАТ ЗАВДАННЯ (>3 поверхів і після 2005) ---\n";
    for (size_t i = 0; i < loadedData.size(); i++) {
        if (loadedData[i].floors > 3 && loadedData[i].year > 2005) {
            std::cout << "Підходить: " << loadedData[i].address << '\n';
        }
    }

    return 0;
}