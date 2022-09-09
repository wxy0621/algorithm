// 替换空格
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        
        int original_length = s.size() - 1;
        for(int i = 0; i <= original_length; ++i) {
            if(s[i] == ' ') {
                s += "00";
            }
        }

        int new_length = s.size() - 1;

        int p1 = new_length;
        int p2 = original_length;
        for(int i = p2; i >= 0; i--)
        {
            char a = s[i];
            if(a == ' ') {
                s[p1--] = '0';
                s[p1--] = '2';
                s[p1--] = '%';
            } else {
                s[p1--] = a;
            }
        }
        return s;
    }
};

int main(){

    return 0;
}