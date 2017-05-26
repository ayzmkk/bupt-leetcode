func twoSum(nums []int, target int) []int {
    imap := make(map[int]int)
    for i := 0;i < len(nums); i++ {
        if index,ok := imap[target-nums[i]]; ok {
            return []int{index,i}
        }
        imap[nums[i]] = i
    }
    return []int{0,0}
}