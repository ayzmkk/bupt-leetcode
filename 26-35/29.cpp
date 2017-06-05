class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = (dividend > 0) ^ (divisor > 0);
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        long m = labs(dividend) , n = labs(divisor);
        int k = 0;
        while((n << k) <= m) k++; 
        int res = 0;
        while(k >= 0) {
            long t = n << k;
            if(m >= t) {
                res += 1<<k;
                m = m - t;
            }
            k--;
        }
        if(neg) res = 0 - res;
        return res;
    }
};