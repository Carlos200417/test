#include <iostream>
#include <cmath> // 用于计算三角形的平方根
using namespace std;

class Shape {
public:
    virtual double calculateArea() const = 0;    // 纯虚函数，需要在派生类中实现
    virtual double calculatePerimeter() const = 0; // 纯虚函数，需要在派生类中实现
};
//当基类中的函数被声明为虚函数时，派生类可以对其进行重写。通过基类指针或引用调用虚函数时，实际调用的是对象的派生类版本（如果派生类重写了这个虚函数），而不是基类版本。
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double len, double wid) : length(len), width(wid) {}

    double calculateArea() const override {
        return length * width;
    }

    double calculatePerimeter() const override {
        return 2 * (length + width);
    }
};

class Triangle : public Shape {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    double calculateArea() const override {
        // 使用海伦公式计算三角形面积
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculatePerimeter() const override {
        return side1 + side2 + side3;
    }
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Triangle triangle(3.0, 4.0, 5.0);

    cout << "圆的面积: " << circle.calculateArea() << ", 周长: " << circle.calculatePerimeter() << endl;
    cout << "矩形的面积: " << rectangle.calculateArea() << ", 周长: " << rectangle.calculatePerimeter() << endl;
    cout << "三角形的面积: " << triangle.calculateArea() << ", 周长: " << triangle.calculatePerimeter() << endl;

    return 0;
}
