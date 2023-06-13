class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved){
           
        vector<vector<int>> ret;
        for (int i = 0; i < intervals.size(); i++) {
            int a, b;
            if (intervals[i][0] < toBeRemoved[0]) {
                a = intervals[i][0];
                b = min(intervals[i][1], toBeRemoved[0]);
                ret.push_back({a, b});
            }

            if (toBeRemoved[1] < intervals[i][1]) {
                a = max(intervals[i][0], toBeRemoved[1]);
                b = intervals[i][1];
                ret.push_back({a, b});
            }
        }

        return ret;
    }
};