// 顶端迭代器
class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    hasNextFlag = Iterator::hasNext();
        if (hasNextFlag) {
            nextVal = Iterator::next();
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return nextVal;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int ret = nextVal;
        hasNextFlag = Iterator::hasNext();
        if (hasNextFlag) {
            nextVal = Iterator::next();
        }
	    return ret;
	}
	
	bool hasNext() const {
	    return hasNextFlag;
	}
private:
    bool hasNextFlag;
    int nextVal;
};