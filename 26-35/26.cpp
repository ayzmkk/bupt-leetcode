class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for(int i=0;i<nums.size();) {
            int pos = i+1;
            int cnt = 0;
            while(pos < nums.size() && nums[pos] == nums[i]) {
                pos++;
                cnt++;
            }
            nums[j++] = nums[i];
            i = pos;
        }
        return j;
    }
};