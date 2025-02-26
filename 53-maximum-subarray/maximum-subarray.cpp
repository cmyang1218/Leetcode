class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], curMaxSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curMaxSum = max(curMaxSum + nums[i], nums[i]);
            maxSum = max(maxSum, curMaxSum);
        }
        return maxSum;
    }
};