// 宝石与石头
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_set<char> s;
        for(char& c: J) {
            s.insert(c);
        }
        for(char& c: S) {
            if(s.find(c) != s.end())
                ++res;
        }
        return res;
    }
};