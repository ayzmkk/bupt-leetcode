func min(x,y int) int {
    if x > y {
        return y
    }
    return x
}
func maxArea(height []int) int {
    left, right, result := 0, len(height) - 1, 0
    for left < right {
        if tmp := (right-left)*min(height[left],height[right]); tmp > result {
            result = tmp
        }
        if height[left] <= height[right] {
            left++
        } else {
            right--
        }
    }
    return result
}