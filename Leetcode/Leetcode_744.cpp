// 寻找比目标字母大的最小字母
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = '|';
        for(auto& c: letters) {
            if(c > target) {
                res = min(res, c);
            }
        }
        return res == '|' ? letters[0] : res;
    }
};