// 基于排列构建数组
class Solution {
    func buildArray(_ nums: [Int]) -> [Int] {
        var res = [Int]()
        for i in 0..<nums.count {
            res.append(nums[nums[i]])
        }
        return res
    }
}