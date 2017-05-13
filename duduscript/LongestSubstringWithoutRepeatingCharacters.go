func lengthOfLongestSubstring(s string) int {
    left,right,rtn := 0,0,0
    table := make([]bool,128)
    for right < len(s) {
        for table[int(s[right])] == true {
            table[int(s[left])] = false
            left++
        }
        table[int(s[right])] = true
        right++
        if rtn < right-left { rtn = right-left }
    }
    return rtn
}