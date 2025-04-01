class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> uMap;
        for (int i = 0; i < nums.size(); i++) {
            auto targetVal = uMap.find(target - nums[i]);
            if (targetVal == uMap.end()) {
                uMap.insert({nums[i], i});
            }else {
                return {targetVal->second, i};
            }
        }
        return {};
    }
};