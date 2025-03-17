class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int> numMap;
        for (auto num : nums) {
            numMap[num]++;
        }
        bool ret = true;
        for (auto n : numMap) {
            if (n.second & 1) {
                ret = false;
                break;
            }
        }
        return ret;
    }
};