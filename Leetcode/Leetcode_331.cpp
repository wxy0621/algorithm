// 验证二叉树的前序序列化
// 栈
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        if (n == 0) return false;
        stack<int> s;
        s.push(1);  // 不是 root 节点，是 root 的更前面一个节点，不论头结点是 # 还是数字，都会立刻出队
        int i = 0;
        while (i < n) {
            if (s.empty()) return false;
            if (preorder[i] == ',') ++i;
            else if (preorder[i] == '#') {
                s.top() -= 1;
                ++i;
                if (s.top() == 0) s.pop();
            } else {
                while (i < n && preorder[i] != ',') ++i;  // 读一个数字，例如 92 要读两次，所以要循环
                s.top() -= 1;
                if (s.top() == 0) s.pop();
                s.push(2);
            }
        }
        return s.empty();
    }
};

// 简化栈为一个计数器（数字）
class Solution2 {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        if (n == 0) return false;
        int count = 1;
        int i = 0;
        while (i < n) {
            if (count == 0) return false;
            if (preorder[i] == ',') ++i;
            else if (preorder[i] == '#') {
                count -= 1;
                ++i;
            } else {
                while (i < n && preorder[i] != ',') ++i;  // 读一个数字，例如 92 要读两次，所以要循环
                count += 1;
            }
        }
        return count == 0;
    }
};