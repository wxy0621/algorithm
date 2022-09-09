// 对角线遍历
class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int m = mat.length;
        if (m == 0) return new int[0];
        int n = mat[0].length;
        if (n == 0) return new int[0];
        int[] res = new int[m*n];
        int i = 0, j = 0, k = 0;
        res[k++] = mat[i][j];
        if (n == 1) ++i;
        else ++j;
        boolean flagInc = false;
        while (k < m * n) {
            if (flagInc) { // 右上
                while (i >= 0 && j < n) {
                    res[k++] = mat[i--][j++];
                }
                if (j >= n) {
                    i += 2;
                    --j;
                } else {
                    ++i;
                }
                flagInc = false;
            } else { // 左下
                while (i < m && j >= 0) {
                    res[k++] = mat[i++][j--];
                }
                if (i >= m) {
                    j += 2;
                    --i;
                } else {
                    ++j;
                }
                flagInc = true;
            }
        }
        return res;
    }
}