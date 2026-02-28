#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        vector<bool> cols(n, false);
        vector<bool> d1(2 * n, false);
        vector<bool> d2(2 * n, false);

        solve(0, n, board, result, cols, d1, d2);
        return result;
    }

private:
    void solve(int row, int n, vector<string>& board, vector<vector<string>>& result,
               vector<bool>& cols, vector<bool>& d1, vector<bool>& d2) {

        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int id1 = row - col + n;
            int id2 = row + col;

            if (!cols[col] && !d1[id1] && !d2[id2]) {
                board[row][col] = 'Q';
                cols[col] = d1[id1] = d2[id2] = true;

                solve(row + 1, n, board, result, cols, d1, d2);

                board[row][col] = '.';
                cols[col] = d1[id1] = d2[id2] = false;
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    Solution s;
    vector<vector<string>> solutions = s.solveNQueens(n);

    cout << "\nTotal solutions: " << solutions.size() << "\n\n";

    int count = 1;
    for (auto &board : solutions) {
        cout << "Solution " << count++ << ":\n\n";

        // Print top border
        cout << "+";
        for (int i = 0; i < n; i++) cout << "---+";
        cout << "\n";

        // Print each row in SQL-table style
        for (auto &row : board) {
            cout << "|";
            for (char c : row) {
                cout << " " << c << " |";
            }
            cout << "\n";

            // Row separator
            cout << "+";
            for (int i = 0; i < n; i++) cout << "---+";
            cout << "\n";
        }

        cout << "\n";
    }

    return 0;
}