#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<ll> dp;
vector<vector<ll>> a;

int main(){
    cin>>n;
    a.resize(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }
    dp.resize(1 << n);
    for(int mask = 0; mask < (1 << n); mask++){
        for(int i = 0; i < n; i++){
            if((1 << i) & mask){
                for(int j = i + 1; j < n; j++){
                    if((1 << j) & mask){
                        dp[mask] += a[i][j];
                    }
                }
            }
        }
    }
    for(int mask = 0; mask < (1 << n); mask++){
        for(int submask = mask; submask > 0; submask = (submask - 1) & mask){
            dp[mask] = max(dp[mask], dp[submask] + dp[submask ^ mask]);
        }
    }
    ll res = dp[(1 << n) - 1];
    cout<<res<<endl;
    return 0;
}