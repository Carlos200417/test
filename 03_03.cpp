#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cout << "请输入一个整数" << endl;
    cin >> a;
    b = a % 7;
    switch(b)
    {
        case 0:
        cout << "今天是星期日" << endl;
        break;
        case 1:
        cout << "今天是星期一" << endl;
        break;
        case 2:
        cout << "今天是星期二" << endl;
        break;
        case 3:
        cout << "今天是星期三" << endl;
        break;
        case 4:
        cout << "今天是星期四" << endl;
        break;
        case 5:
        cout << "今天是星期五" << endl;
        break;
        case 6:
        cout << "今天是星期六" << endl;
        break;
        default:
        cout << "输入错误" << endl;
    }
}