// IP 地址无效化
// 原地替换
class Solution {
public:
    string defangIPaddr(string address) {
        int original_size = address.size();
        for(int i = 0; i < original_size; ++i) {
            if(address[i] == '.') address += "00";
        }
        int new_size = address.size() - 1;
        for(int i = original_size - 1; i >= 0; --i) {
            if(address[i] == '.') {
                address[new_size--] = ']';
                address[new_size--] = '.';
                address[new_size--] = '[';
            } else {
                address[new_size--] = address[i];
            }
        }
        return address;
    }
};

// 弱智暴力法
class Solution2 {
public:
    string defangIPaddr(string address) {
        string res;
        for(char c: address) {
            if(c == '.')
                res += "[.]";
            else
                res += c;
        }
        return res;
    }
};