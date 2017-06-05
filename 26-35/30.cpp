class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty() || s.empty()) return res;
        unordered_map<string, int> dict;
        for(auto word : words) dict[word]++;
        int len = words[0].size();
        int n = s.size();
        int cnt = words.size();
        for(int i = 0; i < len ; i++) {
            unordered_map<string,int> tdict;
            int count = 0 , start = i;
            for(int j = i; j < n; j += len) {
                string w = s.substr(j,len);
                if(dict.count(w)) {
                    tdict[w]++;
                    if(tdict[w] <= dict[w]) {
                        count++;
                    }else {
                        while(tdict[w] > dict[w]) {
                            string t = s.substr(start, len);
                            tdict[t]--;
                            if(tdict[t] < dict[t]) count--;
                            start += len;
                        }
                    }
                    if(cnt == count) {
                        res.push_back(start);
                        tdict[s.substr(start,len)]--;
                        count--;
                        start += len;
                    }
                }else {
                    tdict.clear();
                    start = j + len;
                    count = 0;
                }
            }
        }
        return res;
    }
};