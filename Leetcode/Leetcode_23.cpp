// 合并k个排序链表
// 每次出队一个最小的，看该出对后有无下一个节点进入该队列
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct cmp {
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };

    // 优先队列
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;

        for(auto i: lists) {
            if(i) q.push(i);
        }

        ListNode res(-1);
        ListNode* helper = &res;
        while(!q.empty()) {
            ListNode* tmp = q.top();
            q.pop();
            helper->next = tmp;
            helper = tmp;
            if(tmp->next)
                q.push(tmp->next);
        }
        return res.next;
    }
};

int main()
{
    
    return 0;
}