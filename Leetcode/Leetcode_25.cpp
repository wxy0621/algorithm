// k个一组翻转链表

// 直接反转
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if (!head) return head;
        ListNode* cur = head;
        int lengthOfListNode = 0;
        while (cur) {
            cur = cur->next;
            ++lengthOfListNode;
        }
        int numOfReverse = lengthOfListNode / k;
        ListNode* pre = nullptr;
        cur = head;
        ListNode* dumb = new ListNode(-1);
        ListNode* last = dumb;
        dumb->next = cur;
        while (numOfReverse--) {
            ListNode* temp = cur;
            for (int i = 0; i < k; ++i) {
                ListNode* nex = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nex;
            }
            last->next = pre;
            last = temp;
            temp->next = cur;
            pre = nullptr;
        }
        return dumb->next;
    }
};

// 直接反转，通过辅助函数反转
class Solution2 {
public:
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        if (head == tail) return {head, tail};
        ListNode* pre = head;
        ListNode* cur = head;
        cur = cur->next;
        while (pre != tail) {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = new ListNode(0);
        ListNode* cur = head;
        ListNode* pre = res;
        ListNode* tail;
        pre->next = head;
        while (cur) {
            tail = pre;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) return res->next;
            }
            ListNode* nex = tail->next;
            tie(cur, tail) = myReverse(cur, tail);
            pre->next = cur;
            tail->next = nex;
            pre = tail;
            cur = nex;
        }
        return res->next;
    }
};

// 采用大小为 k 的栈的方法
class Solution3 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy = ListNode(0);
        ListNode* p = &dummy;
        while(true) {
            ListNode* temp = head;
            stack<ListNode*> s;
            int count = k;
            while(count != 0 && temp != nullptr) {
                s.emplace(temp);
                temp = temp->next;
                --count;
            }
            if(count != 0) {
                p->next = head;
                break;
            }
            while(!s.empty()) {
                p->next = s.top();
                s.pop();
                p = p->next;
            }
            p->next = temp;
            head = temp; 
        }
        return dummy.next;
    }
};