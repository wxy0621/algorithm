// 删除有序数组中的重复项
class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        var n = nums.count
        if n < 2 {
            return n
        }
        var fast = 1, slow = 1
        while fast < n {
            if nums[fast] != nums[fast-1] {
                nums[slow] = nums[fast]
                slow += 1
            }
            fast += 1
        }
        return slow
    }
}