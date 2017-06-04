class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = INT_MAX;
        int ans = 0;
        for(int i=0;i< n;i++) {
            int l = i + 1, r = n-1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target) {
                    return target;
                }else if(sum > target) {
                    if(res > sum - target) {
                        res = sum - target;
                        ans = sum;
                    }
                    r--;
                }else {
                    if(res > target - sum) {
                        res = target - sum;
                        ans = sum;
                    }
                    l++;
                }
            }
        }
        return ans;
    }
};