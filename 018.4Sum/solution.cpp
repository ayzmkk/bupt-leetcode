#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
      vector<vector<int> > res;
      sort(nums.begin(),nums.end());
      int len = nums.size();

      for(int i=0;i<len-3;i++)
      {
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int l=i+1;l<len-2;l++)
        {
          if(l>i+1 && nums[l]==nums[l-1]) continue;
          int theTarget = -nums[i]-nums[l]+target;
          int j=l+1;
          int k=len-1;
          while(j<k)
          {
            if(nums[j]+nums[k]<theTarget) j++;
            else if(nums[j]+nums[k]>theTarget) k--;
            else
            {
              vector<int> four;
              four.push_back(nums[i]),four.push_back(nums[l]);
              four.push_back(nums[j]),four.push_back(nums[k]);
              res.push_back(four);
              j++,k--;
              while(j<len-1 && nums[j]==nums[j-1]) j++;
              while(k>0 && nums[k]==nums[k+1]) k--;
            }
          }
        }
      }
      return res;
    }
};

int main()
{
  Solution s;
  int myarray[] = {1, 0, -1, 0, -2, 2};
  vector<int> v(myarray,myarray+6);
  vector<vector<int> > res = s.fourSum(v,0);
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
