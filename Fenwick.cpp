//Fenwick bit(n);
//bit.range_update(2,5,7);
//bit.range_update(3,4,-6);
 
//1 based indexing
struct Fenwick {
    int n; vector<int> t;
    Fenwick(int n_): n(n_), t(n_ + 1) {}
 
    //range update point query
    int query(int i) { int v = 0; for (; i > 0; i -= (i & -i)) v += t[i]; return v; }
    void update(int i, int v) { for (; i <= n; i += (i & -i)) t[i] += v; } //add v to i
    void range_update(int l, int r, int v) { update(l,v); update(r + 1, -v); }
 
    //point update range query
    void add(int i, int v) { for (; i <= n; i += i & -i) t[i] += v; } //add v to i
    int sum(int i) {int v = 0;for (; i > 0; i -= i & -i) v += t[i]; return v; }
    int range_sum(int l, int r) { return sum(r) - sum(l - 1); }
};
