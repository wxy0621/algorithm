#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums, int left, int mid, int right) {
    int n = nums.size();
    vector<int> res(n, 0);
    int i = left, j = mid + 1, k = left;
    while(i <= mid && j <= right) {
        if(nums[i] < nums[j]) {
            res[k] = nums[i];
            ++i;
        } else {
            res[k] = nums[j];
            ++j;
        }
        ++k;
    }
    while(i <= mid) {
        res[k++] = nums[i];
        ++i;
    }
    while(j <= right) {
        res[k++] = nums[j];
        ++j;
    }
    for(int l = left; l <= right; ++l) {
        nums[l] = res[l];
    }
    for(int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void mergeSort(vector<int>& nums, int left, int right) {
    if(left >= right) return;
    int m = (left + right) / 2;
    mergeSort(nums, left, m);
    mergeSort(nums, m + 1, right);
    merge(nums, left, m, right);
}

int main() 
{
    vector<int> nums = {5,4,6,1,8,9,2,0};
    int n = nums.size();

    for(int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    mergeSort(nums, 0, n - 1);

    for(int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}