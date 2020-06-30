#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

struct SuffixArray{
    string s;
    SuffixArray(string _s){
        s = _s;
    }

    void radix_sort(vector<pair<pair<int, int>, int>> &a){
        int n = a.size();
        vector<int>cnt(n, 0);
        for(auto x : a){
            cnt[x.F.S]++;
        }
        vector<pair<pair<int, int>, int>> a_new(n);
        vector<int>pos(n, 0);
        for(int i = 1; i < n; i++){
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for(auto x : a){
            int i = x.F.S;
            a_new[pos[i]] = x;
            pos[i]++;
        }

        a = a_new;

        cnt.clear();
        cnt.resize(n, 0);
        pos.clear();
        pos.resize(n, 0);
        a_new.clear();
        a_new.resize(n);

        for(auto x : a){
            cnt[x.F.F]++;
        }
        for(int i = 1; i < n; i++){
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for(auto x : a){
            int i = x.F.F;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }

    void solve(){

        s = s + "$";
        int n = s.length();
        vector<int>p(n), c(n);
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++)
            a[i] = {s[i] - 'a', i};
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++){
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(a[i].first == a[i - 1].first){
                c[p[i]] = c[p[i - 1]];
            }else{
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        int k = 0;
        while((1LL << k) < n){
            vector<pair<pair<int, int>, int>> v(n);
            for(int i = 0; i < n; i++){
                v[i] = make_pair(make_pair(c[i], c[(i + (1LL << k)) % n]), i);
            }
            radix_sort(v);
            for(int i = 0; i < n; i++){
                p[i] = v[i].S;
            }
            c[p[0]] = 0;
            for(int i = 1; i < n; i++){
                if(v[i].F == v[i - 1].F){
                    c[p[i]] = c[p[i - 1]];
                }else{
                    c[p[i]] = c[p[i - 1]] + 1;
                }
            }
            k++;
        }
        for(int i = 0; i < n; i++){
            cout << p[i] << " " << s.substr(p[i], n - p[i]) << "\n";
        }
    }

};



//string s;
//cin >> s;
//SuffixArray deep(s);
//deep.solve();

