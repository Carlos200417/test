#include <iostream>
#include <cmath>

int main() {
    double base, x;

    // 输入底数和实数
    std::cout << "请输入底数：";
    std::cin >> base;

    std::cout << "请输入实数：";
    std::cin >> x;

    // 检查输入是否为正数
    if (base <= 0 || x <= 0) {
        std::cout << "底数和实数必须为正数。" << std::endl;
        return 1; // 返回错误代码
    }

    // 使用while循环计算对数
    double result = 0.0;
    while (x >= base) {
        x = x / base;
        result++;
    }

    // 输出结果
    std::cout << "以" << base << "为底 " << x << " 的对数是：" << result << std::endl;

    return 0;
}
