#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int res = 0;
    string str;
    cin >> str;
    unordered_set<char> us;
    for (auto& c: str) {
        if (us.count(c)) {
            continue;
        } else {
            us.insert(c);
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}