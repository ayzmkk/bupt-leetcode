#include<iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
      string roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
      int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1},pos = 0;
      string res = "";
      while(num)
      {
        while(num >= value[pos])
        {
          num -= value[pos];
          res += roman[pos];
        }
        pos++;
      }
      return res;
    }
};

int main()
{
  Solution s;
  cout<<s.intToRoman(100)<<endl;
  return 0;
}
