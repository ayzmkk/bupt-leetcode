class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3,0);
        int k = 0;
        for(auto num : nums) v[num]++;
        for(int i=0;i<3;i++) {
            int n = v[i];
            for(int j=0;j<n;j++) nums[k++] = i;
        }
    }
};