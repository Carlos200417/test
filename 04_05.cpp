#include <iostream>
#include <vector>

struct Student {
    std::string name;
    int averageScore;
    int evaluationScore;
    char isCadre;  // 是否是学生干部
    char isWestern;  // 是否是西部省份学生
    int paperCount;  // 论文数
};

// 计算奖金总数
int calculateScholarship(const Student& student) {
    int totalScholarship = 0;

    if (student.averageScore > 80 && student.paperCount >= 1) {
        totalScholarship += 8000;
    }
    if (student.averageScore > 85 && student.evaluationScore > 80) {
        totalScholarship += 4000;
    }
    if (student.averageScore > 90) {
        totalScholarship += 2000;
    }
    if (student.averageScore > 85 && student.isWestern == 'Y') {
        totalScholarship += 1000;
    }
    if (student.evaluationScore > 80 && student.isCadre == 'Y') {
        totalScholarship += 850;
    }

    return totalScholarship;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Student> students(N);

    // 读取学生数据
    for (int i = 0; i < N; ++i) {
        std::cin >> students[i].name >> students[i].averageScore >> students[i].evaluationScore
                >> students[i].isCadre >> students[i].isWestern >> students[i].paperCount;
    }

    std::string maxScholarshipName;  // 获得最多奖金的学生姓名
    int maxScholarship = 0;  // 最多奖金总数
    int totalScholarship = 0;  // 所有学生的奖学金总数

    // 遍历每位学生，计算奖学金总数
    for (const auto& student : students) {
        int scholarship = calculateScholarship(student);

        // 更新最多奖金的学生信息
        if (scholarship > maxScholarship) {
            maxScholarship = scholarship;
            maxScholarshipName = student.name;
        }

        totalScholarship += scholarship;
    }

    // 输出结果
    std::cout << maxScholarshipName << std::endl;
    std::cout << maxScholarship << std::endl;
    std::cout << totalScholarship << std::endl;

    return 0;
}
