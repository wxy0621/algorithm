// 救生艇
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int left = 0, right = n - 1;
        int res = 0;
        while (left <= right) {
            if (left == right) {
                ++res;
                break;
            }
            if (people[left] + people[right] > limit) {
                --right;
                ++res;
            } else {
                ++res;
                ++left;
                --right;
            }
        }
        return res;
    }
};