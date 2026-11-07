class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<int>> rows (9);
        std::vector<std::unordered_set<int>> cols (9);
        std::vector<std::unordered_set<int>> sqrs (9);
        for(size_t i{}; i < board.size(); i++) {
            for(size_t j{}; j < board.size(); j++) {

                // check rows
                if (board[i][j] != '.') {
                    if (!rows[i].contains(board[i][j])) {
                        rows[i].insert(board[i][j]);
                    } 
                    else {
                        return false;
                    }
                }

                // check columns
                if (board[i][j] != '.') {
                    if (!cols[j].contains(board[i][j])) {
                        cols[j].insert(board[i][j]);
                    }
                    else {
                        return false;
                    }
                }

                if (board[i][j] != '.') {
                    if (!sqrs[((i / 3) * 3)  + j / 3].contains(board[i][j])) {
                        sqrs[((i / 3) * 3)  + j / 3].insert(board[i][j]); 
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
