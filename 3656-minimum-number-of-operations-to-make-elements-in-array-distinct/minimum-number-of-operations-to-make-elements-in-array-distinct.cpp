class Solution {
public:

    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> u_map;
        for (auto& num : nums) {
            u_map[num]++;
        }
        int cnt = 0;
        while (!nums.empty()) {
            cout << nums.size() << endl;
            for (auto& it : u_map) {
                cout << it.first << ' ' << it.second << endl;
                if (it.second > 1) {
                    cnt++;
                    break;
                }
            }
            if (nums.size() < 3) {
                for (auto& num : nums) {
                    u_map[num]--;
                }
                nums.erase(nums.begin(), nums.end());
            }else {
                for (int i = 0; i < 3; i++) {
                    u_map[nums[i]]--;
                }
                nums.erase(nums.begin(), nums.begin() + 3);
            }
        }
        return cnt;
    }
};