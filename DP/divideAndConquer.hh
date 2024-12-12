/**
 * Description: when $opt[i][j] \leq opt[i][j + 1]$
 * Time: $O(kn\log n)$
 */
void calc(int tl, int tr, int l, int r, int layer){
    if(tl > tr) return;
    int mid = (tl + tr) >> 1;
    int opt = -1;
    for (int i = l; i <= min(r, mid - 1); ++i) {
        if (dp[mid][layer + 1] > dp[i][layer] + cost[i + 1][mid]) {
            opt = i;
            dp[mid][layer + 1] = dp[i][layer] + cost[i + 1][mid];
        }
    }
    calc(tl, mid - 1, l, opt, layer);
    calc(mid + 1, tr, opt, r, layer);
}