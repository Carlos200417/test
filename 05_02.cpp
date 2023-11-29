#include <iostream>
using namespace std; //使用namespace，后面无需使用std

class Triangle {
private:
    double side1, side2, side3; //定义3个边（私有）

public: //在共有里对三边进行初始化进行初始化
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    void determineType() { //根据三边进行判断
        if (side1 == side2 && side2 == side3) {
            cout << "这是一个等边三角形" << endl;
        } else if (side1 == side2 || side1 == side3 || side2 == side3) {
            cout << "这是一个等腰三角形" << endl;
        } else {
            cout << "这是一个不等边三角形" << endl;
        }
    }
};

int main() { //主函数
    double mash1, mash2, mash3; //定义三个即将被输入的值

    cout << "请输入三角形的三条边长: " << endl;
    cin >> mash1 >> mash2 >> mash3;

    Triangle triangle(mash1, mash2, mash3); //把值给到类的变量，建立一个对象叫做triangle
    triangle.determineType(); //运行成员函数

    return 0;
}