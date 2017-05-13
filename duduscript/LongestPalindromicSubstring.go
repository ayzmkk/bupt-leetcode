func longestPalindrome(s string) string {
    str := ""
    for i:=0;i<len(s);i++ {
        if len(str) >= 2*(len(s) - i)-1 { break }
        l,r := i,i
        for l >= 0 && r < len(s) && s[l] == s[r] {
            if r-l+1 > len(str) {
                str = s[l:r+1]
            }
            l,r = l-1,r+1
        }
        l,r = i,i+1
        for l >= 0 && r < len(s) && s[l] == s[r] {
            if r-l+1 > len(str) {
                str = s[l:r+1]
            }
            l,r = l-1,r+1
        }
    }
    return str
}