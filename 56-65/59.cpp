class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,-1));
        int num = n*n;
        int cur = 1;
        int i = 0 , j = 0 , op = 0;
        while(cur <= num) {
            res[i][j] = cur;
            if(op == 0) {
                if(j + 1 < n && res[i][j+1] == -1) {
                    j += 1;
                }else {
                    i += 1;
                    op = 1;
                }
            }else if(op == 1) {
                if(i + 1 < n && res[i+1][j] == -1) {
                    i += 1;
                }else {
                    j -= 1;
                    op = 2;
                }
            }else if(op == 2) {
                if(j - 1 >= 0 && res[i][j-1] == -1) {
                    j -= 1;
                }else {
                    i -= 1;
                    op = 3;
                }
            }else {
                if(i - 1 >= 0 && res[i-1][j] == -1) {
                    i -= 1;
                }else {
                    j += 1;
                    op = 0;
                }
            }
            cur += 1;
        }
        return res;
    }
    
};