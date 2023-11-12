#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int test_cases;
    cout << "请输入测试数据的组数：";
    cin >> test_cases;

    int count = 0, a;
    while (count < test_cases) {
        cout << "请输入正整数a：";
        cin >> a;
        int result = fibonacci(a);
        cout << "斐波那契数列中第" << a << "个数是：" << result << endl;
        count++;
    }

    return 0;
}
