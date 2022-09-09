// 等式方程的可满足性
class Solution {
public:
    vector<int> parent;
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        iota(parent.begin(), parent.end(), 0);
        for (auto& equation: equations) {
            if (equation[1] == '=') {
                int c1 = equation[0] - 'a', c2 = equation[3] - 'a';
                unit(c1, c2);
            }
        }
        for (auto& equation: equations) {
            if (equation[1] != '=') {
                int c1 = equation[0] - 'a', c2 = equation[3] - 'a';
                if (find(c1) == find(c2)) return false;
            }
        }
        return true;
    }
    void unit(int i, int j) {
        parent[find(i)] = find(j);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return find(parent[i]);
    }
};