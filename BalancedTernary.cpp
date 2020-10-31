#include <bits/stdc++.h>
using namespace std;
#define int long long int
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=200005;
#define M 1000000007
#define double long double
#define BINF 100000000000000
#define init(arr,cur) memset(arr,cur,sizeof(arr))
#define MAXN 17500001
#define deb(x) cout << #x << " " << x << "\n";
const int LG = 22;


int p[39];

void solve(){
    int n;
    //cin >> n;
    int off = 1e18;
    n = 1 + rand() % off;

    deb(n)
    int i = 0, s = 0;
    while(s + p[i] < n){
        s += p[i];
        i++;
    }

    //cout << i << ' ' << p[i] << endl;
    int cur = p[i];
    if(cur == n){
        deb(cur - n)
        return ;
    }

    int pre = s;
    for(int j = i - 1; j >= 0; j--){
        pre -= p[j];
        if(cur == n) break;
        if(cur > n){
            int l = cur - n;
            if(l > pre){
                cur -= p[j];
                //cout << j << ' ' << -p[j] << "\n";
            }
        }else{
            if(cur + pre < n){
                cur += p[j];
                //cout << j << ' ' << p[j] << "\n";
            }
        }
    }

    deb(cur - n);
}

 
#undef int 
int main() {
#define int long long int
ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("optput.txt", "w", stdout); 
#endif

    p[0] = 1;
    for(int i = 1; i < 39; i++)
        p[i] = 3 * p[i - 1];

    int t = 1000;
    while(t--){
        solve();
    }
    
    
    
    
return 0;  
} 


