// 类似 b 树查询，找 target 节点地址
#include <iostream>
#include <vector>

using namespace std;

struct MultiTreeNode {
    vector<int> mval;
    vector<MultiTreeNode*> children;
    MultiTreeNode(): mval({}), children({}) {}
    MultiTreeNode(vector<int> _mval, vector<MultiTreeNode*> _children): mval(_mval), children(_children) {}
};

// 暴力
//int* find(MultiTreeNode* root, int target) {
//    if (!root) return nullptr;
//    int n = root->mval.size();
//    for (int i = 0; i < n; ++i) {
//        if (root->mval[i] == target) {
//            return &root->mval[i];
//        } else if (root->mval[i] > target) {
//            return find(root->children[i], target);
//        } else {
//            continue;
//        }
//    }
//    return find(root->children[n], target);
//}

// 二分
int* find(MultiTreeNode* root, int target) {
    if (!root) return nullptr;
    int n = root->mval.size();
    if (root->mval[n-1] < target) {
        return find(root->children[n], target);
    }
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (root->mval[mid] == target) {
            return &root->mval[mid];
        } else if (root->mval[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (left > right) return find(root->children[left], target);
    return find(root->children[right], target);
}


int main() {

    vector<int> nums1 = {1, 2};
    MultiTreeNode* mulitTree1 = new MultiTreeNode(nums1, {});
    
    vector<int> nums2 = {4, 5, 8};
    MultiTreeNode* mulitTree2 = new MultiTreeNode(nums2, {});
    
    vector<int> nums3 = {11};
    MultiTreeNode* mulitTree3 = new MultiTreeNode(nums3, {});
    
    vector<MultiTreeNode*> childrens = {mulitTree1, mulitTree2, mulitTree3};
    vector<int> nums0 = {3, 9};
    MultiTreeNode* mulitTree0 = new MultiTreeNode(nums0, childrens);
    
    
    int* ret1 = find(mulitTree0, 3);
    cout << ret1 << " " << *ret1 << endl;
    
    int* ret2 = find(mulitTree0, 11);
    cout << ret2 << " " << *ret2 << endl;

    int* ret3 = find(mulitTree0, 4);
    cout << ret3 << " " << *ret3 << endl;

    return 0;
}


