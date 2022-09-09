// 有序链表转换二叉搜索树
// 用 vector 中转
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head) {
            v.emplace_back(head->val);
            head = head->next;
        }
        return structTreeNode(v, 0, v.size());
    }

    TreeNode* structTreeNode(vector<int>& v, int left, int right) {
        if(left == right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = structTreeNode(v, left, mid);
        root->right = structTreeNode(v, mid + 1, right);
        return root;
    }
};

// 直接来，快一些
class Solution2 {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return structTreeNode(head, nullptr);
    }

    TreeNode* structTreeNode(ListNode* head, ListNode* tail) {
        if(head == tail) return nullptr;
        ListNode* fast = head, *slow = head;
        while(fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = structTreeNode(head, slow);
        root->right = structTreeNode(slow->next, tail);
        return root;
    }
};