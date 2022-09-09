// 钥匙和房间
// dfs
class Solution {
public:
    int num = 0;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> inroom(n, false);
        dfs(rooms, 0, inroom);
        return num == n;
    }
    void dfs(vector<vector<int>>& rooms, int i, vector<bool>& inroom) {
        inroom[i] = true;
        ++num;
        for(auto& room: rooms[i]) {
            if(!inroom[room]) dfs(rooms, room, inroom);
        }
    }
};