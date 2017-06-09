class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++) dp[i][0] = i;
        for(int j=1;j<=m;j++) dp[0][j] = j;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                int repace = (a[i-1] == b[j-1] ? 0 : 1) + dp[i-1][j-1];
                int delet = dp[i-1][j] + 1;
                int insert = dp[i][j-1] + 1;
                dp[i][j] = min(delet,min(repace,insert));
            }
        }
        return dp[n][m];
    }
};