class Solution {
public:
    double myPow(double x, int n) {
        bool neg = (x < 0) && (n % 2 == 1);
        double base = fabs(x);
        bool rever = n < 0;
        long long b = labs(n);
        double res = 1.0;
        while(b) {
            if(b & 1) {
                res *= base;
            }
            base = base * base;
            b >>= 1;
        }
        if(neg) res = 0 - res;
        if(rever) res = 1 / res;
        return res;
    }
};