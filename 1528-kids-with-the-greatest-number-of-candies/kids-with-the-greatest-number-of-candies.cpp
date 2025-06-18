class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ret;
        int maxCandy = *max_element(candies.begin(), candies.end());
        for (auto& kids : candies) {
            ret.push_back(kids + extraCandies >= maxCandy); 
        }
        return ret;
    }
};