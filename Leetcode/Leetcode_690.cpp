// 员工的重要性
// hash & 索引
// bfs
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> information;
        for (auto& employee: employees) information[employee->id] = employee;
        queue<Employee*> q;
        int res = 0;
        q.push(information[id]);
        while (!q.empty()) {
            Employee* temp = q.front();
            q.pop();
            res += temp->importance;
            int n = temp->subordinates.size();
            for (int i = 0; i < n; ++i) q.push(information[temp->subordinates[i]]);
        }
        return res;
    }
};

// dfs
class Solution2 {
public:
    void dfs(int id, int& res) {
        Employee* temp = information[id];
        res += temp->importance;
        for (auto& t: temp->subordinates) dfs(t, res);
    }
    int getImportance(vector<Employee*> employees, int id) {
        for (auto& employee: employees) information[employee->id] = employee;
        int res = 0;
        dfs(id, res);
        return res;
    }
private:
    unordered_map<int, Employee*> information;
};