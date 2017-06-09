class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int L) {
        int n = words.size();
        vector<string> res;
        for(int i = 0 ; i < n;) {
            int pos = i+1;
            int l = words[i].size();
            int space_num = 0;
            while(pos < n && (words[pos].size() + l + 1) <= L - space_num) {
                l += words[pos].size();
                space_num += 1;
                pos += 1;
            }
            string tmp = words[i];
            for(int j = 0; j < space_num; j++) {
                if(pos == n) tmp += " ";
                else tmp += string((L-l) / space_num + (j < (L-l) % space_num) , ' ');
                tmp += words[i + j + 1];
            }
            tmp += string(L - tmp.size(),' ');
            res.push_back(tmp);
            i = pos;
        }
        return res;
    }
};