// 课程表
// 有向图
// 建立 邻接表 并记录 入度，将入度 为 0 的不断加入队列，并记录 入度非0 的节点的个数，最后如果个数为零的则是非环的图
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses);
        vector< vector<int> > adjacent(numCourses);
        queue<int> q;
        int num = numCourses;
        for(int i = 0; i < prerequisites.size(); ++i) {
            ++in_degree[prerequisites[i][0]];
            adjacent[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
        }
        for(int i = 0; i < numCourses; ++i) {
            if(in_degree[i] == 0) {
                --num;
                q.push(i);
            }
        }
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            for(int i = 0; i < adjacent[temp].size(); ++i) {
                if(--in_degree[adjacent[temp][i]] == 0) {
                    q.push(adjacent[temp][i]);
                    --num;
                }
            }
        }
        if(num == 0) return true;
        return false;
    }
};