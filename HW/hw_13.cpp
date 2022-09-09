#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    vector<string> v;
    while (cin >> str) {
        v.emplace_back(str);
    }
    int n = v.size();
    for (int i = n - 1; i >= 0; --i) {
        if (i != 0) cout << v[i] << " ";
        else cout << v[i];
    }
    return 0;
}