func reverse(x int) int {
    flag,result := 0,0
    if x < 0 {
        flag = 1
        x = -x
    }
    for x != 0 {
        result = result*10 + x%10
        x /= 10
    }
    if flag == 1 { result = -result }
    if result > (1<<31-1) || result < -(1<<31) {
        result = 0
    }
    return result
}