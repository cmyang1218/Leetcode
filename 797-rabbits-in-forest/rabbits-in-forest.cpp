class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> uMap;
        int cnt = 0;
        for (auto& ans : answers) {
            if (!uMap.count(ans) || uMap[ans] == 0) {
                cnt += (ans + 1);
                uMap[ans] = ans;
            }else {
                uMap[ans]--;
            }
        }
        return cnt;
    }
};