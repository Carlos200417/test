#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int playerChoice, computerChoice;
    int playerWins = 0, computerWins = 0;
    int totalRounds = 0;
    char playAgain;

    // 初始化随机数生成器
    srand(static_cast<unsigned>(time(0)));

    do {
        cout << "石头剪刀布游戏" << endl;
        cout << "选择：(0)石头, (1)剪刀, (2)布: ";
        cin >> playerChoice;

        // 用rand函数进行随机选择
        computerChoice = rand() % 3;

        cout << "电脑选择了 ";
        switch (computerChoice) {
            case 0:
                cout << "石头" << endl;
                break;
            case 1:
                cout << "剪刀" << endl;
                break;
            case 2:
                cout << "布" << endl;
                break;
        }

        // 判断胜负
        int result = (playerChoice - computerChoice + 3) % 3;
        if (result == 0) {
            cout << "平局!" << endl;
        } else if (result == 1) {
            cout << "您赢了!" << endl;
            playerWins++;
        } else {
            cout << "电脑赢了!" << endl;
            computerWins++;
        }

        totalRounds++;

        cout << "继续游戏吗? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "游戏结束!" << endl;
    cout << "总回合数: " << totalRounds << endl;
    cout << "您赢了 " << playerWins << " 次，电脑赢了 " << computerWins << " 次。" << endl;

    return 0;
}
