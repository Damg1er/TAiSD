
#include <cmath>
using namespace std;
class Point {
    static int counter;

public:
    double x;
    double y;

    Point() {
        counter++;
    }

    ~Point() {
        counter--;
    }

    static int getCounter() {
        return counter;
    }

    double distance() {
        return sqrt(x * x + y * y);
    }

    // Унарные операции
    void MinusOperator() {
        x--;
        y--;
    }

    void SwapOperator() {
        std::swap(x, y);
    }

    int Convert(double x) {
        return (int)x;  // неявное приведение типа double к int (целая часть)
    }
    double Convert(int y) {
        return (double)y;  // явное приведение типа int к double
    }


    // Бинарные операции
    Point BinOperator(Point p, int val) {
        Point result = p;
        result.x -= val;
        return result;
    }

    Point BinOperator(int val, Point p) {
        Point result = p;
        result.y -= val;
        return result;
    }

    double BinOperator(Point p1, Point p2) {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        return sqrt(dx * dx + dy * dy);
    }
};

int Point::counter = 0;

double distance(double x, double y) {
    return sqrt(x * x + y * y);
}

double InputValidation(double num, std::string s) {
    bool b = false;
    do {
        b = false;
        cout << s;
        if (!(std::cin >> num)) {
            cin.clear();
            cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            cout << "Ошибка ввода!\n";
            b = true;
        }
    } while (b);
    return num;
}