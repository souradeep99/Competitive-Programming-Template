/*
https://codedrills.io/contests/amrita-icpc-practice-session-3/problems/unique-strings

Given a string of lowercase english characters of length N. Find the number of unique 
strings of all possible length that can be formed by using the characters from the given string. 
Two strings are different when they differ in length or at some position the characters are 
different. Compute the answer modulo 10^9 + 7.

1 <= N <= 5000

Sample Input 0
aab
Sample Output 0
8

Sample Input 1
abc
Sample Output 1
15

Explanation
In first case, there are 8 possible strings - "a", "b", "ab", "ba", "aa", "aab", "aba", "baa".
In second case, there are 15 possible strings - "a", "b", "c", "ab", "ac", "ba", "bc", "ca", "cb", "abc", "acb", "bac", "bca", "cab", "cba".
*/


//My Time Complexity: O(N * N)
//My Space Complexity: O(N)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
#define int long long int
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=5005;
#define M 1000000007
#define double long double
#define BINF 1e9
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 17500001
#define deb(xx) cout << #xx << " " << xx << "\n";
const int LG = 22;


int power(int x,int y,int m){
    if (y == 0)
        return 1;
    int res = 1;
    while(y){
        if(y & 1) res = (res * x) % M;
        y /= 2;
        x = (x * x) % M;
    }
    return res;
}

int fact[N], ifact[N];

void process(){
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % M;
    for(int i = 0; i < N; i++)
        ifact[i] = power(fact[i], M - 2, M);
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

    process();

    string s;
    cin >> s;
    vector<int>f(26, 0);
    int n = s.length();
    for(auto i : s){
        f[i - 'a']++;
    }

    vector<int>dp(n + 1);
    dp[0] = 1;
    for(int i = 0; i < 26; i++){
        vector<int>new_dp(n + 1, 0);
        new_dp = dp;
        for(int j = 1; j <= f[i]; j++){
            for(int k = 1; k <= n; k++){
                if(k - j >= 0){
                    int x = dp[k - j] * ifact[k - j];
                    x %= M;
                    int y = (x * fact[k]) % M;
                    y = (y * ifact[j]) % M;
                    new_dp[k] += y;
                    new_dp[k] %= M;
                }
            }   
        }
        swap(dp, new_dp);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += dp[i];
        ans %= M;
    }

    cout << ans << endl;


return 0;  
}


