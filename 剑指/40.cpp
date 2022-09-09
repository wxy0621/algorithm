// 最小的k个数，方法一优先队列，方法二partition函数
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k, 0);
        if(k == 0) return res;
        priority_queue<int> q;
        for(int i = 0; i < k; ++i)
            q.push(arr[i]);
        for(int i = k; i < arr.size(); ++i)
        {
            if(q.top() > arr[i])
            {
                q.pop();
                q.push(arr[i]);
            }
        }
        for(int i = 0; i < k; ++i)
        {
            res[i] = q.top();
            q.pop();
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int n = arr.size();
        if(n == k) return arr;
        if(n < k || n == 0 || k <= 0) return vector<int>();
        int l = 0, r = n - 1;
        int index = partition(arr, l, r);
        while(index != k - 1)
        {
            if(index > k -1)
                r = index - 1;
            else
                l = index + 1;
            index = partition(arr, l, r);
        }
        return vector<int>(arr.begin(), arr.begin()+k);
    }

    int partition(vector<int>& arr,int l, int r)
    {
        int temp = arr[l];
        int index = l;
        while(l < r) {
            while(l < r && arr[r] >= temp)
                r--;
            while(l < r && arr[l] <= temp)
                l++;
            swap(arr[l], arr[r]);
        }
        swap(arr[index], arr[l]);
        return l;
    }
};

int main()
{

    return 0;
}