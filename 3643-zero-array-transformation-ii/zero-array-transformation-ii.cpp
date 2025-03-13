class Solution {
public:
    bool findZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff (n+1, 0);
        for (int i = 0; i < k; i++) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] += val;
            diff[r+1] -= val;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += diff[i];
            if (cnt < nums[i]) 
                return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size();
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (findZeroArray(nums, queries, mid)) {
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return left <= queries.size() ? left : -1;
    }
};