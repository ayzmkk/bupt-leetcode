class Solution {
public:
    vector<vector<int>> ThreeSum(vector<int>& nums, int index , int target) {
        vector<vector<int>> res;
        for(int i=index;i<nums.size();i++) {
            if(i != index && nums[i] == nums[i-1]) continue;
            int l = i + 1 , r = nums.size() - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target) {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[l]);
                    v.push_back(nums[r]);
                    res.push_back(v);
                    l += 1;
                    while(l < r && nums[l] == nums[l-1]) l++;
                }else if(sum < target){
                    l++;
                }else {
                    r--;
                }
            }
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++) {
            if(i != 0 && nums[i] == nums[i-1]) continue;
            auto tmp = ThreeSum(nums,i+1,target - nums[i]);
            for(auto vec : tmp) {
                vector<int> v;
                v.push_back(nums[i]);
                for(auto num : vec) v.push_back(num);
                res.push_back(v);
            }
        }
        return res;
    }
};