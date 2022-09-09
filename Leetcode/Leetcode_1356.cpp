// 根据数字二进制下 1 的数目排序
int countOne(int num) {
    int count = 0;
    while (num) {
        num &= (num-1);
        ++count;
    }
    return count;
}
bool Compare(int i, int j) {
    int one_i = countOne(i);
    int one_j = countOne(j);
    return one_i != one_j ? countOne(i) < countOne(j) : i < j;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> res = arr;
        sort(res.begin(), res.end(), Compare);
        return res;
    }
};