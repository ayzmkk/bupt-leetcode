class Solution {
public:
    unordered_map<int,string> key;
    void build() {
        key[1] = "";
        key[2] = "abc";
        key[3] = "def";
        key[4] = "ghi";
        key[5] = "jkl";
        key[6] = "mno";
        key[7] = "pqrs";
        key[8] = "tuv";
        key[9] = "wxyz";
    }
    void dfs(vector<string> &res, string & path, int index, string &digits) {
        if(index == digits.size()) {
            res.push_back(path);
            return;
        }
        int k = digits[index] - '0';
        for(auto c : key[k]) {
            path.push_back(c);
            dfs(res,path,index+1,digits);
            path.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string path;
        build();
        if(digits.empty()) return res;
        int index = 0;
        dfs(res,path,index,digits);
        return res;
    }
};