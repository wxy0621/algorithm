// 复制带随机指针的链表
// 存下来，空间复杂度 O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        if (!cache.count(head)) {
            Node* newNode = new Node(head->val);
            cache[head] = newNode;
            newNode->next = copyRandomList(head->next);
            newNode->random = copyRandomList(head->random);
        }
        return cache[head];
    }
private:
    unordered_map<Node*, Node*> cache;
};

// 空间复杂度 O(1)
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* newNode = new Node(node->val);
            newNode->next = node->next;
            node->next = newNode;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* newNode = node->next;
            newNode->random = node->random ? node->random->next : nullptr;
        }
        Node* res = head->next;
        for (Node* node = head; node != nullptr; node = node->next) {
            Node* nex = node->next;
            node->next = nex->next;
            nex->next = nex->next ? nex->next->next : nullptr;
        }
        return res;
    }
};