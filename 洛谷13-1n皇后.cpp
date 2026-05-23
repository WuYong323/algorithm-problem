#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NQueens {
private:
    int n;
    vector<vector<int>> solutions;
    vector<int> current;
    vector<bool> col_used;
    vector<bool> diag1_used;
    vector<bool> diag2_used;

    void backtrack(int row) {
        if (row == n) {
            solutions.push_back(current);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            int d1 = row - col + n;//对角线
            int d2 = row + col;//副对角线
            
            if (!col_used[col] && !diag1_used[d1] && !diag2_used[d2]) {
                col_used[col] = true;
                diag1_used[d1] = true;
                diag2_used[d2] = true;
                current[row] = col + 1;
                
                backtrack(row + 1);
                
                col_used[col] = false;
                diag1_used[d1] = false;
                diag2_used[d2] = false;
            }
        }
    }

public:
    NQueens(int size) : n(size) {
        current.resize(n, 0);
        col_used.resize(n, false);
        diag1_used.resize(2 * n, false);
        diag2_used.resize(2 * n, false);
    }
    
    void solve() {
        backtrack(0);
    }
    
    void printSolutions() {
        // 输出前3个解
        for (int i = 0; i < min(3, (int)solutions.size()); i++) {
            for (int j = 0; j < n; j++) {
                cout << solutions[i][j];
                if (j < n - 1) cout << " ";
            }
            cout << endl;
        }
        // 输出解的总数
        cout << solutions.size() << endl;
    }
};

int main() {
    int n;
    cin >> n;
    
    NQueens solver(n);
    solver.solve();
    solver.printSolutions();
    
    return 0;
}