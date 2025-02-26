class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int curMaxSum = 0, curMinSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            curMaxSum = max(curMaxSum + nums[i], nums[i]);
            curMinSum = min(curMinSum + nums[i], nums[i]);
            maxSum = max(curMaxSum, maxSum);
            minSum = min(curMinSum, minSum);
        }
        return abs(maxSum) > abs(minSum) ? abs(maxSum) : abs(minSum);
    }
};