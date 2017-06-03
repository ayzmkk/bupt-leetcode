#include<iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
      if(str.empty()) return 0;
      // res存结果 p记录下标位置, flag表示正负数
      int len = str.length(),res = 0,p=0,flag=1;
      while(p<len && str[p] == ' ') p++;
      if(str[p] == '+' || str[p] == '-')
      {
        if(str[p++] == '+') flag =1;
        else flag = -1;
      }

      for(;p<len&&str[p]>='0'&&str[p]<='9';p++)
      {
        if((res > INT_MAX/10)||(res==INT_MAX/10 && str[p]>'7'))
          return flag == 1 ? INT_MAX : INT_MIN;
        res = res*10 + (str[p]-'0');
      }
      return res*flag;
    }
};


int main()
{
  Solution s;
  cout<<s.myAtoi("1")<<endl;
  cout<<s.myAtoi("123ab123")<<endl;
  cout<<s.myAtoi("-2147483648")<<endl;
  cout<<s.myAtoi("2147483648")<<endl;
  return 0;
}
