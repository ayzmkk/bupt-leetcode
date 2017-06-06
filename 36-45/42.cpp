class Solution {
public:
    int trap(vector<int>& h) {
        if(h.empty()) return 0;
        int res = 0;
        int l = 0, r = h.size() - 1;
        while(l < r) {
            if(h[l] < h[r]) {
                if(l + 1 < r && h[l+1] < h[l]) {
                    res += h[l] - h[l+1];
                    h[l+1] = h[l];
                }
                l+= 1;
            }else {
                if(r - 1 > l && h[r-1] < h[r]) {
                    res += h[r] - h[r-1];
                    h[r-1] = h[r];
                }
                r -=1;
            }
        }
        return res;
    }
};