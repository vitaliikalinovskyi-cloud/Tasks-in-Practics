#include <iostream>
#include <cmath>
using namespace std;
struct Point {
    double x;
    double y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double heron_area(Point p1, Point p2, Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);

    double p = (a + b + c) / 2.0; 
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
  
    Point M1 = { 0.0, 0.0 };
    Point M2 = { 1.0, 2.0 };
    Point M3 = { 3.0, 2.0 };
    Point M4 = { 5.0, 0.0 };
    Point M5 = { 4.0, -2.0 };

    double area1 = heron_area(M1, M2, M3);
    double area2 = heron_area(M1, M3, M4);
    double area3 = heron_area(M1, M4, M5);
    double total_area = area1 + area2 + area3;

    cout << "Площа першого трикутника: " << area1 << endl;
    cout << "Площа другого трикутника: " << area2 << endl;
    cout << "Площа третього трикутника: " << area3 << endl;
    cout << "Загальна площа п'ятикутника: " << total_area << endl;

    return 0;
}