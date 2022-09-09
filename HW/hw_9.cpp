#include <iostream>

using namespace std;

int main() {
    int nums[10] = {0};
    int num;
    int res = 0;
    cin >> num;
    while (num) {
        int temp = num % 10;
        if (nums[temp] == 0) res = res * 10 + temp;
        nums[temp] = 1;
        num /= 10;
    }
    cout << res << endl;
    return 0;
}