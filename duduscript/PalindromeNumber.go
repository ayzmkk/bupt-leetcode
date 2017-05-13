func isPalindrome(x int) bool {
    s := strconv.Itoa(x)
    l,r := 0,len(s)-1
    for l <= r {
        if s[l] != s[r] {
            return false
        }
        l,r = l+1,r-1
    }
    return true
}