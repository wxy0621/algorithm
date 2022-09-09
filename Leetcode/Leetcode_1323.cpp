// 6 和 9 组成的最大数字
class Solution {
public:
    int maximum69Number (int num) {
        vector<int> temp;
        while(num != 0) {
            temp.emplace_back(num % 10);
            num /= 10;
        }
        if((num + 1 - pow(10, temp.size())) == 0) return num;
        for(int i = temp.size() - 1; i >= 0; --i) {
            if(temp[i] == 6) {
                temp[i] = 9;
                break;
            }
        }
        int res = 0;
        for(int i = temp.size() - 1; i >= 0; --i) {
            res = res * 10 + temp[i];
        }
        return res;
    }
};

// 别人的答案就是这么好
class Solution2 {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(char& c: s) {
            if(c == '6') {
                c = '9';
                break;
            }
        }
        return stoi(s);
    }
};