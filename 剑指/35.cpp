// 复杂链表的复制
// 遍历两遍
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        Node* cur = head;
        unordered_map<Node*, Node*> m;
        while (cur) {
            m[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }
        return m[head];
    }
};

// 2 递归
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        if (!m.count(head)) {
            m[head] = new Node(head->val);
            m[head]->next = copyRandomList(head->next);
            m[head]->random = copyRandomList(head->random);
        }
        return m[head];
    }
private:
    unordered_map<Node*, Node*> m;
};