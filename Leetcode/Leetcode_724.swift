class Solution {
    func pivotIndex(_ nums: [Int]) -> Int {
        var numsLength = nums.count
        if (numsLength == 0) {
            return -1
        }
        var total = 0
        for num in nums {
            total += num
        }
        if (total == nums[0]) {
            return 0
        }
        var current = 0
        var i = 0
        for i in stride(from: 0, through: numsLength-2, by: 1) {
            current += nums[i]
            total -= nums[i]
            if (total == nums[i+1] + current) {
                return i + 1
            }
        }
        return -1
    }
}