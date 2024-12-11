// TODO: create a structure

const int MAXN = 200;
const int INF = 1e9;
int n;
int cost[MAXN][MAXN], cap[MAXN][MAXN];
int d[MAXN], pot[MAXN], par[MAXN];
bool edge[MAXN][MAXN];
bool dijkstra (int s, int t) {
    vector <bool> used(n, 0);
    fill(d, d + n, INF);
    d[s] = 0;
    while (1) {
        int v = -1;
        for (int u = 0; u < n; u++)
            if (!used[u] && (v == -1 || d[u] < d[v]))
                v = u;
        if (v == -1 || d[v] == INF)
            break;
        used[v] = 1;
        for (int u = 0; u < n; u++) {
            int w = cost[v][u] + pot[v] - pot[u];
            if (cap[v][u] > 0 && d[u] > d[v] + w) {
                d[u] = d[v] + w;
                par[u] = v;
            }
        }
    }
    return d[t] != INF;
}
int mincost_maxflow (int s, int t) {
    int ans = 0;
    while (dijkstra(s, t)) {
        for (int i = 0; i < n; ++i)
            pot[i] += d[i];
        int delta = INF;
        for (int v = t; v != s; v = par[v])
            delta = min(delta, cap[par[v]][v]);
        for (int v = t; v != s; v = par[v]) {
            cap[par[v]][v] -= delta;
            cap[v][par[v]] += delta;
            ans += cost[par[v]][v] * delta;
        }
    }
    return ans;
}