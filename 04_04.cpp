#include <iostream>

int main() {
    std::string str;

    // 定义并输入一个字符串
    std::cout << "请输入一个字：";
    std::getline(std::cin, str);

    // 大小写字母互换，包含了函数的嵌套。
    for (char &c : str) {
        if (std::islower(c)) {
            c = std::toupper(c);
        } else if (std::isupper(c)) {
            c = std::tolower(c);
        }
    }

    // 输出结果
    std::cout << "互换大小写后的字符串：" << str << std::endl;

    return 0;
}
