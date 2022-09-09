// 最小绝对差
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector< vector<int> > res;
        int abs_min = INT_MAX;
        for(int i = 0; i < arr.size() - 1; ++i) {
            abs_min = min(abs(arr[i+1] - arr[i]), abs_min);
        }
        for(int i = 0; i < arr.size() - 1; ++i) {
            if(abs(arr[i+1] - arr[i]) == abs_min) {
                vector<int> temp;
                temp.emplace_back(arr[i]);
                temp.emplace_back(arr[i+1]);
                res.emplace_back(temp);
            }
        }
        return res;
    }
};