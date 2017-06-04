class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<int,int> key;
        key['I'] = 1;
        key['V'] = 5;
        key['X'] = 10;
        key['L'] = 50;
        key['C'] = 100;
        key['D'] = 500;
        key['M'] = 1000;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(i > 0) {
                if(key[s[i]] > key[s[i-1]]) res -= key[s[i-1]];
                else res += key[s[i-1]];
            }
            if(i == n-1) res += key[s[i]];
        }
        return res;
    }
};