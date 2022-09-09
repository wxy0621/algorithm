// 钥匙和房间
// dfs
class Solution {
    private int count;
    boolean[] inRoom;
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        count = 0;
        int n = rooms.size();
        inRoom = new boolean[n+1];
        inRoom[0] = true;
        dfs(rooms, 0);
        return count == n;
    }
    public void dfs(List<List<Integer>> rooms, int index) {
        inRoom[index] = true;
        ++count;
        for (int room: rooms.get(index)) {
            if (!inRoom[room]) dfs(rooms, room);
        }
    }
}