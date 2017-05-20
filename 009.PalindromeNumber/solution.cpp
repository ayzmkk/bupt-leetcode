#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
      int a[15] = {0},p=0;
      if(x<0) return false;
      while(x)
      {
        a[p++] = x%10;
        x/=10;
      }
      for(int i=0;i<p/2;i++)
      {
        if(a[i]!=a[p-1-i])
          return false;
      }
      return true;
    }
};

int main()
{
  Solution s;
  cout<<s.isPalindrome(123)<<endl;
  cout<<s.isPalindrome(121)<<endl;
  cout<<s.isPalindrome(-121)<<endl;
  return 0;
}
