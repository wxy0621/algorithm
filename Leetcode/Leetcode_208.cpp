// 实现 Trie (前缀树)
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() = default;
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (auto& c: word) {
            if (!node->next[c-'a']) {
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (auto& c: word) {
            if (!node->next[c-'a']) {
                return false;
            }
            node = node->next[c-'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto& c: prefix) {
            if (!node->next[c-'a']) {
                return false;
            }
            node = node->next[c-'a'];
        }
        return true;
    }
protected:
    Trie* next[26] = {nullptr};
    bool isEnd = false;
};