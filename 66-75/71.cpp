class Solution {
public:
    string simplifyPath(string path) {
        string name;
        vector<string> st;
        path.push_back('/');
        for(int i = 0; i < path.size(); i++) {
            char c = path[i];
            if(c == '/') {
                if(name == "..") {
                    if(!st.empty()) st.pop_back();
                }else if(!name.empty() && name != ".") {
                    st.push_back(name);
                }
                name = "";
            }else {
                name.push_back(c);
            }
        }
        string res;
        for(int i=0;i<st.size();i++) {
            res += "/";
            res += st[i];
        }
        return (res.size() == 0) ? "/" : res;
    }
};