// 移除链表元素
// 哑结点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dumb = new ListNode(0);
        ListNode* pre = dumb;
        pre->next = head;
        ListNode* cur = head;
        while(cur != nullptr) {
            if(cur->val == val) {
                pre->next = cur->next;
            } else {
                pre = pre->next;
            }
            cur = cur->next;
            
        }
        return dumb->next;
    }
};

// 哑结点改版
class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dumb = new ListNode(0);
        ListNode* pre = dumb;
        pre->next = head;
        while(head != nullptr) {
            if(head->val == val) {
                pre->next = head->next;
            } else {
                pre = pre->next;
            }
            head = head->next;
            
        }
        return dumb->next;
    }
};

// 哑结点3
class Solution3 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        ListNode* cur = head;
        ListNode* del;
        while(cur->next != nullptr) {
            if(cur->next->val == val) {
                del = cur->next;
                cur->next = del->next;
                delete del;
            } else {
                cur = cur->next;
            }
        }
        return head->val == val ? head->next : head;
    }
};

// 递归
class Solution4 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};