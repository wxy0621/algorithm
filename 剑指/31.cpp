#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> a;
        int j = 0;
        int i = 0;
        while(i != popped.size())
        {
            if(a.size() == 0 || a.top() != popped[i])
            {
                if(j == pushed.size())
                    return false;
                a.push(pushed[j]);
                j++;
            } else {
                a.pop();
                i++;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}