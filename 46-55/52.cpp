class Solution {
public:
    vector<bool> col;
    unordered_map<int,bool> diag;
    unordered_map<int,bool> anti_diag;
    void dfs(int index, int &res, int n) {
        if(index == n) {
            res++;
            return;
        }
        int i = index;
        for(int j = 0; j < n ; j ++) {
            if(!col[j] && !diag[j-i] && !anti_diag[i+j]) {
                col[j] = diag[j-i] = anti_diag[i+j] = true;
                dfs(index+1,res,n);
                col[j] = diag[j-i] = anti_diag[i+j] = false;
                
            }
        }
        return;
    }
    int totalNQueens(int n) {
        col.assign(n,false);
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0; j < n ; j++) {
                diag[i-j] = false;
                anti_diag[i+j] = false;
            }
        }
        int res = 0;
        int index = 0;
        dfs(index,res,n);
        return res;
    }
};