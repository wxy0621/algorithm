// 扁平化嵌套列表迭代器 (暑期实习腾讯实习一面算法)
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        it = nums.begin();
    }
    
    int next() {
        return *it++;
    }
    
    bool hasNext() {
        return it != nums.end();
    }
private:
    vector<int> nums;
    vector<int>::iterator it;
    void dfs(vector<NestedInteger> &nestedList) {
        for (auto& nexted: nestedList) {
            if (nexted.isInteger()) {
                nums.emplace_back(nexted.getInteger());
            } else {
                dfs(nexted.getList());
            }
        }
    }
};