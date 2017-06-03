#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
      generate("",0,0,n);
      return res;
    }

    void generate(string s,int l,int r,int n)
    {
      if(r == n)
      {
        res.push_back(s);
        return;
      }
      if(l < n) generate(s+"(",l+1,r,n);
      if(r < l) generate(s+")",l,r+1,n);
    }
};

int main()
{
  Solution s;
  vector<string> res = s.generateParenthesis(3);
  int len = res.size();
  for(int i=0;i<len;i++)
    cout<<res[i]<<endl;
  return 0;
}
