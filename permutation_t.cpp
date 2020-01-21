#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int n;
string s;

vector<ll> dp, csum;

ll sum(int a, int b){
    if(a == 0) return csum[b];
    return (csum[b] - csum[a-1] + mod) % mod;
}

int main(){
    cin>>n>>s;
    dp.resize(n+1); csum.resize(n+1);
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        vector<ll> ndp(n+1);
        csum[1] = dp[1];
        for(int u = 2; u <= n; u++){
            csum[u] = (csum[u-1] + dp[u]) % mod;
        }
        for(int l = 1; l <= i; l++){
            if(s[i-2] == '<'){
                // for(int k = 1; k < l; k++){
                    // ndp[l] = (ndp[l] + dp[k]) % mod;
                    ndp[l] = sum(1, l-1);
                // }
            }else{
                // for(int k = l; k <= i-1; k++){
                    // ndp[l] = (ndp[l] + dp[k]) % mod;
                    ndp[l] = sum(l, i-1);
                // }
            }
        }
        dp = ndp;
    }
    ll res = 0;
    for(auto x : dp){
        res = (res + x) % mod;
    }
    cout<<res<<endl;
    return 0;
}