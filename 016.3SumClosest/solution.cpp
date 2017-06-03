#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int res = 0,diff = INT_MAX;
      int len = nums.size();
      sort(nums.begin(),nums.end());
      for(int i=0;i<len;i++)
      {
        if(i>0 && nums[i]==nums[i-1]) continue;
        int theTarget = target - nums[i];
        int j = i+1,k=len-1;
        while(j<k)
        {
          if(abs(nums[i]+nums[j]+nums[k]-target)<diff)
          {
            diff = abs(nums[i]+nums[j]+nums[k]-target);
            res = nums[i]+nums[j]+nums[k];
          }
          if(nums[j]+nums[k]<theTarget) j++;
          else if(nums[j]+nums[k]>theTarget) k--;
          else
          {
            return target;
          }
        }
      }
      return res;
    }
};

int main()
{
  Solution s;
  int myArray[] = {-1, 2, 1, -4},target=1;
  vector<int> v(myArray,myArray+5);
  cout<<s.threeSumClosest(v,target)<<endl;
  return 0;
}
