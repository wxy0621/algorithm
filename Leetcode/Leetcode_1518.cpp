// 换酒问题
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int emptyBottles = numBottles;
        while(emptyBottles >= numExchange) {
            res += emptyBottles / numExchange;
            emptyBottles = emptyBottles / numExchange + emptyBottles % numExchange; 
        }
        return res;
    }
};