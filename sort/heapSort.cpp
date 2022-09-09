#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 用来检测 index 位置及之下的子树是否满足最大堆的原则
void adjust(vector<int>& nums, int index, int len) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    while (left < len) {
        int maxId = left;
        if (right < len && nums[maxId] < nums[right]) {
            maxId = right;
        }
        if (nums[index] < nums[maxId]) {
            swap(nums[maxId], nums[index]);
            index = maxId;
            left = index * 2 + 1;
            right = index * 2 + 2;
        } else {
            break;
        }
    }
}

// 堆排序
void heapSort(vector<int>& nums, int len) {
    // 建立最大堆
    int index = len / 2 - 1;
    for (int i = index; i >= 0; --i) {
        adjust(nums, i, len);
    }
    // 轮流将堆顶和最后的元素交换
    int swapIndex = len - 1;
    for (int i = 0; i < len - 1; ++i) {
        swap(nums[0], nums[swapIndex--]);
        adjust(nums, 0, swapIndex + 1);
    }
}

// 维护一个最大堆
void makeHeap(vector<int>& nums, int len) {
    // 建立最大堆
    int index = len / 2 - 1;
    for (int i = index; i >= 0; --i) {
        adjust(nums, i, len);
    }
}

// 上升过程
void upHeap(vector<int>& nums, int len) {
    int index = len - 1;
    int parent = (index - 1) / 2;
    while (nums[index] > nums[parent]) {
        swap(nums[index], nums[parent]);
        adjust(nums, index, len);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// 通过替换删除的节点和最后的节点的值，再将索引下沉比较各个节点
void deleteHeap(vector<int>& nums, int len, int deleteIndex) {
    swap(nums[len - 1], nums[deleteIndex]);
    nums.pop_back();
    int left = deleteIndex * 2 + 1;
    int right = deleteIndex * 2 + 2;
    int maxId = left;
    int index = deleteIndex;
    while (left < len - 1) {
        if (right < len - 1 && nums[maxId] < nums[right]) {
            maxId = right;
        }
        if (nums[index] < nums[maxId]) {
           swap(nums[index], nums[maxId]);
           index = maxId;
           left = index * 2 + 1;
           right = index * 2 + 2;
        } else {
           break;
        }
    }

}

int main() {
    vector<int> nums = {5,10,7,340,23,58,2,55,35,45};
    int n = nums.size();
   //  heapSort(nums, n);  // 堆排序模拟
    makeHeap(nums, n);
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;

    nums.emplace_back(100);  // 插入一个数字
    n = nums.size();
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;
    upHeap(nums, n);  // 维护一个上升过程
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;

    nums = {93,72,48,53,45,30,18,36,15,35};
    n = nums.size();
    int deleteNumIndex = 1;
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;
    deleteHeap(nums, n, deleteNumIndex);  // 根据索引删除某个节点
    n = nums.size();
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;


    return 0;
}