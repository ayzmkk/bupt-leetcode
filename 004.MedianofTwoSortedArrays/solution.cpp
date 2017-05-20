#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int m = nums1.size(),n = nums2.size();
      int len = m+n;
      vector<int> all;
      for(int i=0;i<m;i++)
        all.push_back(nums1[i]);
      for(int i=0;i<n;i++)
        all.push_back(nums2[i]);
      sort(all.begin(),all.end());
      len-=1;
      if(len&1)
      {
        return (all[len>>1]+all[(len>>1)+1])/2.0;
      }
      return all[len>>1];
    }
};

int main()
{
  Solution s;
  vector<int> a;
  vector<int> b;
  a.push_back(1); a.push_back(2);
  b.push_back(3); b.push_back(4);
  cout<<s.findMedianSortedArrays(a,b)<<endl;
}
