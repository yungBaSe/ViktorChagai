/**
 * Description: SCC=)
 * Time: O(N+E)
 */
vector <vector <int>> g, gr;
vector <char> used;
vector <int> order, component;
void dfs1 (int v) {
	used[v] = true;
	for (int u : g[v])
		if (!used[u])
			dfs1(u);
	order.push_back(v);
}
void dfs2 (int v) {
	used[v] = true;
	component.push_back(v);
	for (int u : gr[v])
		if (!used[u])
			dfs2(u);
}
vector <vector <int>> SCC_find() {
    int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		gr[b].push_back(a);
	}
	used.assign (n, false);
	for (int i = 0; i < n; ++i)
		if (!used[i])
			dfs1(i);
	used.assign (n, false);
    vector <vector <int>> components;
	for (int i = 0; i < n; ++i) {
		int v = order[n - 1 - i];
		if (!used[v]) {
			dfs2 (v);
			components.push_back(component);
			component.clear();
		}
	}
    return components;
}