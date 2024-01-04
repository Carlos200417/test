#include <iostream>
#include <list>

int main() {
    // 创建整数类型的链表
    std::list<int> mylist;
    int input;

    // 提示用户输入整数
    std::cout << "请输入整数（输入非整数以结束）：" << std::endl;

    // 从标准输入读取整数，并添加到链表中
    while (std::cin >> input) {
        mylist.push_back(input);
    }

    // 检查链表是否为空
    if (!mylist.empty()) {
        // 删除链表的第一个和最后一个元素
        mylist.pop_front(); // 删除第一个元素
        mylist.pop_back();  // 删除最后一个元素

        // 输出剩余的链表内容
        std::cout << "剩余的链表内容为：" << std::endl;
        for (const auto &elem : mylist) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "链表为空" << std::endl;
    }

    return 0;
}
