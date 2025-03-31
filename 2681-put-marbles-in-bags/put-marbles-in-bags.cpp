class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> pairWeights;
        size_t n = weights.size();
        for (int i = 0; i < n-1; i++) {
            pairWeights.push_back(weights[i] + weights[i+1]);
        }
        sort(pairWeights.begin(), pairWeights.end());
        long long maxScore = weights[0] + weights[n-1];
        long long minScore = weights[0] + weights[n-1];
        for (int i = 0; i < k-1; i++) {
            minScore += pairWeights[i];
        }
        for (int i = 0; i < k-1; i++) {
            maxScore += pairWeights[n-i-2];
        }
        return maxScore - minScore;
    }
};