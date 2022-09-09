#include <iostream>

using namespace std;

int main() {
    int res = 0;
    int num;
    cin >> num;
    while (num != 0) {
        res += (num % 2);
        num >>= 1;
    }
    cout << res << endl;
    return 0;
}