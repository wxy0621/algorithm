#include <bits/stdc++.h>

using namespace std;

void insertSort(vector<int>& nums) {
    int temp;
    int n = nums.size();
    for(int i = 1; i < n; ++i) {
        temp = nums[i];
        int j;
        for(j = i - 1; j >= 0 && nums[j] > temp; --j) nums[j + 1] = nums[j];
        nums[j + 1] = temp;
    }
}

int main()
{
    vector<int> nums = {5,4,6,1,8,9,2,0};
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    insertSort(nums);
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
