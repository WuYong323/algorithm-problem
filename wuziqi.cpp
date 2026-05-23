#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Wuziqi {
private:
    vector<vector<char> > board;
    int size;
    char currentPlayer;
    bool gameOver;

public:
    Wuziqi(int s = 15) : size(s), currentPlayer('X'), gameOver(false) {
        board.resize(size, vector<char>(size, ' '));
    }

    void printBoard() {
        // 打印列号
        cout << "   ";
        for (int i = 0; i < size; i++) {
            if (i < 10)
                cout << i << "  ";
            else
                cout << i << " ";
        }
        cout << endl;

        // 打印棋盘
        for (int i = 0; i < size; i++) {
            // 打印行号
            if (i < 10)
                cout << i << "  ";
            else
                cout << i << " ";

            for (int j = 0; j < size; j++) {
                cout << board[i][j];
                if (j < size - 1)
                    cout << "---";
            }
            cout << endl;

            // 打印分隔线
            if (i < size - 1) {
                cout << "   ";
                for (int j = 0; j < size; j++) {
                    cout << "|";
                    if (j < size - 1)
                        cout << "  ";
                }
                cout << endl;
            }
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= size || col < 0 || col >= size) {
            cout << "位置超出范围！请重新输入。" << endl;
            return false;
        }
        if (board[row][col] != ' ') {
            cout << "该位置已有棋子！请重新输入。" << endl;
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin(int row, int col) {
        char player = board[row][col];

        // 检查水平方向
        int count = 1;
        for (int i = col - 1; i >= 0 && board[row][i] == player; i--) count++;
        for (int i = col + 1; i < size && board[row][i] == player; i++) count++;
        if (count >= 5) return true;

        // 检查垂直方向
        count = 1;
        for (int i = row - 1; i >= 0 && board[i][col] == player; i--) count++;
        for (int i = row + 1; i < size && board[i][col] == player; i++) count++;
        if (count >= 5) return true;

        // 检查对角线方向（左上到右下）
        count = 1;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0 && board[i][j] == player; i--, j--) count++;
        for (int i = row + 1, j = col + 1; i < size && j < size && board[i][j] == player; i++, j++) count++;
        if (count >= 5) return true;

        // 检查反对角线方向（右上到左下）
        count = 1;
        for (int i = row - 1, j = col + 1; i >= 0 && j < size && board[i][j] == player; i--, j++) count++;
        for (int i = row + 1, j = col - 1; i < size && j >= 0 && board[i][j] == player; i++, j--) count++;
        if (count >= 5) return true;

        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        cout << "===================================" << endl;
        cout << "        欢迎来到五子棋游戏！" << endl;
        cout << "===================================" << endl;
        cout << "游戏规则：" << endl;
        cout << "  - 两位玩家轮流落子" << endl;
        cout << "  - 玩家X先手，玩家O后手" << endl;
        cout << "  - 先连成5子的一方获胜" << endl;
        cout << "  - 输入坐标时，先输入行，再输入列" << endl;
        cout << "===================================" << endl << endl;

        while (!gameOver) {
            printBoard();
            cout << "\n玩家 " << currentPlayer << " 的回合" << endl;
            cout << "请输入落子位置（行 列）：";

            int row, col;
            cin >> row >> col;

            if (makeMove(row, col)) {
                if (checkWin(row, col)) {
                    printBoard();
                    cout << "\n===================================" << endl;
                    cout << "  恭喜玩家 " << currentPlayer << " 获胜！" << endl;
                    cout << "===================================" << endl;
                    gameOver = true;
                } else if (checkDraw()) {
                    printBoard();
                    cout << "\n===================================" << endl;
                    cout << "      平局！棋盘已满。" << endl;
                    cout << "===================================" << endl;
                    gameOver = true;
                } else {
                    switchPlayer();
                }
            }
        }
    }
};

int main() {
    Wuziqi game;
    game.play();
    return 0;
}
