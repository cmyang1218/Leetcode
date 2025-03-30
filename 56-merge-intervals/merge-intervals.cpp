class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        for (auto& interval : intervals) {
            if (ret.empty() || ret.back()[1] < interval[0]) {
                ret.push_back(interval);
            }else {
                ret.back()[1] = max(ret.back()[1], interval[1]);
            }
        }
        return ret;
    }
};