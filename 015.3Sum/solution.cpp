#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
      vector<vector<int> > res;
      sort(nums.begin(),nums.end());
      int len = nums.size();

      for(int i=0;i<len-2;i++)
      {
        if(i>0 && nums[i]==nums[i-1]) continue;
        int target = -nums[i];
        int j=i+1;
        int k=len-1;
        while(j<k)
        {
          if(nums[j]+nums[k]<target) j++;
          else if(nums[j]+nums[k]>target) k--;
          else
          {
            vector<int> three;
            three.push_back(nums[i]),three.push_back(nums[j]),three.push_back(nums[k]);
            res.push_back(three);
            j++,k--;
            while(j<len-1 && nums[j]==nums[j-1]) j++;
            while(k>0 && nums[k]==nums[k+1]) k--;
          }
        }
      }
      return res;
    }
};

int main()
{
  Solution s;
  int myarray[] = {-2,0,1,1,2};
  vector<int> v(myarray,myarray+5);
  vector<vector<int> > res = s.threeSum(v);
  int len = res.size();
  for(int i=0;i<len;i++)
  {
    int t = res[i].size();
    for(int j=0;j<t;j++)
    {
      cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
