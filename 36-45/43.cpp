class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        if(num1.empty() || num2.empty()) return ans;
        int n = num1.size() , m = num2.size();
        vector<int> res (n+m,0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int carry = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m;j++) {
                int c = (num1[i] - '0') * (num2[j] - '0');
                res[i+j] += c;
            }
        }
        for(int i = 0; i < n+m; i++) {
            int t = res[i] + carry;
            res[i] = t % 10;
            carry = t / 10;
        }
        int index = n+m-1;
        while(index >= 0 && res[index] == 0) index--;
        for(int i=index;i >= 0;i--) ans.push_back(res[i] + '0');
        return ans.size() == 0 ? "0" : ans;
    }
};