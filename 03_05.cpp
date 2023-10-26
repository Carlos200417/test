#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) { //用于检查一个整数是否为质数的函数
    if (num <= 1) {
        return false;
    }
    
    if (num == 2) {
        return true;
    }
    
    if (num % 2 == 0) {
        return false;
    }

    for (int i = 3; i <= sqrt(num); i += 2) { //sqrt用来求平方根
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    cout << "200到300之间的质数有：";
    for (int i = 200; i <= 300; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}
