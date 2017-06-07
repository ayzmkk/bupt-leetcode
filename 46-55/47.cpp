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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> A;
        A.push_back(1);
        A.push_back(1);
        for(int i=2;i<=nums.size();i++) {
            A.push_back(A[i-1]*i);
        }
        int num = A[nums.size()];
        unordered_map<int,int> mp;
        for(auto num : nums) mp[num]++;
        for(auto it : mp) {
            if(it.second > 1) {
                num /= A[it.second];
            }
        }
        vector<vector<int>> res;
        while(num--) {
            res.push_back(nums);
            nextPermutation(nums);
        }
        return res;
    }
};