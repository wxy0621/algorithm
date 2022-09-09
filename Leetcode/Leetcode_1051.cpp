// 高度检查器
// 计数排序、桶排序
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size(), count = 0;
        int arr[101] = {0};
        for(auto& h: heights) ++arr[h];
        int j = 0;
        for(int i = 1; i < 101; ++i) {
            while(arr[i]--) {
                if(i != heights[j++]) ++count;
            }
        }
        return count;
    }
};