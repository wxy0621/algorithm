// 盛最多水的容器
// 双指针
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_volumn = 0;
        while(left < right) {
            if(height[left] < height[right]) {
                max_volumn = max(max_volumn, (right - left) * height[left]);
                ++left;
            } else {
                max_volumn = max(max_volumn, (right - left) * height[right]);
                --right;
            }
        }
        return max_volumn;
    }
};

class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int min_height = min(height[left], height[right]);
        int max_volumn = (right - left) * min_height;
        while(left < right) {
            if(height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
            min_height = min(height[left], height[right]);
            max_volumn = max(max_volumn, (right - left) * min_height);
        }
        return max_volumn;
    }
};

int main()
{
    
    return 0;
}