#include <iostream>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        string res;
        int n = s.size();
        int i = 0;
        while (n - i > 8) {
            cout << s.substr(i, 8) << endl;
            i += 8;
        }
        if (n - i <= 8) {
            res += s.substr(i, n - i);
            for (int j = 0; j < 8 - n + i; ++j)
                res += '0';
        }
        cout << res << endl;
    }
    return 0;
}