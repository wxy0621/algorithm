// 玩筹码
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0, even = 0;
        for(auto& num: chips) {
            if(num % 2 == 1) ++odd;
            else ++even;
        }
        return min(odd, even);
    }
};