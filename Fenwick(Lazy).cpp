//0 based indexing
//range update - range query
 
//Tree deep(n);
//deep.upd(l,r,v); //[l,r] += v
//deep.get(l,r); //sum [l,r]
 
 
struct BIT {
  vector<int> f;
 
  BIT(int n = 0) {
    f.assign(n, 0);
  }
 
  int get(int at) {
    int res = 0;
    for (; at >= 0; at = (at & (at + 1)) - 1)
      res += f[at];
    return res;
  }
 
  void upd(int at, int delta) {
    for (; at < f.size(); at = (at | (at + 1)))
      f[at] += delta;
  }
};
 
struct Tree {
  BIT f1;
  BIT f2;
 
  Tree(int n = 0): f1(n + 1), f2(n + 1) {}
 
  void upd(int low, int high, int delta) {
    f1.upd(low, delta);
    f1.upd(high + 1, -delta);
    f2.upd(low, delta * (low - 1));
    f2.upd(high + 1, -delta * high);
  }
 
  int get(int pos) {
    return f1.get(pos) * pos - f2.get(pos);
  }
 
  int get(int low, int high) {
    return get(high) - (low == 0 ? 0 : get(low - 1));
  }
};
 
