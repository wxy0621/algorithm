// LRU 缓存机制
// 双向链表 & 哈希表（经典算法）
struct DLinkedNode {
    int key;
    int value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    DLinkedNode* head;
    DLinkedNode* tail;
    int size = 0;
    int LRUCapacity;
    unordered_map<int, DLinkedNode*> cache;
public:
    LRUCache(int capacity) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
        LRUCapacity = capacity;
    }
    
    int get(int key) {
        if (!cache.count(key)) {  // 找不到
            return -1;
        } else {  // 找到
            DLinkedNode* node = cache[key];
            moveToHead(node);
            return node->value;
        }
    }
    
    void put(int key, int value) {
        DLinkedNode* node;
        if (!cache.count(key)) {  // 找不到
            node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > LRUCapacity) {
                DLinkedNode* deleted = deleteFromTail();
                cache.erase(deleted->key);
                delete deleted;
                --size;
            }
        } else {  // 找到
            node = cache[key];
            moveToHead(node);
            node->value = value;
        }
    }
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }
    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(DLinkedNode* node)  {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    DLinkedNode* deleteFromTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};