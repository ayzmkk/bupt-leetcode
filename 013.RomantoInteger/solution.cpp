#include<iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
      string roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
      int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1},pos = 0,len = s.size();
      int res = 0,t = 0;;
      while(pos<len)
      {
        while(s.substr(pos,roman[t].size()) == roman[t])
        {
          res += value[t];
          pos += roman[t].size();
        }
        t++;
      }
      return res;
    }
};

int main()
{
  Solution s;
  cout<<s.romanToInt("MIV")<<endl;
  return 0;
}
