// 一次编辑
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n1 = first.size();
        int n2 = second.size();
        if (n1 - n2 > 1 || n2 - n1 > 1) return false;
        bool isEdit = false;
        if (n1 == n2) {
            for (int i = 0; i < n1; ++i) {
                if (first[i] != second[i]) {
                    if (isEdit) return false;
                    else isEdit = true;
                }
            }
        } else if (n1 + 1 == n2) {
            int j = 0;
            for (int i = 0; i < n2; ++i) {
                if (first[j] != second[i]) {
                    if (isEdit) return false;
                    isEdit = true;
                } else ++j;
            }
        } else {
            int j = 0;
            for (int i = 0; i < n1; ++i) {
                if (first[i] != second[j]) {
                    if (isEdit) return false;
                    isEdit = true;
                } else ++j;
            }
        }
        return true;
    }
};