class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        
        // Initialize the base case
        for (int j = 0; j < 5; ++j) {
            dp[1][j] = 1;
        }
        
        // Fill the dp table
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][0] + dp[i-1][1];
            dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
            dp[i][3] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3];
            dp[i][4] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4];
        }
        
        // Sum up the counts for strings of length n
        int result = 0;
        for (int j = 0; j < 5; ++j) {
            result += dp[n][j];
        }
        
        return result;
    }
};