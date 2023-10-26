#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cout << "请输入一元二次方程的系数 (a, b, c): ";
    cin >> a >> b >> c;

    if (a == 0) { //分步骤逐步进行判断，先判断是不是一元二次方程
        cout << "a不能为0，这不是一元二次方程。" << endl;
    } else {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) { //开始判断有无实根，并根据根的类型给出答案
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "有两个不同实根，它们分别为 " << root1 << " 和 " << root2 << endl;
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "有两个相同实根，它们都是 " << root << endl;
        } else {
            cout << "无实根，因为判别式小于0。" << endl;
        }
    }

    return 0;
}
