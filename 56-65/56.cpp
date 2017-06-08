/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval &a, Interval &b) {
    if(a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& ins) {
        sort(ins.begin(),ins.end(),cmp);
        vector<Interval> res;
        for(int i = 0; i < ins.size(); i++) {
            if(res.empty()) {
                res.push_back(ins[i]);
            }else {
                if(ins[i].start <= res.back().end) {
                    res.back().end = max(res.back().end, ins[i].end);
                }else {
                    res.push_back(ins[i]);
                }
            }
        }
        return res;
    }
};