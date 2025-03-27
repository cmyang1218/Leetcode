class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int, int> freqMap;
        for (auto& num : nums) {
            freqMap[num]++;
        }
        vector<pair<int, int>> freqVec;
        for (auto& it : freqMap) {
            freqVec.push_back(it);
        }
        sort(freqVec.begin(), freqVec.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });
        int dom = freqVec[0].first, domFreq = freqVec[0].second;
        int subDomFreq1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == dom) {
                subDomFreq1++;
            }
            int subDomFreq2 = domFreq - subDomFreq1;
            if (subDomFreq1 * 2 > (i + 1) && subDomFreq2 * 2 > (nums.size() - i - 1))
                return i;
        }
        return -1;
    }
};