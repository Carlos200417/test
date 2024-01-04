#include <iostream>
#include <deque>
#include <string>
#include <sstream>

int main() {
    // 创建一个整数类型的双端队列
    std::deque<int> myQueue;
    std::string command;

    // 提示用户输入命令
    std::cout << "请输入命令(push <number>, pop, print, quit)：" << std::endl;

    // 不断读取输入，执行相应的操作
    while (std::cin >> command) {
        if (command == "push") {
            int num;
            // 读取要入队的数字
            if (std::cin >> num) {
                // 将数字入队
                myQueue.push_back(num);
            } else {
                std::cout << "无效的输入" << std::endl;
                break;
            }
        } else if (command == "pop") {
            // 检查队列是否为空
            if (!myQueue.empty()) {
                // 出队一个元素
                myQueue.pop_front();
            } else {
                std::cout << "队列为空" << std::endl;
            }
        } else if (command == "print") {
            // 打印队列中的元素
            std::cout << "队列中的元素为: ";
            for (const auto &elem : myQueue) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        } else if (command == "quit") {
            // 退出程序
            break;
        } else {
            // 未知命令
            std::cout << "未知命令" << std::endl;
        }
    }

    return 0;
}
