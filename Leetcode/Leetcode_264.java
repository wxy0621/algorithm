// 丑数 II
// 哈希 + 最小堆
class Solution {
    public int nthUglyNumber(int n) {
        int[] nums = {2, 3, 5};
        Set<Long> set = new HashSet<Long>();
        PriorityQueue<Long> q = new PriorityQueue<Long>();
        set.add(1L);
        q.offer(1L);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            long temp = q.poll();
            res = (int) temp;
            for (int num: nums) {
                long addNum = num * temp;
                if (set.add(addNum)) q.offer(addNum);
            }
        }
        return res;
    }
}

// dp
class Solution2 {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        int n2 = 0, n3 = 0, n5 = 0;
        for (int i = 1; i < n; ++i) {
            int temp2 = dp[n2] * 2, temp3 = dp[n3] * 3, temp5 = dp[n5] * 5;
            int minNum = Math.min(temp2, Math.min(temp3, temp5));
            dp[i] = minNum;
            if (minNum == temp2) ++n2;
            if (minNum == temp3) ++n3;
            if (minNum == temp5) ++n5;
        }
        return dp[n-1];
    }
}