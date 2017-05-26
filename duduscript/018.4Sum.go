import "sort"
func fourSum(nums []int, target int) [][]int {
    var result [][]int
    sort.Ints(nums)
    for i:=0;i<len(nums)-3;i++ {
        if i != 0 && nums[i] == nums[i-1] { continue }
        for j:=i+1;j<len(nums)-2;j++ {
            if j != i+1 && nums[j] == nums[j-1] { continue }
            left,right,tar := j+1,len(nums)-1,target-nums[i]-nums[j]
            for left < right {
                if (left != j+1 && nums[left] == nums[left-1]) || nums[left]+nums[right]<tar {
                    left++
                } else if (right != len(nums)-1 && nums[right] == nums[right+1]) || nums[left] + nums[right]>tar {
                    right--
                } else {
                    result = append(result,[]int{nums[i],nums[j],nums[left],nums[right]})
                    left++
                }
            }
        }
    }
    return result
}