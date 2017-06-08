class Solution {
public:
    long long c(int a, int b) {
        long long divi = 1;
        long long densor = 1;
        int n = b;
        for(int i=0;i<n;i++) {
            divi *= (a-i);
            densor *= (b-i);
            if(divi % densor == 0) {
                divi /= densor;
                densor = 1;
            }
        }
        return divi;
    }
    int uniquePaths(int m, int n) {
        m-=1;
        n-=1;
        int a = m+n;
        int b = n;
        if(b > a/2) b = m;
        return c(a,b);
    }
};