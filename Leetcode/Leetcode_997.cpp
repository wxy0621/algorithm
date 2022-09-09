// 找到小镇的法官
// 图，出度 0，入度 N - 1
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> _out(N, 0);
        vector<int> _in(N, 0);
        for(auto& person: trust) {
            ++_out[person[0] - 1];
            ++_in[person[1] - 1];
        }
        for(int i = 0; i < N; ++i) {
            if(_out[i] == 0 && _in[i] == N - 1) return i + 1;
        }
        return -1;
    }
};

// 优化，入度和出度之差为 N - 1
class Solution2 {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> temp(N, 0);
        for(auto& person: trust) {
            --temp[person[0] - 1];
            ++temp[person[1] - 1];
        }
        for(int i = 0; i < N; ++i) {
            if(temp[i] == N - 1) return i + 1;
        }
        return -1;
    }
};