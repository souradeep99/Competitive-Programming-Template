// count [l,r] >= k,  0 based indexing
struct SegTree {
    int n;
    vector<vector<int>> tree;
    SegTree(int n_) {
        n = 1; while (n < n_) n <<= 1;
        tree.resize(2 * n);
    }
    void add(int i, int x) {
        tree[n + i].push_back(x);
    }
    void build() {
        for (int i = n - 1; i > 0; i--)
            merge(tree[i * 2].begin(), tree[i * 2].end(),tree[i * 2 + 1].begin(), tree[i * 2 + 1].end(),back_inserter(tree[i]));
    }
    int query(int i, int j, int x) {
        int cnt = 0;
        int l = i, r = j;
        for (i += n, j += n; i <= j; i = (i + 1) >> 1, j = (j - 1) >> 1){
            if ((i & 1) == 1) cnt += tree[i].end() - lower_bound(tree[i].begin(), tree[i].end(), x);
            if ((j & 1) == 0) cnt += tree[j].end() - lower_bound(tree[j].begin(), tree[j].end(), x);
        }
        return cnt;
    }
};
 
//SegTree seg(n);
//for(int i = 0; i < n; i++)
// 	cin >> a[i], seg.add(i, a[i]);
//seg.build();
//seg.query(l, r, k); //[l,r] >= k
