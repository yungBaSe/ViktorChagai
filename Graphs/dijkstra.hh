/**
 * Description: Bro=) pora uzhe zabotat')))
 */
vector <pair <int, int>> g[MAXN];
int n;
vector<int> dijkstra_fast(int s) {
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    set <pair <int, int>> q;
    q.emplace(0, s);
    while (!q.empty()) {
        auto [d, u] = *q.begin();
        q.erase(q.begin());
        for (auto [v, w] : g[u]) {
            if (dist[u] + w < dist[v]) {
                q.erase({dist[v], v});
                dist[v] = dist[u] + w;
                q.insert({dist[v], v});
            }
        }
    } 
    return dist;
}
vector<int> dijkstra_slow(int s) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[s] = 0;
    for (int i = 0, u = -1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        if (dist[u] == INT_MAX) break;
        visited[u] = true;
        for (auto [v, w] : g[u]) 
            dist[v] = min(dist[v], dist[u] + w);
    }
    return dist;
}
