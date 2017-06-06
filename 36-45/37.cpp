class Solution {
public:
    vector<vector<int>> row;
    vector<vector<int>> col;
    vector<vector<int>> small;
    vector<pair<int,int>> blank;
    vector<vector<char>> res;
    int n;
    int m;
    void fill_small(int r, int c, vector<vector<char>>& board) {
        vector<int> meet(9,false);
        for(int i = r; i < r + 3; i++) {
            for(int j = c; j < c + 3; j++) {
                if(board[i][j] == '.') continue;
                meet[board[i][j] - '1'] = true;
            }
        }
        cout<<r + c/3<<endl;
        small[(r/3)*3 + c/3] = meet;
        return;
    }
    void fill_row_col(vector<vector<char>>& board) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == '.') {
                    blank.push_back({i,j});   
                    continue;
                }
                row[i][board[i][j] - '1'] = true;
                col[j][board[i][j] - '1'] = true;
            }
        }
    }
    void dfs(int index, vector<vector<char>>& board) {
        if(index == blank.size()) {
            res = board;
            return;
        }
        int i = blank[index].first , j = blank[index].second;
        for(char k = '1'; k <= '9'; k++) {
            if(!small[(i/3) * 3 + j/3][k - '1'] && !row[i][k - '1'] && !col[j][k - '1']) {
                board[i][j] = k;
                small[(i/3) * 3 + j/3][k - '1'] = row[i][k - '1'] = col[j][k - '1'] = true;
                dfs(index + 1, board);
                small[(i/3) * 3 + j/3][k - '1'] = row[i][k - '1'] = col[j][k - '1'] = false;
                board[i][j] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        n = board.size() , m = board[0].size();
        small.assign(9,vector<int>());
        row.assign(n,vector<int>(9,false));
        col.assign(m,vector<int>(9,false));
        fill_row_col(board);
        for(int i = 0; i < n; i+= 3) {
            for(int j = 0; j < m; j += 3) {
                fill_small(i,j,board);
            }
        }
        int index = 0;
        dfs(index,board);
        board = res;
        return;
    }
};