class Solution {
public:
    int jump(vector<int>& nums) {
        int canReach = 0 , nextReach = 0;
        int jump = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            if(i > canReach) {
                canReach = nextReach;
                jump += 1;
            }
            nextReach = max(nextReach, nums[i] + i);
        }
        return jump;
    }
};