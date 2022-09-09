// 爱生气的书店老板
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int res = customers[0] * (grumpy[0]-1)*(-1);
        int n = grumpy.size();
        if (X >= n) {
            int temp = 0;
            for (int i = 0; i < n; ++i) temp += customers[i];
            return temp;
        }
        int temp_max_time = 0;
        for (int i = 0; i < X; ++i) 
            temp_max_time += grumpy[i] * customers[i];
        int max_grumpy_time = temp_max_time;
        int max_start_index = 0;
        for (int i = 1; i < n-X+1; ++i) {
            res += customers[i] * (grumpy[i]-1)*(-1);
            temp_max_time += (grumpy[X+i-1] * customers[X+i-1] - grumpy[i-1] * customers[i-1]);
            if (max_grumpy_time < temp_max_time) {
                max_grumpy_time = temp_max_time;
                max_start_index = i;
            }
        }
        for (int i = n-X+1; i < n; ++i) 
            res += customers[i] * (grumpy[i]-1)*(-1);
        return res + max_grumpy_time;
    }
};