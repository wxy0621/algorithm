// 旋转链表
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0) return head;
        ListNode* res = head;
        ListNode* temp = head;

        int count = 1;
        while(temp->next) { 
            ++count;
            temp = temp->next;
        }
        temp->next = head;
        k = k % count;
        
        temp = head;
        for(int i = 0; i < count - k - 1; ++i) {
            temp = temp->next;
        }
        res = temp->next;
        temp->next = nullptr;
        return res;
    }
};

int main()
{
    return 0;
}