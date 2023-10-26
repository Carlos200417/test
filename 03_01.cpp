#include <iostream>
using namespace std;

int main() {
    int a, b; //定义两个整数

    cout << "请输入第一个整数: ";
    cin >> a; //输入第一个整数
    cout << "请输入第二个整数: ";
    cin >> b; //输入第二个整数

    if (a < b)
    {
        cout << a << " 小于 " << b << endl;
    } 
    else if (a > b)
    {
        cout << a << " 大于 " << b << endl;
    } 
    else 
    {
        cout << a << " 等于 " << b << endl;
    }

    return 0;
}
