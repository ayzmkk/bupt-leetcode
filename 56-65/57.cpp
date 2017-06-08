/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& ins, Interval newInterval) {
        vector<Interval> res;
        vector<Interval>::iterator it = ins.begin();
        int s = newInterval.start, e = newInterval.end;
        for(;it<ins.end();it++) {
            if(it->start > e) {
                break;
            }else if(it->end < s) {
                res.push_back(*it);
            }else {
                s = min(it->start,s);
                e = max(it->end,e);
            }
        }
        res.push_back(Interval(s,e));
        while(it != ins.end()) {
            res.push_back(*it); 
            it++;
        }
        return res;
        
    }
};