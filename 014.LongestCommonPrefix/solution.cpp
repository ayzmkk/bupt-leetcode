#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string res = "";
      int str_min_len = 1e8,vector_len = strs.size();
      if(vector_len == 0) return res;
      for(int i=0;i<vector_len;i++) str_min_len = min(str_min_len,int(strs[i].size()));
      int flag =0;
      for(int i=0;i<str_min_len;i++)
      {
        for(int j=1;j<vector_len;j++)
        {
          if(strs[j][i]!=strs[0][i])
          {
            flag = 1;
            break;
          }
        }
        if(flag) break;
        res += strs[0][i];
      }
      return res;
    }
};

int main()
{
  Solution s;
  string s1 = "abc";
  string s2 = "abcd";
  string s3 = "abce";
  vector<string> v;
  v.push_back(s1),v.push_back(s2),v.push_back(s3);
  cout<<s.longestCommonPrefix(v)<<endl;
  return 0;
}
