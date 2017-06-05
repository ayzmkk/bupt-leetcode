class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        for(;i>0;i--) {
            if(nums[i] > nums[i-1]) {
                for(int j=n-1;j>=i;j--) {
                    if(nums[j] > nums[i-1]) {
                        swap(nums[j],nums[i-1]);
                        break;
                    }
                }
                break;
            }
        }
        reverse(nums.begin() + i, nums.end());
    }
};