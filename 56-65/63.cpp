class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        if(a.empty() || a[0].empty()) return 0;
        int n = a.size() , m = a[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = a[0][0] == 0 ? 1 : 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(a[i][j] == 0) {
                    if(i > 0 ) dp[i][j] += dp[i-1][j];
                    if(j > 0) dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};