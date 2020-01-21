#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int n;
vector<vector<ll>> a, dp;

int main(){
    cin>>n;
    a.resize(n+1, vector<ll>(n+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>a[i][j];
        }
    }
    dp.resize(n+1, vector<ll>(1 << n));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int mask = 0; mask <= (1 << n) - 1; mask++){
            if(__builtin_popcount(mask) != i) continue; // number of boys == number of girls
            for(int j = 0; j < n; j++){
                if((mask & (1 << j)) && a[i][j + 1]){
                    dp[i][mask] = (dp[i][mask] + dp[i-1][mask ^ (1 << j)]) % mod;
                }
            }
        }
    }
    ll res = dp[n][(1 << n) - 1];
    cout<<res<<endl;
    return 0;
}