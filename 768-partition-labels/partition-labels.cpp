class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> intervals;
        vector<int> firstOcc(26, -1), lastOcc(26, -1);
        for (int i = 0; i < s.length(); i++) {
            if (firstOcc[s[i] - 'a'] == -1) {
                firstOcc[s[i] - 'a'] = i; 
                lastOcc[s[i] - 'a'] = i;
            }else {
                lastOcc[s[i] - 'a'] = i;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (firstOcc[i] != -1 && lastOcc[i] != -1) {
                intervals.push_back({firstOcc[i], lastOcc[i]});
            }
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals;
        for (auto& interval : intervals) {
            if (mergedIntervals.empty() || mergedIntervals.back()[1] < interval[0]) {
                mergedIntervals.push_back(interval);
            }else {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], interval[1]);
            }
        }
        vector<int> ret;
        for (auto& interval : mergedIntervals) {
            ret.push_back(interval[1] - interval[0] + 1);
        }
        return ret;
    }
};