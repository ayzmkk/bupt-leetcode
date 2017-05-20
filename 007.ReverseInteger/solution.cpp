#include<iostream>
using namespace std;

/*
如果溢出需要输出0

负数比正数多表示一个。因为是补码表示。
*/

class Solution {
public:
    int reverse(int x) {
        long long maxn = 1;
        long long cur_x = x;
        maxn = (maxn<<31) -1;
        bool flag = false;
        long long res = 0;
        if(cur_x<0)
        {
          cur_x = -cur_x;
          flag = true;
        }

        while(cur_x)
        {
          res = res*10 + cur_x%10;
          cur_x/=10;
          if(res>maxn)
            return 0;
        }
        if(flag)
          res = -res;
        return int(res);
    }
};

int main()
{
  Solution s;
  cout<<s.reverse(123)<<endl;
  cout<<s.reverse(-123)<<endl;

  cout<<s.reverse(-2147483648)<<endl;
  return 0;
}
