#include <iostream>
using namespace std; //声明一下要用namespace，后面就可以省略掉std了。

class Circle {
private: //私有成员函数，不能直接改变，除非有个接口
    double radius;
    const double PI;

public: //共有的，类的构造函数
    Circle(double r) : radius(r), PI(3.14159){}

    double calculateArea() { //求面积的函数
        return PI * radius * radius;
    }

    double calculatePerimeter() { //求周长的函数
        return 2 * PI * radius;
    }
};

int main() {
    double radiusValue; //定义即将被输入的值
    cout << "请输入圆的半径:";
    cin >> radiusValue;

    if (radiusValue <= 0) {
        cout << "请输入大于零的有效半径值。" << endl; //做一个有效判断
        return 1;
    }

    Circle circleObject(radiusValue); //给类添加一个对象并赋值
//带着有值的对象回到类中的构造函数进行运算
    double area = circleObject.calculateArea();
    double perimeter = circleObject.calculatePerimeter();
//赋个新名字方便输出
    cout << "圆的面积为: " << area << endl;
    cout << "圆的周长为: " << perimeter << endl;

    return 0;
}
