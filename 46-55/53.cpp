class Solution {
public:
    int merge_sort(vector<int>& sum, int s, int e) {
        if(s == 0 && e - s == 1) return INT_MIN;
        if(e - s == 1) return sum[s];
        int mid = (e - s) / 2 + s;
        int l = merge_sort(sum,s,mid);
        int r = merge_sort(sum,mid,e);
        int cur_max = sum[e-1] - sum[s];
        vector<int> cache;
        int i = s , j = mid;
        while(i < mid || j < e) {
            int a;
            if(i < mid && j < e)  {
                if(sum[i] < sum[j]) {
                    a = sum[i++];
                }else {
                    a = sum[j++];
                }
            }else if(i < mid) {
                a = sum[i++];
            }else {
                a = sum[j++];
            }
            cache.push_back(a);
        }
        copy(cache.begin(),cache.end(),sum.begin()+s);
        return max(max(cur_max,l),r);
        
    }
    int maxSubArray(vector<int>& nums) {
        vector<int> sum;
        sum.push_back(0);
        int n = nums.size();
        for(auto num : nums) sum.push_back(sum.back()+num);
        return merge_sort(sum,0,n+1);
    }
};