#include <iostream>
//以下开始定义两个函数
void move(int disk, char source, char target) { //三个形参定义函数：逐步输出每一次移动的结果disk为第几步，source为移动塔，target为被移动塔
    std::cout << disk << ":" << source << "->" << target << std::endl;
}

void hanoi(int n, char source, char auxiliary, char target) {//四个形参定义函数：汉诺塔的运算逻辑，比如对多个序列标识进行定义，按照顺序执行move函数。
    if (n == 1) {
        move(1, source, target);
        return;
    }
//以下对hanoi进行递归操作
    hanoi(n - 1, source, target, auxiliary);
    move(n, source, target); //函数的嵌套
    hanoi(n - 1, auxiliary, source, target);
}

int main() {
    int num_disks;
    char source, auxiliary, target;

    std::cout << "输入盘子的数量: ";
    std::cin >> num_disks;

    std::cout << "依次对塔进行标序: ";
    std::cin >> source >> auxiliary >> target;

    hanoi(num_disks, source, auxiliary, target);

    return 0;
}
