// 网络信号最好的坐标
// 暴力
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<int> res = {0, 0};
        int tempMax = 0;
        for (int i = 0; i <= 50; ++i) {
            for (int j = 0; j <= 50; ++j) {
                int tense = 0;
                for (auto& tower: towers) {
                    int dis = (tower[0] - i) * (tower[0] - i) + (tower[1] - j) * (tower[1] - j);
                    if (dis <= radius * radius) {
                        tense += tower[2] / (1 + sqrt(dis));
                    }
                }
                if (tempMax < tense) {
                    tempMax = tense;
                    res = {i, j};
                }
            }
        }
        return res;
    }
};