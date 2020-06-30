//special
 
//1. findcnt(l, r, val) is number of Ai(i = l..r) such that Ai ≤ val
//2. findsum(l, r, val) is sum of Ai(i = l..r) such that Ai ≤ val
//0 based index
 
vector<int> a, b;
 
template<class T>
struct segtree{ // [l,r)
    int n;
    vector<vector<T>> sum, all;
    segtree(int sz){
        n = (1 << ((int)(log2(sz - 1)) + 1));
        sum.resize(n + n);
        all.resize(n + n);
    }
    void build(int root, int l, int r){
        if (l >= r) return;
        if (l >= a.size()) return;
        if (l + 1 == r){
            all[root].push_back(a[l]);
            sum[root].push_back(a[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(root<<1, l, mid);
        build(root<<1|1, mid, r);
        all[root].resize(all[root<<1].size() + all[root<<1|1].size());
        merge(all[root<<1].begin(), all[root<<1].end(), all[root<<1|1].begin(), all[root<<1|1].end(), all[root].begin());
        sum[root].resize(all[root<<1].size() + all[root<<1|1].size());
        for (int i = 0; i < sum[root].size(); i++)
            sum[root][i] = all[root][i] + (i == 0 ? 0 : sum[root][i - 1]);
    }
    int find_cnt(int x, int y, T val, int root, int l, int r){
        if (r <= x || l >= y) return 0;
        if (l >= x && r <= y){
            int p = (int)(upper_bound(all[root].begin(), all[root].end(), val) - all[root].begin());
            return p;
        }
        int mid = (l + r) >> 1;
        return find_cnt(x, y, val, root<<1, l, mid) + find_cnt(x, y, val, root<<1|1, mid, r);
    }
    int find_cnt(int x, int y, T val){
        return find_cnt(x, y, val, 1, 0, n);
    }
    T find_sum(int x, int y, T val, int root, int l, int r){
        if (r <= x || l >= y) return 0;
        if (l >= x && r <= y){
            int p = (int)(upper_bound(all[root].begin(), all[root].end(), val) - all[root].begin());
            return (p == 0 ? 0 : sum[root][p - 1]);
        }
        int mid = (l + r) >> 1;
        return find_sum(x, y, val, root<<1, l, mid) + find_sum(x, y, val, root<<1|1, mid, r);
    }
    T find_sum(int x, int y, T val){
        return find_sum(x, y, val, 1, 0, n);
    }
};
 
/*
vector<int>a,b; //global
int n;
cin >> n;
a.resize(n);
for(int i = 0; i < n; i++)
    cin >> a[i];
b = a;
sort(b.begin(), b.end());
 
segtree<int> T(n);
T.build(1, 0, T.n); // [l,r)
T.find_sum(l, r + 1, k) << endl; //[l,r)
T.find_cnt(l, r + 1, k) << endl; //[l,r)
*/
