vector<pair<int, int>> adj[N];
int p[N];
int d[N];
 
void dijkstra(int s) {
 
    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;
 
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
 
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

/*
for(int i = 0; i <= n; i++){
     adj[i].clear();
     d[i] = BINF, p[i] = -1;
}
 
adj[u].push_back(make_pair(v, w)); 
adj[v].push_back(make_pair(u, w));
 
dijkstra(src);
*/
