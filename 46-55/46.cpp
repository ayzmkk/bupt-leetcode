class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int i = 0, n = nums.size();
        for(i = n - 1; i >= 1; i--) {
            if(nums[i] > nums[i-1]) {
                for(int j = n-1; j >= i; j--) {
                    if(nums[j] > nums[i-1]) {
                        swap(nums[j],nums[i-1]);
                        break;
                    }
                }
                break;
            }
        }
        reverse(nums.begin()+i,nums.end());
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int num = 1;
        vector<vector<int>> res;
        for(int i=1;i<=nums.size();i++) {
            num *= i;
        }
        while(num--) {
            res.push_back(nums);
            nextPermutation(nums);
        }
        return res;
    }
};