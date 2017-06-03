class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) nums[i] = -1;
        }
        unordered_map<int, int> sumToIndex;
        sumToIndex[0] = -1;
        int sum = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sumToIndex.find(sum) != sumToIndex.end()) {
                ret = max(ret, i - sumToIndex[sum]);
            }
            else sumToIndex[sum] = i;
        }
        return ret;
    }
};
