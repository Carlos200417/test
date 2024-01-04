#include <iostream>
#include <vector>
#include <algorithm>

// 函数用于去除容器中的重复元素并进行升序排序
void uniqueSort(std::vector<int> &vec) {
    // 对容器中的元素进行排序
    std::sort(vec.begin(), vec.end());

    // 使用unique函数移除重复元素，并返回指向新结尾的迭代器
    auto last = std::unique(vec.begin(), vec.end());

    // 使用erase方法删除重复元素后的冗余元素
    vec.erase(last, vec.end());
}

int main() {
    std::vector<int> numbers;
    int input;

    std::cout << "请输入一系列整数（输入非整数以结束）：" << std::endl;

    // 从标准输入读取整数并添加到vector中
    while (std::cin >> input) {
        numbers.push_back(input);
    }

    // 调用uniqueSort函数对vector进行去重和排序
    uniqueSort(numbers);

    // 打印处理后的容器元素
    std::cout << "处理后的容器元素为：" << std::endl;
    for (const auto &num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
