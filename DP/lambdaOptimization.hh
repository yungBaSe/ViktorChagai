/**
 * Description: Transforming CHT to:
 * to $dp[i] = min(dp[j] + cost(j + 1, i)) + \lambda$
 * Using binary search for $\lambda$ to find first 
 * that best number of segments is exactly $k$
 * Time: $O(n\log n)$
 */
void init() {
    for (int i = 0; i < maxn; i++) {
        dp[i] = make_pair(inf, 0);
    }
}
pair <ll, int> check(ll x) { // change this to CHT
    init();
    dp[0] = make_pair(0ll, 0); // 1-indexation
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = min(dp[i], {dp[j].first + cost[j + 1][i] + x, dp[j].second + 1});
        }
    }
    return dp[n];
}
ll solve() {
    ll l = -1e14;
    ll r = 1;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        pair<ll, int> x = check(mid);
        if (x.second >= k) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    pair<ll, int> result = check(l);
    return result.first - l * return.second;
}