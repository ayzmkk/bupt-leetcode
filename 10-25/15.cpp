class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++) {
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1 , r = nums.size() - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0) {
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[l]);
                    t.push_back(nums[r]);
                    res.push_back(t);
                    l += 1;
                    while(l < r && nums[l] == nums[l-1]) l++;
                }else if(sum < 0) {
                    l++;
                }else {
                    r--;
                }
            }
        }
        return res;
    }
};