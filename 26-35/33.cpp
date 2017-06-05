class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int l = 0 , r = nums.size() - 1;
        while(l < r) {
            int mid = (r-l)/2 + l;
            if(nums[mid] > nums[r]) {
                if(nums[l] <= target && nums[mid] >= target) {
                    r = mid;
                }else {
                    l = mid + 1;
                }
            }else {
                if(nums[mid] < target && nums[r] >= target) {
                    l = mid + 1;
                }else {
                    r = mid;
                }
            }
        }
        return nums[l] == target ? l : -1;
    }
};