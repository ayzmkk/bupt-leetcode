class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        if(strs.empty()) return prefix;
        int index = 0;
        for(char c : strs[0]) {
            bool flag = true;
            for(auto str : strs) {
                if(str.size() <= index || str[index] != c) {
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
            index += 1;
            prefix.push_back(c);
        }
        return prefix;
    }
};