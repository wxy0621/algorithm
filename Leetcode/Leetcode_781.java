// 森林中的兔子
// 哈希
class Solution {
    public int numRabbits(int[] answers) {
        int n = answers.length;
        int res = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int answer: answers) {
            if (map.containsKey(answer)) map.put(answer, map.get(answer) + 1);
            else map.put(answer, 1);
        }
        for (Map.Entry<Integer, Integer> entry: map.entrySet()) {
            int y = entry.getKey(), x = entry.getValue();
            res += (x + y) / (y + 1) * (y + 1);
        }

        return res;
    }
}