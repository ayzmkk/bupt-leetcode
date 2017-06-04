class Solution {
public:
    void dfs(vector<string> &res, string &path, int lc , int rc , int n) {
        if(path.size() == 2*n) {
            res.push_back(path);
            return;
        }
        if(lc < n && lc >= rc) {
            path.push_back('(');
            dfs(res,path,lc+1,rc,n);
            path.pop_back();
        }
        if(rc < n && rc < lc) {
            path.push_back(')');
            dfs(res,path,lc,rc+1,n);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int num = 0;
        vector<string> res;
        string path;
        dfs(res,path,num,num,n);
        return res;
    }
};