#include <iostream>
#include <list>

int MonkeyKing(int n, int m) {
    std::list<int> monkeys;

    // 初始化猴子编号
    for (int i = 1; i <= n; ++i) {
        monkeys.push_back(i);
    }

    auto currentMonkey = monkeys.begin();

    while (monkeys.size() > 1) {
        // 计算报数
        int count = (m - 1) % monkeys.size();

        // 移动到报数的位置
        std::advance(currentMonkey, count);

        // 删除报数的猴子erase
        currentMonkey = monkeys.erase(currentMonkey);

        // 处理循环列表
        if (currentMonkey == monkeys.end()) {
            currentMonkey = monkeys.begin();
        }
    }

    return monkeys.front();//回到第一个猴子的位置
}

int main() { //主循环定义猴子的总数，和第几个猴子的触发
    int n, m;

    while (true) {
        std::cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        int monkeyKinger = MonkeyKing(n, m);
        std::cout << monkeyKinger << std::endl;
    }

    return 0;
}
