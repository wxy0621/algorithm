// 目标和
// 枚举遍历
class Solution {
    private int count = 0;
    public int findTargetSumWays(int[] nums, int S) {
        calculate(nums, 0, 0, S);
        return count;
    }
    public void calculate(int[] nums, int i, int sum, int S) {
        if (i == nums.length) {
            if (sum == S) ++count;
            return;
        }
        calculate(nums, i + 1, sum + nums[i], S);
        calculate(nums, i + 1, sum - nums[i], S);
    }
}

// dp
class Solution2 {
    public int findTargetSumWays(int[] nums, int S) {
        int n = nums.length;
        int[][] dp = new int[n][2001];
        dp[0][1000 + nums[0]] = 1;
        dp[0][1000 - nums[0]] += 1;  // 第一个数字可能是 0，所以要用 +=
        for (int i = 1; i < n; ++i) {
            for (int j = -1000; j <= 1000; ++j) {
                if (dp[i-1][j + 1000] > 0) {
                    dp[i][j + nums[i] + 1000] += dp[i-1][j + 1000];
                    dp[i][j - nums[i] + 1000] += dp[i-1][j + 1000];
                }
            }
        }
        return S > 1000 ? 0 : dp[n-1][S+1000];
    }
}

// 空间优化版本
class Solution3 {
    public int findTargetSumWays(int[] nums, int S) {
        int n = nums.length;
        int[] dp = new int[2001];
        dp[1000 + nums[0]] = 1;
        dp[1000 - nums[0]] += 1;  // 第一个数字可能是 0，所以要用 +=
        for (int i = 1; i < n; ++i) {
            int[] next = new int[2001];
            for (int j = -1000; j <= 1000; ++j) {
                if (dp[j + 1000] > 0) {
                    next[j + nums[i] + 1000] += dp[j + 1000];
                    next[j - nums[i] + 1000] += dp[j + 1000];
                }
            }
            dp = next;
        }
        return S > 1000 ? 0 : dp[S+1000];
    }
}