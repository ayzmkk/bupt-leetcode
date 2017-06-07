class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> res;
        if(a.empty() || a[0].empty()) return res;
        int i = 0 , j = 0;
        int n = a.size() , m = a[0].size();
        int op = 1;
        while(res.size() < n*m) {
            res.push_back(a[i][j]);
            a[i][j] = INT_MIN;
            if(op == 1) {
                if(j+1 < m && a[i][j+1] != INT_MIN) {
                    j += 1;
                }else {
                    i += 1;
                    op = 2;
                }
            }
            else if(op == 2) {
                if(i + 1 < n && a[i+1][j] != INT_MIN) {
                    i += 1;
                }else {
                    j -= 1;
                    op = 3;
                }
            }
            else if(op == 3) {
                if(j - 1 >= 0 && a[i][j-1] != INT_MIN) {
                    j -= 1;
                }else {
                    i -= 1;
                    op = 4;
                }
            }else {
                if(i - 1 >= 0 && a[i-1][j] != INT_MIN) {
                    i -= 1;
                }else {
                    j += 1;
                    op = 1;
                }
            }
        }
        return res;
    }
};