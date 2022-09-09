// 反转字符串中的元音字母
class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isVowels(s[left])) ++left;
            while (left < right && !isVowels(s[right])) --right;
            swap(s[left++], s[right--]);
        }
        return s;
    }
    bool isVowels(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
        || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }
};