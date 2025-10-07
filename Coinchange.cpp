//leetcode 518
class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        int n = coins.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, 0));

        // Base case: There's one way to make an amount of 0 (by using no coins).
        for (int i = 0; i < n + 1; i++) {
            dp[i][0] = 1;
        }

        // Fill the DP table
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < amount + 1; j++) { // Corrected: removed extra comma
                if (coins[i - 1] <= j) {
                    // Option 1: Include the current coin
                    // Option 2: Exclude the current coin
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                } else {
                    // Current coin is too large, so exclude it
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        for(int i=0;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                cout<< dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n][amount];
    }
};