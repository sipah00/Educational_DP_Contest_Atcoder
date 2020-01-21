#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int n, k;
vector<ll> a;
vector<ll> dp;

int main(){
    cin>>n>>k;
    a.resize(n+1); dp.resize(k+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        vector<ll> csum(k+1);
        csum[0] = dp[0];
        for(int u = 1; u <= k; u++){
            csum[u] = (dp[u] + csum[u-1]) % mod;
        }
        for(int j = 0; j <= k; j++){
            // j - a[i] to j
            if(j - a[i] > 0){
                dp[j] = (mod + csum[j] - csum[j-a[i]-1]) % mod;
            }else{
                dp[j] = csum[j] % mod;
            }
        }
    }
    ll res = dp[k];
    cout<<res<<endl;
    return 0;
}