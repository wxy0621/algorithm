// 二叉树寻路
// 本节点的父节点 = 上一次层最大 + 上一次层最小 - 当前值 / 2
class Solution {
public:
    int getLayerNum(int label) {
        int count = 0;
        while (label) {
            label /= 2;
            ++count;
        }
        return count;
    }
    vector<int> pathInZigZagTree(int label) {
        if (label <= 0) return {};
        int layerNum = getLayerNum(label);
        vector<int> res(layerNum);
        for (int i = layerNum - 1; i > 0; --i) {
            res[i] = label;
            label = pow(2, i - 1) + pow(2, i) - 1 - label / 2;
        }
        res[0] = 1;
        return res;
    }
};