#include<iostream>
using namespace std;

/*
用的解法是O(N^2)的
其实还有O(N)的算法，待做！！
这题是最长回文子串，最长回文子序列待做！
*/

class Solution {
public:
    string longestPalindrome(string s) {
      int left=0,res=1;
      int leng = s.length();
      if(leng==0) return "";

      for(int i=0;i<leng;i++)
      {
        for(int j=0;(i-j>=0)&&(i+j<leng);j++)
        {
            if(s[i-j]==s[i+j])
            {
              if(2*j+1>res)
              {
                res = 2*j+1;
                left = i-j;
              }
            }
            else
              break;
        }
        for(int j=0;(i-j>=0)&&(i+j+1<leng);j++)
        {
            if(s[i-j]==s[i+j+1])
            {
              if(2*j+2>res)
              {
                res = 2*j+2;
                left = i-j;
              }
            }
            else
              break;
        }
      }

      return s.substr(left,res);
    }
};

int main()
{
  Solution s;
  cout<<s.longestPalindrome("bab")<<endl;
  cout<<s.longestPalindrome("aaaa")<<endl;
  cout<<s.longestPalindrome("ccc")<<endl;
  cout<<s.longestPalindrome("babad")<<endl;
  cout<<s.longestPalindrome("cbbd")<<endl;
}
