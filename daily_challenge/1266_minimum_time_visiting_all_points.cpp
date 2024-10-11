class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        vector<int> cur=points[0]; 
        for(const auto& point:points){
            time+=max(abs(point[1]-cur[1]),abs(point[0]-cur[0]));
            cur = point;
        }
        return time;
    }
};
