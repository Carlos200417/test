#include <iostream>
#include <forward_list>

// 模板函数：接受一个 forward_list 和阈值参数，并移除小于阈值的元素
template<typename T>
void filterList(std::forward_list<T>& lst, const T& threshold) {
    // 使用 remove_if 和 lambda 表达式移除小于阈值的元素
    lst.remove_if([&threshold](const T& val) { return val < threshold; });
}

int main() {
    std::forward_list<int> myList; // 创建一个整数类型的 forward_list
    int value;

    std::cout << "Enter integers (enter non-integer to stop):" << std::endl;
    while (std::cin >> value) {
        myList.push_front(value); // 从标准输入读取整数并添加到链表
    }

    int threshold;
    std::cout << "Enter threshold value: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> threshold; // 获取用户输入的阈值

    filterList(myList, threshold); // 使用 filterList 函数过滤链表

    std::cout << "Filtered List:" << std::endl;
    for (const auto& val : myList) {
        std::cout << val << " "; // 打印处理后的列表
    }
    std::cout << std::endl;

    return 0;
}
