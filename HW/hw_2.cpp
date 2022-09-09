#include <iostream>

using namespace std;

int main() {
    string s;
    int nums[10] = {0};
    int letters[26] = {0};
    getline(cin, s);
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] >= '0' && s[i] <= '9') ++nums[s[i] - '0'];
        else if (s[i] >= 'A' && s[i] <= 'Z') ++letters[s[i] - 'A'];
        else ++letters[s[i] - 'a'];
    }
    char compareChar;
    cin >> compareChar;
    if (compareChar >= '0' && compareChar <= '9') cout << nums[compareChar - '0'] << endl;
    if (compareChar >= 'a' && compareChar <= 'z') cout << letters[compareChar - 'a'] << endl;
    if (compareChar >= 'A' && compareChar <= 'Z') cout << letters[compareChar - 'A'] << endl;
    
    return 0;
}