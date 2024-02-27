// 判断路径是否相交
class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<int> visitPoints;
        int x = 0, y = 0;
        visitPoints.insert(countHash(x, y));
        for (char c: path) {
            if (c == 'N') ++y;
            else if (c == 'S') --y;
            else if (c == 'W') --x;
            else if (c == 'E') ++x;
            int hash = countHash(x, y);
            if (visitPoints.find(hash) != visitPoints.end()) {
                return true;
            } else {
                visitPoints.insert(hash);
            }
        }
        return false;
    }
    int countHash(int x, int y) {
        return x * 20001 + y;
    }
};