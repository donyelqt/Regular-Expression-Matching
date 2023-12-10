#include <vector>
#include <iostream>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.size();
        int n = p.size();

        // dp[i][j] will be true if the first i characters in s match the first j characters in p
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        // Empty pattern matches empty string
        dp[0][0] = true;

        // Handle patterns with '*' at the beginning
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Build the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
            }
        }

        return dp[m][n];
    }
};
