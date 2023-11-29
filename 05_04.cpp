#include <iostream>
using namespace std; //使用namespace，后面不用std了

class Student {
private: //私有，定义学生信息
    string name;
    string className;
    string studentID;
    int score;
    static int count; // 静态变量，用于统计对象总数

public:
    Student(string n, string c, string id, int s)
        : name(n), className(c), studentID(id), score(s) {
        count++; // 每次创建对象时增加对象总数
    }

    void displayInfo() {
        cout << "姓名: " << name << endl;
        cout << "班级: " << className << endl;
        cout << "学号: " << studentID << endl;
        cout << "分数: " << score << endl;
        cout << "成绩等级: " << getGrade() << endl;
    }

    char getGrade() {
        if (score >= 90) {
            return 'A';
        } else if (score >= 80) {
            return 'B';
        } else if (score >= 70) {
            return 'C';
        } else {
            return 'D';
        }
    }

    static int getCount() {
        return count; // 返回对象总数
    }
};

int Student::count = 0; // 初始化静态变量为 0

int main() {
    Student student1("Sinner", "Class A", "221112010", 85);
    Student student2("Shelton", "Class B", "221112011", 75);
    Student student3("Aracaz", "Class C", "221112012", 92);

    cout << "学生信息：" << endl;
    student1.displayInfo();
    student2.displayInfo();
    student3.displayInfo();

    cout << "总共创建了 " << Student::getCount() << " 个学生对象。" << endl;

    return 0;
}
