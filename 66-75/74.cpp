class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int n = matrix.size() , m = matrix[0].size();
        int l = 0, r = m*n - 1;
        while(l < r) {
            int mid = (r-l)/2 + l;
            int a = matrix[mid/m][mid%m];
            if(a < target) {
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return matrix[l/m][l%m] == target;
    }
};