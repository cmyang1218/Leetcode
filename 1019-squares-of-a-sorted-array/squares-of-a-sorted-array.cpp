class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 0);
        int i = 0, j = len-1, k = len-1;
        while (i <= j) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                res[k--] = nums[i] * nums[i];
                i++;
            }else {
                res[k--] = nums[j] * nums[j];
                j--;
            }
        }
        return res;
    }
};