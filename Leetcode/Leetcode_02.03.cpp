// 删除中间节点
// 有点傻，理解题目意思
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// 谁知道以前写的代码更蠢
class Solution2 {
public:
    void deleteNode(ListNode* node) {
        while(node->next) {
            node->val = node->next->val;
            if(node->next->next) node = node->next;
            else node->next = nullptr;
        }
    }
};