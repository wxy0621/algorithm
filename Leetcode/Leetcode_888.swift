// 公平的糖果交换
class Solution {
    func fairCandySwap(_ aliceSizes: [Int], _ bobSizes: [Int]) -> [Int] {
        var aliceTotal = 0, bobTotal = 0
        var res = [Int]()
        for num in aliceSizes {
            aliceTotal += num
        }
        for num in bobSizes {
            bobTotal += num
        }
        var delta = (aliceTotal - bobTotal) / 2
        let aliceSet = Set(aliceSizes)
        for y in bobSizes {
            var x = delta + y
            if aliceSet.contains(x) {
                res = [x, y]
                break
            }
        }
        return res
    }
}