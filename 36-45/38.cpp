class Solution {
public:
    string countAndSay(int n) {
        int k = 1;
        string res = "1";
        while(k < n) {
            string t;
            for(int i = 0; i < res.size(); ) {
                int cnt = 0;
                int pos = i;
                while(pos < res.size() && res[i] == res[pos]) {
                    pos++;
                    cnt++;
                }
                t += to_string(cnt);
                t.push_back(res[i]);
                i = pos;
            }
            res = t;
            k++;
        }
        return res;
    }
};