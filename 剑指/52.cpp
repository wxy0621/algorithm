// 两个链表的第一个公共节点
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unsigned int length1 = getLength(headA);
        unsigned int length2 = getLength(headB);
        int difference = length1 - length2;

        ListNode* plong = headA;
        ListNode* pshort = headB;
        if(difference < 0)
        {
            plong = headB;
            pshort = headA;
            difference = -difference;
        }
        
        for(int i = 0; i < difference; ++i)
        {
            plong = plong->next;
        }

        while(plong != nullptr && pshort != nullptr && plong != pshort)
        {
            plong = plong->next;
            pshort = pshort->next;
        }

        ListNode* res = plong;
        return res;
    }
    unsigned int getLength(ListNode* head)
    {
        unsigned int length = 0;
        ListNode* res = head;
        while(res != nullptr)
        {
            length++;
            res = res->next;
        }
        return length;
    }
};

int main()
{
    

    return 0;
}