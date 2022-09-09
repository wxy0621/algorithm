// 统计不开心的朋友
class Solution {  // 情人节系列，太心酸了
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int res = 0;
        vector<int> couple(n);
        vector< vector<int> > order(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                order[i][preferences[i][j]] = j;
            }
        }
        int numOfCouple = pairs.size();
        for (int i = 0; i < numOfCouple; ++i) {
            couple[pairs[i][0]] = pairs[i][1];
            couple[pairs[i][1]] = pairs[i][0];
        }
        for (int x = 0; x < n; ++x) {  // 自己
            int y = couple[x];  // 现任
            int index = order[x][y];  // 现任在自己这儿的排名
            for (int i = 0; i < index; ++i) {  // 现任之前的人数
                int u = preferences[x][i];  // 心目中比现任好的妹子
                int v = couple[u];  // 妹子的 couple
                if (order[u][x] < order[u][v]) {  // 妹子的 couple 比自己垃圾，就不满意
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};