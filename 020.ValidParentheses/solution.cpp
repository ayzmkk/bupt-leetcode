#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
      stack <int> brackets;
      char left[] = {'(','[','{'};
      char right[] = {')',']','}'};
      int len = s.size();
      for(int i=0;i<len;i++)
      {
        int j;
        for(j=0;j<3;j++)
        {
          if(s[i]==left[j])
          {
            brackets.push(j);
            break;
          }
        }
        if(j<3) continue;

        for(j=0;j<3;j++)
        {
          if(s[i]==right[j])
          {
            if(brackets.empty()) return false;
            int l = brackets.top();
            if(l==j)  brackets.pop();
            else  return false;
            break;
          }
        }
      }
      if(!brackets.empty()) return false;
      return true;
    }
};

int main()
{
  Solution s;
  cout<<s.isValid("(])")<<endl;
  cout<<s.isValid("()")<<endl;
  return 0;
}
