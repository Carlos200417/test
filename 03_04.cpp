#include <iostream>

using namespace std;

int main() {
    int a;
    cout << "请输入金字塔的行数: ";
    cin >> a;

    int b = 1;
    while (b <= a) {
        for (int space = 1; space <= a - b; space++)
        {
            cout << " ";
        }
        for (int star = 1; star <= 2 * b - 1; star++)
        {
            cout << "*";
        }
        cout << endl;
        b++;
    }
//第一个for循环直到运行到条件不满足才会进行第二个for循环，而每一次while循环完成的是一行的输入。
    return 0;
}
