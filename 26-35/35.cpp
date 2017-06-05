class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int l = 0 , r = nums.size() - 1;
        while(l < r) {
            int mid = (r-l)/2 + l;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return nums[l] < target ? l + 1 : l;
    }
};