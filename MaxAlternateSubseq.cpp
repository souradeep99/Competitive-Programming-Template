//a1 a2 a3 a4 ...... aN given (-1e9 <= ai <= 1e9, 1 <= i <= N)
//update a value in pos with val
//find maximum sum of alternating subsequence from [l, r], 
//more formally choose k indices b1, b2, ...., bk (k > 0, b1 >= l, bk <= r) such that
//a[b1] - a[b2] + a[b3] - a[b4] + .... +/- a[bk] is maximum

//below code uses 1 based indexing with dynamic memory allocation
//each node has 4 value {start : end-> pos + pos, pos + neg, neg + pos, neg + neg}
//SegTree seg(n, a); //[a = vector of N numbers]
//seg.build(1, n, 1);
//seg.update(pos, val, 1, n, 1);
//seg.query(1, 1, n, l, r);

//easy version: https://codeforces.com/contest/1420/problem/C2

struct SegTree{
    struct Node{
        int pp, pn, np, nn;
    };
    Node merge(Node x, Node y){
        Node cur;
        cur.pp = max(x.pp + y.np, x.pn + y.pp);
        cur.pn = max(x.pp + y.nn, x.pn + y.pn);
        cur.np = max(x.nn + y.pp, x.np + y.np);
        cur.nn = max(x.np + y.nn, x.nn + y.pn);
        return cur;
    }
    int n;
    vector<int> a;
    vector<Node> v;
    SegTree(int n_, vector<int>a_) {
        n = n_;
        a = a_;
        v.resize(4 * (n + 1));
    }
    void build(int l, int r, int i){
        if(l == r){
            v[i].pp = a[l];
            v[i].nn = -1 * a[l];
            v[i].pn = 0;
            v[i].np = 0;
            return ;
        }
        int mid = (l + r) >> 1;
        build(l, mid, 2 * i);
        build(mid + 1, r, 2 * i + 1);
        v[i] = merge(v[2 * i], v[2 * i + 1]);
    }   
    void update(int pos, int val, int l, int r, int i){
        if(l == r){
            v[i].pp = val;
            v[i].nn = -1 * val;
            v[i].pn = 0;
            v[i].np = 0;
            return ;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(pos, val, l, mid, 2 * i);
        else
            update(pos, val, mid + 1, r, 2 * i + 1);
        v[i] = merge(v[2 * i], v[2 * i + 1]);
    }
    int query(int i, int tl, int tr, int l, int r){
        if(l > r)
            return 0;
        if(l == tl and r == tr){
            return max(v[i].pp, v[i].pn);
        }
        int mid = (tl + tr) >> 1;
        return max(query(2 * i, tl, mid, l, min(r, mid)), query(2 * i + 1, mid + 1, tr, max(l, mid + 1), r));
    }   
};
