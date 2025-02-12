class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0, len = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                len = j - i + 1;
                result = min(result, len);
                sum -= nums[i++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};