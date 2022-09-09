// 二进制求和
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int length_a = a.size();
        int length_b = b.size();

        while(length_a < length_b) {
            a = '0' + a;
            ++length_a;
        }

        while(length_a > length_b) {
            b = '0' + b;
            ++length_b;
        }

        for(int i = length_a - 1; i > 0; --i) {
            a[i] = a[i] + b[i] - '0';
            if(a[i] >= '2') {
                a[i] -= 2;
                a[i-1] += 1;
            }
        }

        a[0] = a[0] + b[0] - '0';
        if(a[0] >= '2') {
            a[0] -= 2;
            a = '1' + a;
        }
        
        return a;
    }
};

int main()
{
    
    return 0;
}