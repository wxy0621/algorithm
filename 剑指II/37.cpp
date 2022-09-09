// 小行星碰撞
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> stk;
        for (auto& asteroid: asteroids) {
            if (asteroid > 0) stk.push(asteroid);
            else {
                if (stk.empty() || stk.top() < 0) {
                    stk.push(asteroid);
                } else {
                    while (!stk.empty()) {
                        if (stk.top() < 0) {
                            stk.push(asteroid);
                            break;
                        }
                        if (stk.top() + asteroid == 0) {
                            stk.pop();
                            break;
                        } else if (stk.top() + asteroid > 0) {
                            break;
                        } else {
                            stk.pop();
                            if (stk.empty()) {
                                stk.push(asteroid);
                                break;
                            }
                        }
                    }
                }
                
            }
        }
        while (!stk.empty()) {
            res.emplace_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
