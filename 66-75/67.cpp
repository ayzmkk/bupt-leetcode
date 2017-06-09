class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int n = a.size() , m = b.size();
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i = 0 , j = 0;
        int c = 0;
        while(i < n || j < m) {
            int t = 0;
            if(i < n && j < m) {
                t = (a[i++] - '0') + (b[j++] - '0') + c;
            }else if(i < n) {
                t = a[i++] - '0' + c;
            }else {
                t = b[j++] - '0' + c;
            }
            c = t / 2;
            t = t % 2;
            res.push_back(t + '0');
        }
        if(c != 0) res.push_back(c + '0');
        reverse(res.begin(),res.end());
        return res;
    }
};