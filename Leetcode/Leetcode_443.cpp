// 压缩字符串
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int j = 0;
        int count = 0;
        // 原地修改
        for(int i = 1; i <= n; ++i) {
            ++count;
            if(i == n || chars[i] != chars[j]) {
                ++j;
                if(count != 1) {
                    string number = to_string(count);
                    for(auto& c: number) {
                        chars[j++] = c;
                    }
                }
                if(i == n) break;
                chars[j] = chars[i];
                count = 0;
            }
        }
        return j;
    }
};