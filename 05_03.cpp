#include <iostream>
using namespace std; //使用namespace，后面不用std

class Point {
protected: //被保护
    double x, y;

public: //类的公有成员函数
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {} //初始化

    void displayPoint() {
        cout << "点的坐标为: (" << x << ", " << y << ")" << endl;
    }

    void changePoint(double newX, double newY) {
        x = newX;
        y = newY;
    }
};

class Rectangle : public Point {
private:
    double length, width;

public: //第二个类的声明
    Rectangle(double xCoord, double yCoord, double len, double wid)
        : Point(xCoord, yCoord), length(len), width(wid) {}

    double calculateArea() {
        return length * width;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }
};

int main() { //主函数
    double x, y, length, width;

    cout << "请输入矩形的左下角坐标 (x, y): ";
    cin >> x >> y;
    cout << "请输入矩形的长度和宽度: ";
    cin >> length >> width;

    Rectangle rectangle(x, y, length, width);

    rectangle.displayPoint(); //调用第一个类
    cout << "矩形的面积为: " << rectangle.calculateArea() << endl; //调用第二个类
    cout << "矩形的周长为: " << rectangle.calculatePerimeter() << endl;

    return 0;
}
