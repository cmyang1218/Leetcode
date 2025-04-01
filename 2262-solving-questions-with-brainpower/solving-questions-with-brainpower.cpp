class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        dp[n-1] = questions[n-1][0];
        for (int i = n-2; i >= 0; i--) {
            int point = questions[i][0];
            int brainpower = questions[i][1];
            if (i + brainpower + 1 < n)
                dp[i] += dp[i + brainpower + 1];
            
            dp[i] = max(point + dp[i], dp[i+1]);
        }
        return dp[0];
    }
};