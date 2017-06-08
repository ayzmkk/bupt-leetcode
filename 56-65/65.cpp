//[-+]?(([0-9]+(.[0-9]*)?)|.[0-9]+)(e[-+]?[0-9]+)?

class Solution {
public:
    void trim(string &s) {
        int index = 0;
        while(index < s.size() && s[index] == ' ') index++;
        s = s.substr(index);
        index = s.size() - 1;
        while(index >= 0 && s[index] == ' ') index--;
        s = s.substr(0,index+1);
    }
    bool isNumber(string s) {
        trim(s);
        bool numberSeen = false, eSeen = false, dotSeen = false;
        bool numberAfterE = true;
        for(int i=0;i<s.size();i++) {
            char c = s[i];
            if(isdigit(c)) {
                numberSeen = true;
                numberAfterE = true;
            }else if(c == '.') {
                if(dotSeen || eSeen ) return false;
                dotSeen = true;
            }else if(c == 'e') {
                if(eSeen || !numberSeen) return false;
                eSeen = true;
                numberAfterE = false;
            }else if(c == '+' || c == '-') {
                if(i != 0 && s[i-1] != 'e') {
                    return false;
                }
            }else {
                return false;
            }
        }
        return numberSeen && numberAfterE;
    }
};