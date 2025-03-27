class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> numsArr;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                numsArr.push_back(grid[i][j]);
            }
        }
        nth_element(numsArr.begin(), numsArr.begin() + numsArr.size() / 2, numsArr.end());
        int median = numsArr[numsArr.size() / 2];
        int ret = 0;
        for (auto& num : numsArr) {
            if (num % x != median % x) {
                return -1;
            }else {
                ret += abs(num - median) / x;
            }
        }
        return ret;
    }
};