class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCount = 0, posCount = 0;
        for (auto num : nums) {
            if (num > 0) {
                posCount++;
            }else if (num < 0) {
                negCount++;
            }
        }
        return max(posCount, negCount);
    }
};