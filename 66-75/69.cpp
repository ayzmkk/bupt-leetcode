class Solution {
public:
    int mySqrt(int x) {
        if(x <= 0) return x;
        int l = 1 , r = x;
        while(l <= r) {
            int mid = (r-l)/2 + l;
            if(mid == x / mid && x % mid == 0) return mid;
            else if(mid < x/mid) {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        return min(l,x/l);
    }
};