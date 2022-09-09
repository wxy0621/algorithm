// 机器人能否返回原点
class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical = 0, horizontal = 0;
        for(auto& move: moves) {
            if(move == 'U') ++vertical;
            else if(move == 'D') --vertical;
            else if(move == 'R') ++horizontal;
            else if(move == 'L') --horizontal;
        }
        return vertical == 0 && horizontal == 0;
    }
};