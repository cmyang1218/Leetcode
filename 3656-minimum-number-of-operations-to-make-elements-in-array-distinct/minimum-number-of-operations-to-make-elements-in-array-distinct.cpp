class Solution {
public:
    bool countFrequency(vector<int>& nums) {
        unordered_map<int, int> u_map;
        for (int i = 0; i < nums.size(); i++) {
            u_map[nums[i]]++;
        }
        for (auto& it : u_map) {
            if (it.second != 1) {
                return false;
            }
        }
        return true;
    }

    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        while (!nums.empty() && !countFrequency(nums)) {
            if (nums.size() < 3)
                nums.erase(nums.begin(), nums.end());
            else
                nums.erase(nums.begin(), nums.begin() + 3);
            cnt++;
        }
        return cnt;
    }
};