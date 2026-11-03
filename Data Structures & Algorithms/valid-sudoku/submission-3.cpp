class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<char>> row_vals(9);
        std::vector<std::unordered_set<char>> col_vals(9);
        std::vector<std::unordered_set<char>> square_vals(9);
        for (int i {}; i < 9; i++) {
            for (int j{}; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (row_vals[i].contains(board[i][j])) {
                        return false;
                    } else {
                        row_vals[i].insert(board[i][j]);
                    }
                    int square_idx = (i / 3) * 3 + (j / 3);
                    if (square_vals[square_idx].contains(board[i][j])) {
                        return false;
                    } else {
                        square_vals[square_idx].insert(board[i][j]);
                    }
                }
                if (board[j][i] != '.') {
                    if (col_vals[i].contains(board[j][i])) {
                        return false;
                    } else {
                        col_vals[i].insert(board[j][i]);
                    }
                } 
            }
        }
        return true;
    }
};
