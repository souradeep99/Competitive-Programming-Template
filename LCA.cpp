//dfs(1, 0);
//init(P, -1);
//pre(1, 0);
 
int lvl[N], P[N][LG];
vector<int>g[N];
 
void dfs(int u, int par){
    lvl[u] = 1+lvl[par];
    P[u][0] = par;
    for(int v:g[u]){
        if (v == par) continue;
        dfs(v, u);
    }
}
 
int lca(int u, int v){
    int i, lg;
    if (lvl[u] < lvl[v]) swap(u, v);
 
    for(lg = 0; (1<<lg) <= lvl[u]; lg++);
    lg--;
 
    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= lvl[v])
            u = P[u][i];
    }
 
    if (u == v) 
        return u;
 
    for(i=lg; i>=0; i--){
        if (P[u][i] != -1 and P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    }
 
    return P[u][0];
}
 
void pre(int u, int p){
    P[u][0] = p;
    for(int i = 1; i < LG; i++)
        P[u][i] = P[P[u][i-1]][i-1];
 
    for(auto i: g[u])
        if(i != p)
            pre(i, u);
}
 
//Get the ancestor of node "u"
//which is "dis" distance above.
int getAncestor(int u, int dis){
    dis = lvl[u] - dis;
    int i, lg = 0;
    for(; (1<<lg) <= lvl[u]; lg++); lg--;
 
    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= dis)
            u = P[u][i];
    }
 
    return u;
}
 
//returns the distance between
//two nodes "u" and "v".
int dis(int u, int v){
    if (lvl[u] < lvl[v]) swap(u, v);
    int w = lca(u, v);
    return lvl[u] + lvl[v] - 2*lvl[w];
}
 
