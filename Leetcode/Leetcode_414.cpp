// 第三大的数
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
        for(int& num: nums) {
            if(num > a) {
                c = b;
                b = a;
                a = num;
            } else if(num > b && num != a) {
                c = b;
                b = num;
            } else if(num > c && num != a && num != b) {
                c = num;
            }
        }
        return (c == LONG_MIN) ? a : c;
    }
};