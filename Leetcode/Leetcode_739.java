// 每日温度
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int n = T.length;
        int[] res = new int[n];
        Deque<Integer> stk = new LinkedList<Integer>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && T[stk.peek()] <= T[i]) {
                stk.pop();
            }
            if(stk.isEmpty()) res[i] = 0;
            else res[i] = stk.peek() - i;
            stk.push(i);
        }
        return res;
    }
}