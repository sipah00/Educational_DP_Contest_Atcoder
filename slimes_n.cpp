#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<ll> a, csum;
vector<vector<ll>> dp;

ll sum(int l, int r){
    if(l == 0) return csum[r];
    return csum[r] - csum[l-1];
}

// ll solve(int l, int r){
//     if(l >= r) return 0;
//     ll res = LLONG_MAX;
//     for(int k = l; k < r; k++){
//         res = min(res, solve(l, k) + solve(k+1, r) + sum(l, r));
//     }
//     return res;
// }

int main(){
    cin>>n;
    a.resize(n); csum.resize(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    csum[0] = a[0];
    for(int i = 1; i < n; i++){
        csum[i] = csum[i-1] + a[i];
    }
    // ll res = solve(0, n-1);
    dp.resize(n, vector<ll>(n));
    for(int l = n - 1; l >= 0; l--){
        for(int r = l + 1; r < n; r++){
            dp[l][r] = LLONG_MAX;
            for(int k = l; k < r; k++){
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + sum(l, r));
            }

        }
    }
    ll res = dp[0][n-1];
    cout<<res<<endl;
    return 0;
}