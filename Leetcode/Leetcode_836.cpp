// 矩形重叠
// 所有的 右上角坐标要 大于 左下角坐标（两两对应）
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rec1[2] > rec2[0] && rec1[3] > rec2[1] && rec2[2] > rec1[0] && rec2[3] > rec1[1];
    }
};