#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    string s;
    int res;
    while (cin >> s) {
        res = 0;
        s = s.substr(2);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') res = res * 16 + (s[i] - '0');
            else res = res * 16 + (s[i] - 'A' + 10);
        }
        cout << res << endl;
    }
    return 0;
}