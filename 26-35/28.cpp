class Solution {
public:
    int kmp(string &s , string &t, vector<int> &next) {
        int n = s.size();
        int m = t.size();
        int i = 0 , j = 0;
        while(i < n && j < m) {
            if(j < 0 || s[i] == t[j]) {
                i++;
                j++;
            }else {
                j = next[j];
            }
        }
        if(j == m) {
            return i - m;
        }
        return -1;
    }
    vector<int> get_next(string &t) {
        int n = t.size();
        vector<int> next(n,0);
        next[0] = -1;
        int k = -1;
        int i = 0;
        while(i < n - 1) {
            if(k == -1 || t[k] == t[i]) {
                i++;
                k++;
                next[i] = k;
            }else {
                k = next[k];
            }
        }
        return next;
    }
    int strStr(string s, string t) {
        if(t.empty()) return 0;
        vector<int> next = get_next(t);
        return kmp(s,t,next);
    }
};