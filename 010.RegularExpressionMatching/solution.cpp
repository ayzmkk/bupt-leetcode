#include<iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
      if(p.empty()) return s.empty();
      if(p.length()==1)
        return (s.length()==1 && (s[0] == p[0]||p[0]=='.'));
      if(p.length()>1 && p[1] == '*')
      {
        //带*匹配0次
        if(isMatch(s,p.substr(2))) return true;

        if(s.empty()) return false;  //这条语句不能放在匹配0次之前，因为s和p可能被去成空了。
        //带*匹配一次或多次
        if(s[0]==p[0] || p[0]=='.')
        {
          return isMatch(s.substr(1),p);
        }
      }
      else
      {
        if(s.empty()) return false;
        if(s[0]==p[0]||p[0]=='.')
        {
          //正常匹配
          return isMatch(s.substr(1),p.substr(1));
        }
      }
      return false;
    }
};

int main()
{
  Solution s;
  cout<<s.isMatch("a", "a*")<<endl;
  cout<<s.isMatch("aa","a")<<endl;
  cout<<s.isMatch("aa","aa")<<endl;
  cout<<s.isMatch("aaa","aa")<<endl;
  cout<<s.isMatch("aa", "a*")<<endl;
  cout<<s.isMatch("aa", ".*")<<endl;
  cout<<s.isMatch("ab", ".*")<<endl;
  cout<<s.isMatch("aab", "c*a*b")<<endl;
}
