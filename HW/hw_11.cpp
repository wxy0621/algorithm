#include <iostream>

using namespace std;

int main() {
    string res;
    int num;
    cin >> num;
    while (num) {
        res += (num % 10 + '0');
        num /= 10;
    }
    cout << res << endl;
    return 0;
}