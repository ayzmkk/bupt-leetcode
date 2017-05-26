import "sort"
func threeSumClosest(nums []int, target int) int {
    var result []int
    sort.Ints(nums)
    diff := 0x7fffffff
    for i:=0;i<len(nums)-2;i++ {
        if i != 0 && nums[i] == nums[i-1] { continue }
        for j:=i+1;j<len(nums)-1;j++ {
            if j != i+1 && nums[j] == nums[j-1] { continue }
            left,right,tar := j+1,len(nums),target-nums[i]-nums[j]
            for left < right {
                mid := left + (right - left)/2
                if nums[mid] < tar {
                    if tar - nums[mid] < diff { 
                        diff = tar-nums[mid]
                        result = []int{nums[i],nums[j],nums[mid]}
                    }
                    left = mid+1
                } else if nums[mid] > tar {
                    if nums[mid] - tar < diff { 
                        diff = nums[mid]-tar
                        result = []int{nums[i],nums[j],nums[mid]}
                    }
                    right = mid
                } else {
                    return target
                }
            }
        }
    }
    return result[0]+result[1]+result[2]
}