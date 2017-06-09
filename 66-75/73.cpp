class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        bool first_col = false;
        bool first_row = false;
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0;i<n;i++) {
            if(matrix[i][0] == 0) first_col = true;
        }
        for(int j=0;j<m;j++) {
            if(matrix[0][j] == 0) first_row = true;
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(first_col) {
            for(int i=0;i<n;i++) {
                matrix[i][0] = 0;
            }
        }
        if(first_row) {
             for(int j=0;j<m;j++) {
                matrix[0][j] = 0;
            }
        }
     }
};