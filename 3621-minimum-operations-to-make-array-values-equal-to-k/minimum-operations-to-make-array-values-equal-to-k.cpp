class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        for (auto& num : nums) {
            if (num < k) {
                return -1;
            }else if (num > k) {
                s.insert(num);
            }
        }
        return s.size();
    }
};