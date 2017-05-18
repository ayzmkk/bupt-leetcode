#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if(s.length()<1)
        return 0;
      map <char,int> mp;
      mp[s[0]] = 0;
      int res =1,left =0;
      for(int i=1;i<s.length();i++)
      {
        if(mp.find(s[i])==mp.end() || mp[s[i]]<left)
        {
          res = max(res,i-left+1);
        }
        else
        {
          left = mp[s[i]] +1;
        }
        mp[s[i]] = i;
      }
      return res;
    }
};

int main()
{
  string str;
  Solution s;
  while(cin>>str)
  {
    cout<<s.lengthOfLongestSubstring(str)<<endl;
  }
  return 0;
}

/*
abcabcbb
bbbbb
pwwkew
pwpkew
*/
