#include <iostream>
using namespace std;

int main() {
    int a, b = 0, digitCount = 0;

    cout << "请输入一个整数: ";
    cin >> a;

    do {
        int digit = a % 10; // 用取余数的方法获取最后一位数
        b = b * 10 + digit; // 将数字反向依次乘10
        a /= 10; // 因为数字定义的是整型所以会舍弃掉小数部分
       digitCount++; // 递增位数计数
    } while (a > 0);

    cout << "反向输出的整数为: " << b << endl;
    cout << "位数为: " << digitCount << endl;

    return 0;
}