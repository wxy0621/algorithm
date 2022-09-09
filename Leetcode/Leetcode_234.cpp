// 回文链表
// 栈
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* p = head;
        stack<int> s;
        while(p != nullptr) {
            s.push(p->val);
            p = p->next;
        }

        p = head;
        while(!s.empty()) {
            if(s.top() != p->val) return false;
            s.pop();
            p = p->next;
        }

        return true;
    }
};

// 快慢指针
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode* fast = head, *slow = head;
        ListNode* pre = nullptr;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        while(slow != nullptr) {
            ListNode* p = slow->next;
            slow->next = pre;
            pre = slow;
            slow = p;
        }

        while(pre != nullptr) {
            if(pre->val != head->val) return false;
            pre = pre->next;
            head = head->next;
        }
        
        return true;
    }
};

// 计算长度
class Solution3 {
public:
    bool isPalindrome(ListNode* head) {
        int lengthOfList = 0;
        ListNode* cur = head;
        while (cur) {
            cur = cur->next;
            ++lengthOfList;
        }
        int moveLength = lengthOfList / 2;
        ListNode* pre = nullptr;
        cur = head;
        for (int i = 0; i < moveLength; ++i) {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        if (lengthOfList % 2 == 1) cur = cur->next;
        while (moveLength--) {
            if (pre->val != cur->val) return false;
            pre = pre->next;
            cur = cur->next;
        }
        return true;
    }
};