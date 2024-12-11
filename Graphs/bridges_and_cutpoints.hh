// TODO: create a structure

vector <int> g[MAXN];
bool used[MAXN];
int h[MAXN], d[MAXN];
set <int> ans;
void dfs_cutpoints(int v, int p = -1) {
    used[v] = 1;
    d[v] = h[v];
    int childrens = 0;
    for (int u : g[v]) {
        if (u == p)
            continue;
        if (!used[u]) {
            ++childrens;
            h[u] = h[v] + 1;
            dfs(u, v);
            d[v] = min(d[v], d[u]);
            if (h[v] <= d[u] && p != -1) {
                ans.insert(v);
            }
        } else {
            d[v] = min(d[v], h[u]);
        }
    }
    if (p == -1 && childrens > 1) {
        ans.insert(v);
    }
}
void dfs_bridges(int v, int p) {
    used[v] = 1;
    d[v] = h[v];
    for (int u : g[v]) {
        if (u == p)
            continue;
        if (!used[u]) {
            h[u] = h[v] + 1;
            dfs(u, v);
            d[v] = min(d[v], d[u]);
            if (h[v] < d[u]) {
                ans.push_back({v, u});
            }
        } else {
            d[v] = min(d[v], h[u]);
        }
    }
}
