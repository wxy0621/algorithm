// 棒球比赛
class Solution {
    func calPoints(_ operations: [String]) -> Int {
        var res = 0
        var arr : [Int] = []
        for operation in operations {
            if operation == "+" {
                arr.append(arr[arr.count - 1] + arr[arr.count - 2])
            } else if operation == "D" {
                arr.append(arr[arr.count - 1] * 2)
            } else if operation == "C" {
                arr.removeLast()
            } else {
                arr.append(Int(operation)!)
            }
        }
        for num in arr {
            res += num
        }
        return res
    }
}