class Solution {
public:
    bool check_small(int r, int c, vector<vector<char>>& board) {
        vector<int> meet(9,false);
        for(int i = r; i < r + 3; i++) {
            for(int j = c; j < c + 3; j++) {
                if(board[i][j] == '.') continue;
                if(meet[board[i][j] - '1']) return false;
                meet[board[i][j] - '1'] = true;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i+= 3) {
            for(int j = 0; j < m; j += 3) {
                if(!check_small(i,j,board)) return false;
            }
        }
        vector<vector<int>> row(n,vector<int>(9,false));
        vector<vector<int>> col(m,vector<int>(9,false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == '.') continue;
                if(row[i][board[i][j] - '1']) return false;
                if(col[j][board[i][j] - '1']) return false;
                row[i][board[i][j] - '1'] = true;
                col[j][board[i][j] - '1'] = true;
            }
        }
        return true;
    }
};