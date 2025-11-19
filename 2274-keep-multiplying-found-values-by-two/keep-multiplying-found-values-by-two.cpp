class Solution {
public:
    bool binary_search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }

    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        while (binary_search(nums, original)) {
            original *= 2;
        }
        return original;
    }
};