#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int leng = s.length();
        string ans(leng,' ');
        if(numRows==1)  return s;
        int span = 2*numRows - 2,p=0;
        for(int i=0;i<leng;i+=span)
        {
          ans[p++] = s[i];
        }
        for(int i=1;i<numRows-1;i++)
        {
          int inter = 2*i;
          for(int j=i;j<leng;j+=inter)
          {
            ans[p++] = s[j];
            inter = span - inter;
          }
        }
        for(int i=numRows-1;i<leng;i+=span)
        {
          ans[p++] = s[i];
        }
        return ans;
    }
};

int main()
{
  Solution s;
  cout<<s.convert("PAYPALISHIRING",3)<<endl;

  //这个样例要注意！！
  cout<<s.convert("A",1)<<endl;
  return 0;
}
