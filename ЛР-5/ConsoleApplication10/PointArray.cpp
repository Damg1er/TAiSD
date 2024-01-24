#include <iostream>
#include <windows.h>
#include <time.h>
#include "Point.cpp"
using namespace std;

class PointArray {
    static int count;
    double minDist = DBL_MAX;
public:
    int SizeArr;
    Point* arr;

    PointArray() {
        count++;
    }

    PointArray(int size) {
        count++;
        SizeArr = size;
        arr = new Point[SizeArr];
        for (int i = 0; i < size; i++)
        {
            cout << "\nВведите координату X" << i + 1 << ": ";
            cin >> arr[i].x;
            cout << "Введите координату Y" << i + 1 << ": ";
            cin >> arr[i].y;
        }
    }

    PointArray(int size, int min, int max) {
        count++;
        SizeArr = size;
        arr = new Point[SizeArr];
        for (int i = 0; i < size; i++)
        {
            arr[i].x = rand() % (max - min) + min;
            arr[i].y = rand() % (max - min) + min;
        }
    }

    ~PointArray() {
        count--;
    }


    Point ClosestPoint() {
        int index;
        for (int i = 0; i < SizeArr; i++)
        {
            if (minDist > arr[i].distance()) {
                minDist = arr[i].distance();
                index = i;
            }
        }
        return arr[index];
    }

    Point NumOut(int i) {
        return arr[i];
    }

    void ArrayOut() {
        for (int i = 0; i < SizeArr; i++)
        {
            cout << "Точка №" << i + 1 << ", координаты: {"
                << arr[i].x << ", " << arr[i].y << "}\n";
        }
    }

    static int GetCount() {
        return count;
    }
};
int PointArray::count = 0;  