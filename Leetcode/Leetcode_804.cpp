// 唯一摩尔斯密码词
// 哈希表
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string map[] {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for(auto& w: words) {
            string str;
            for(auto& c: w) str += map[c - 'a'];
            s.insert(str);
        }
        return s.size();
    }
};