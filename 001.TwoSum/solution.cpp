#include<vector>
#include<map>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        // 定义一个map,用来存放元素到下标的映射
        map<int, int> mapping;

        int length = nums.size();
        for(int i=0;i<length;i++)
        {
          mapping[nums[i]]=i;
        }
        for(int i=0;i<length;i++)
        {
          int searched = target - nums[i];
          //看差值能否在map中找到，并且下标不等于当前的
          if(mapping.find(searched)!=mapping.end()&&mapping[searched]!=i)
          {
            res.push_back(i);
            res.push_back(mapping[searched]);
            break;
          }
        }
        return res;
    }
};

int main()
{
  Solution s;
  vector<int> v;
  v.push_back(3);
  v.push_back(2);
  v.push_back(4);

  vector<int> res;
  res = s.twoSum(v,6);
  cout<<res[0]<<" "<<res[1]<<endl;
  cout<<v[res[0]]<<" "<<v[res[1]]<<endl;
  return 0;
}
