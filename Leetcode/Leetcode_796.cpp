// 旋转字符串
// 头尾相连
class Solution {
public:
    bool rotateString(string A, string B) {
        if(A == "" && B == "") return true;
        return (A + A).find(B, 1) != string::npos && A.size() == B.size();
    }
};