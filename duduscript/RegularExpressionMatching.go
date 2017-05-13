func isMatch(s string, p string) bool {
    if len(p) == 0 { return len(s) == 0 }
    if p[0] == '*' { return isMatch(s,p[1:]) }
    if len(p) == 1 || p[1] != '*' {
        return len(s)!=0 && (s[0] == p[0] || p[0] == '.') && isMatch(s[1:],p[1:])
    }
    if p[0] != '.' {
        if isMatch(s, p[2:]) { return true }
        for i:=0;i<len(s);i++ {
            if s[i] == p[0] && isMatch(s[i+1:],p[2:]) {
                return true
            } else if s[i] != p[0] {
                return isMatch(s[i:],p[2:])
            }
        }
        return false
    } else {
        for i:=0;i<=len(s);i++ {
            if isMatch(s[i:],p[2:]){
                return true
            }
        }
        return false
    }
}