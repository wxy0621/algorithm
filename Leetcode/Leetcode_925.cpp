// 长按键入
// 双指针
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n1= name.size(), n2 = typed.size();
        if(n1 > n2) return false;
        int i = 0, j = 0;
        while(i < n1 && j < n2) {
            if(name[i] == typed[j]) {
                ++i;
                ++j;
            } else if(j > 0 && typed[j - 1] == typed[j]) ++j;
            else return false;
        }
        // typed 可能没走完，后面还有字符没判断
        while(j < n2) {
            if(typed[j] != typed[j - 1]) return false;
            j++;
        }
        return i == n1;
    }
};