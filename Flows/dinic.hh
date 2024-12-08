// TODO: create a structure

const int MAXN = 200;

struct Edge{
    int to, c, f = 0;
    Edge (int _to, int _c) {
        to = _to;
        c = _c;
    }
};
 
vector <Edge> edges;
vector <int> g[MAXN], ans_g[MAXN];
bool used[MAXN];
int d[MAXN], ptr[MAXN];
int n, S, T, even, odd;
 
void add_edge(int u, int v, int c){
    g[u].push_back(edges.size());
    edges.emplace_back(v, c);
    g[v].push_back(edges.size());
    edges.emplace_back(u, 0);
}
 
bool bfs(){
    memset(d, -1, n * sizeof(d[0]));
    queue <int> q;
    d[S] = 0;
    q.push(S);
    while (!q.empty() && d[T] == -1) {
        int v = q.front();
        q.pop();
        for( int id : g[v]) {
            int u = edges[id].to, c = edges[id].c, f = edges[id].f;
            if (d[u] == -1 && c > f) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    return d[T] != -1;
}
 
int dfs(int v, int flow){
    if (!flow) return 0;
    if (v == T) return flow;
    for (int &i = ptr[v]; i < g[v].size(); ++i) {
        int id = g[v][i];
        int u = edges[id].to, c = edges[id].c, f = edges[id].f;
        if (d[u] != d[v] + 1) continue;
        int pushed = dfs(u, min(flow, c - f));
        if (pushed) {
            edges[id].f += pushed;
            edges[id ^ 1].f -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic() {
    int res = 0;
    while(bfs()){
        memset(ptr, 0, (n + 2) * sizeof(ptr[0]));
        while (int pushed = dfs(S, INF)){ res += pushed; }
    }
    return res;
}