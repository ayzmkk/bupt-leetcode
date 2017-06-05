class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int l = 0 , r = nums.size() - 1;
        while(l < r) {
            int mid =  (r-l)/2 + l;
            if(nums[mid] >= target) {
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        return nums[l] == target ? l : -1;
    }
    int upper_bound(vector<int>& nums, int target) {
        int l = 0 , r = nums.size() - 1;
        while(l < r) {
            int mid =  (r-l)/2 + l + 1;
            if(nums[mid] <= target) {
                l = mid;
            }else {
                r = mid - 1;
            }
        }
        return nums[l] == target ? l : -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.empty()) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int l = lower_bound(nums,target);
        if(l == -1) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int r = upper_bound(nums,target);
        res.push_back(l);
        res.push_back(r);
        return res;
    }
};