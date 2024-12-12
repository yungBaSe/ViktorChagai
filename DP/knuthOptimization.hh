/**
 * Description: when $opt[i - 1][j] \leq opt[i][j] \leq opt[i][j + 1]$
 * Time: $O(n^2)$
 */
for (int len = 2; len <= n; ++len) {
    for (int l = 0; l <= n - len; ++l) {
        int r = l + len;
        for (int i = cut[l][r - 1]; i <= cut[l + 1][r]; ++i) {
            if (dp[l][r] > cost[l + 1][i] + dp[l][i] + cost[i + 2][r] + dp[i + 1][r]) {
                cut[l][r] = i;
                dp[l][r] = cost[l + 1][i] + dp[l][i] + cost[i + 2][r] + dp[i + 1][r];
            }
        }
    }
}