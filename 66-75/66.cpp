class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = -1;
        for(int i = 0 ; i < digits.size(); i++) {
            if(digits[i] != 9) index = i;
        }
        if(index != -1) {
            digits[index]++;
            index++;
            while(index < digits.size()) digits[index++] = 0;
            return digits;
        }else {
            vector<int> res (digits.size()+1, 0);
            res[0] = 1;
            return res;
        }
    }
};