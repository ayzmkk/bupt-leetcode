class Solution {
public:
    void dfs(vector<int> &cand, int index, int cur_sum , int target, vector<int> &path, vector<vector<int>> &res) {
        if(cur_sum > target) return;
        else if(cur_sum == target) {
            res.push_back(path);
            return;
        }
        for(int i = index; i < cand.size();i++) {
            path.push_back(cand[i]);
            dfs(cand,i,cur_sum+cand[i],target,path,res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> res;
        dfs(candidates,0,0,target,path,res);
        return res;
    }
};