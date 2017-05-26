func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 { return "" }
    for i := 0;;i++ {
        for j := 0;j < len(strs);j++ {
            if len(strs[j]) <= i || j != 0 && strs[j][i] != strs[j-1][i] {
                return strs[0][:i]
            }
        }
    }
}