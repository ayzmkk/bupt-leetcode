class Solution {
public:
    vector<int> A;
    void build(int n) {
        A.push_back(1);
        A.push_back(1);
        for(int i=2;i<=n;i++) A.push_back(A.back() * i);
    }
    string getPermutation(int n, int k) {
        build(n);
        string res;
        int len = n;
        vector<int> v;
        for(int i=1;i<=n;i++) v.push_back(i);
        for(int i = 1; i<= n; i++) {
            int index = (k-1) / A[n-i];
            res.push_back('0' + v[index]);
            v.erase(v.begin() + index);
            k -= index * A[n-i];
        }
        return res;
    }
};