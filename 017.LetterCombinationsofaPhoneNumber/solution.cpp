#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
      vector<string> res;
      int len = digits.size();
      if(len==0) return res;
      res.push_back("");
      
      string phone[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      for(int i=0;i<len;i++)
      {
        int pos = digits[i]-'2';
        int res_len = res.size();
        int phone_len = phone[pos].size();
        for(int j=0;j<res_len;j++)
        {
          //用res.front() 如果用res[0]会出现问题！！
          string tmp = res.front();
          res.erase(res.begin());
          for(int k=0;k<phone_len;k++)
          {
            res.push_back(tmp+phone[pos][k]);
          }
        }
      }
      return res;
    }
};

int main()
{
  Solution s;
  vector<string> res = s.letterCombinations("23");
  int len = res.size();
  for(int i=0;i<len;i++)
  {
    cout<<res[i]<<endl;
  }
  return 0;
}
