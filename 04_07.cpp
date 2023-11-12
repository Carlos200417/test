#include <iostream>
#include <vector>

// 判断在当前位置放置皇后是否合法
bool isSafe(const std::vector<int>& board, int row, int col) {
    // 检查该列是否有皇后
    for (int i = 0; i < row; ++i) {
        if (board[i] == col ||          // 检查同一列
            board[i] - i == col - row || // 检查左上到右下的对角线
            board[i] + i == col + row)   // 检查左下到右上的对角线
        {
            return false;
        }
    }
    return true;
}

// 递归函数，尝试在每一行放置皇后
bool solveQueens(std::vector<int>& board, int row, int b) {
    if (row == 8) {
        // 当成功摆放八个皇后时，输出对应的皇后串
        if (--b == 0) {
            for (int i = 0; i < 8; ++i) {
                std::cout << board[i] + 1; // 输出的列数是从1开始
            }
            std::cout << std::endl;
            return true;
        }
        return false;
    }

    // 尝试在当前行的每一列放置皇后
    for (int col = 0; col < 8; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            if (solveQueens(board, row + 1, b)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int b;
        std::cin >> b;

        std::vector<int> board(8, 0);
        solveQueens(board, 0, b);
    }

    return 0;
}
