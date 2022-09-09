// 公交站间的距离
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int res1 = 0, res2 = 0;
        int n = distance.size();
        if(start > destination) swap(start, destination);
        for(int i = 0; i < distance.size(); ++i) {
            if(i >= start && i < destination) res1 += distance[i];
            else res2 += distance[i];
        }
        return min(res1, res2);
    }
};
