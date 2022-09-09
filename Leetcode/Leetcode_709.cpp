// 转换成小写字母
// c |= 32 大小转小；c ^= 32 大转小、小转大；c ^= 32；c &= -33 大小转大，因为 -33 的补码为 11011111
class Solution {
public:
    string toLowerCase(string str) {
        for(auto& c: str) c |= 32;
        return str;
    }
};

class Solution2 {
public:
    string toLowerCase(string str) {
        for(auto& c: str) if('A' <= c && c <= 'Z') c += 32;
        return str;
    }
};