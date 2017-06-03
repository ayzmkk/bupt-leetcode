#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0,j = height.size()-1;
        //min(ai,aj) * (j-i)
        while(i<j)
        {
          res = max(res,min(height[i],height[j])*(j-i));
          if(height[i]<=height[j]) i++;
          else j--;
        }
        return res;
    }
};

int main()
{
  Solution s;
  vector<int> v;
  v.push_back(2),v.push_back(3),v.push_back(1),v.push_back(3);
  cout<<s.maxArea(v)<<endl;
  return 0;
}
