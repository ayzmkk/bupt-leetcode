class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int len = 0;
        for(int i = 0; i < s.size();) {
            int pos = i;
            while(pos < s.size() && s[pos] != ' ') pos++;
            if(pos != i) len = pos - i;
            i = pos + 1;
        }
        return len;
    }
};