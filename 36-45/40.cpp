class Solution {
public: 
    void dfs(int cur_sum , int index, int target, vector<vector<int>> &res, vector<int> &path, vector<int> &cand) {
        if(cur_sum > target) return;
        if(cur_sum == target) {
            res.push_back(path);
            return;
        }
        for(int i=index;i<cand.size();i++) {
            if(i != index && cand[i] == cand[i-1]) continue;
            path.push_back(cand[i]);
            dfs(cur_sum+cand[i],i+1,target,res,path,cand);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(0,0,target,res,path,cand);
        return res;
    }
};