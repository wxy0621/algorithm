// 行星碰撞
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (auto& asteroid: asteroids) {
            if (asteroid > 0) {
                res.emplace_back(asteroid);
                continue;
            }
            bool isAlive = true;
            while (isAlive && res.size() > 0 && res.back() > 0) {
                if (res.back() + asteroid < 0) {
                    res.pop_back();
                } else if (res.back() + asteroid == 0) {
                    isAlive = false;
                    res.pop_back();
                } else {
                    isAlive = false;
                }
            }
            if (isAlive) res.emplace_back(asteroid);
        }
        return res;
    }
};