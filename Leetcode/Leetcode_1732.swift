// 找到最高海拔
class Solution {
    func largestAltitude(_ gain: [Int]) -> Int {
        var sum = 0
        var res = 0
        for val in gain {
            sum += val
            res = max(sum, res)
        }
        return res
    }
}