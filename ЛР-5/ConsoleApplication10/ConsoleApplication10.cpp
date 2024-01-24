#include <iostream>
#include "PointArray.cpp"

using namespace std;

PointArray Arr1(int size);
PointArray ArrRand(int size, int min, int max);

int main()
{
    srand(time(0));
    setlocale(0, "");

    Point D;
    int index, size, choice, max, min;
    PointArray arr;

    cout << "Введите размер массива: ";
    cin >> size;

    cout << "Выберите тип заполнения массива:\n"
        "1. Вручную\n"
        "2. Рандомными числами в выбраном диапазоне\n"
        "Ваш выбор: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        arr = Arr1(size);
        break;
    case 2:
        cout << "Введите желаемый, минимально  возможную координату: ";
        cin >> min;
        cout << "Введите желаемый, максимально возможную координату: ";
        cin >> max;
        arr = ArrRand(size, min, max);
        break;
    default:
        return 0;
        break;
    }
    cout << "\nВаш массив координат точек:\n";
    arr.ArrayOut();

    cout << "\nВведите координаты какой точки вы хотите посмотреть: ";
    cin >> index;
    D = arr.NumOut(index - 1);
    cout << "Координаты точки: {" << D.x << ", " << D.y << "}\n";

    D = arr.ClosestPoint();
    cout << "\nКоординаты ближайщей точки к центру: " << D.x << " ... " << D.y;
    cout << "\nРасстояние от этой точки до центра: " << D.distance();
    cout << "\n\nКоличество созданных объектов класса: "
        << PointArray::GetCount() << "\n";
}

PointArray Arr1(int size) {
    PointArray arr(size);
    return arr;
}
PointArray ArrRand(int size, int min, int max) {
    PointArray arr(size, min, max);
    return arr;
}
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