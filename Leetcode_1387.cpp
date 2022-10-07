// 将整数按权重排序
bool cmp(vector<int> v1, vector<int> v2) {
    if (v1[1] == v2[1]) return v1[0] < v2[0];
    return v1[1] < v2[1];
}
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<vector<int>> weights(hi - lo + 1, vector<int>(2));
        for (int i = lo; i <= hi; ++i) {
            weights[i - lo][0] = i;
            weights[i - lo][1] = countWeight(i);
        }
        sort(weights.begin(), weights.end(), cmp);
        return weights[k-1][0];
    }
    int countWeight(int key) {
        int weight = 0;
        while (key != 1) {
            if (key % 2 == 0) key /= 2;
            else key = key * 3 + 1;
            ++weight;
        }
        return weight;
    }
};