// 在既定时间做作业的学生人数
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int res = 0;
        int student_number = startTime.size();
        for(int i = 0; i < student_number; ++i) {
            if(startTime[i] <= queryTime && queryTime <= endTime[i]) ++res;
        }

        return res;
    }
};