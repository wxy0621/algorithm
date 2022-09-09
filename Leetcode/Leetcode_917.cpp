// 仅仅反转字母
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int n = S.size();
        int i = 0, j = n - 1;
        while(i < j) {
            if(!isalpha(S[i])) ++i;
            if(!isalpha(S[j])) --j;
            if(isalpha(S[i]) && isalpha(S[j])) swap(S[i++], S[j--]);
        }
        return S;
    }
};

// 这种较慢，判断的条件太多了
class Solution2 {
public:
    string reverseOnlyLetters(string S) {
        int n = S.size();
        int i = 0, j = n - 1;
        while(i < j) {
            while(!isalpha(S[i]) && i < j) ++i;
            while(!isalpha(S[j]) && i < j) --j;
            if(isalpha(S[i]) && isalpha(S[j]) && i < j) swap(S[i++], S[j--]);
        }
        return S;
    }
};