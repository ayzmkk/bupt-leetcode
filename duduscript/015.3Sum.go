import "sort"

func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    var result [][]int
    for i := 0;i < len(nums)-2; i++ {
        if i != 0 && nums[i] == nums[i-1] { continue }
        if nums[i] > 0 || nums[i]+nums[i+1]+nums[i+2] > 0 { break }
        for j := i+1; j< len(nums) -1; j++ {
            if j != i+1 && nums[j] == nums[j-1] { continue }
            left, right, target := j+1, len(nums), -(nums[i]+nums[j])
            for left < right {
                mid := left + (right - left)/2
                if nums[mid] < target {
                    left = mid+1
                } else if nums[mid] > target {
                    right = mid
                } else {
                    result = append(result,[]int{nums[i],nums[j],target})
                    break
                }
            }
        }
    }
    return result
}