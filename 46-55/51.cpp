class Solution {
public:
    vector<bool> col;
    unordered_map<int,bool> diag;
    unordered_map<int,bool> anti_diag;
    void dfs(int index, vector<vector<string>> &res, vector<string> &path , int n) {
        if(index == n) {
            res.push_back(path);
            return;
        }
        int i = index;
        for(int j = 0; j < n ; j ++) {
            if(!col[j] && !diag[j-i] && !anti_diag[i+j]) {
                col[j] = diag[j-i] = anti_diag[i+j] = true;
                path[index][j] = 'Q';
                dfs(index+1,res,path,n);
                col[j] = diag[j-i] = anti_diag[i+j] = false;
                path[index][j] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        col.assign(n,false);
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0; j < n ; j++) {
                diag[i-j] = false;
                anti_diag[i+j] = false;
            }
        }
        string t(n,'.');
        vector<vector<string>> res;
        vector<string> path(n,t);
        int index = 0;
        dfs(index,res,path,n);
        return res;
    }
};