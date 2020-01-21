#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mx = LLONG_MAX;

int n;
vector<ll> h, dp;

int main(){
    cin>>n;
    h.resize(n); dp.resize(n);
    for(int i = 0; i < n; i++){
        cin>>h[i];
    }
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for(int i = 2; i < n; i++){
        dp[i] = min(dp[i-1] + abs(h[i-1] - h[i]), dp[i-2] + abs(h[i-2] - h[i]));
    }
    ll res = dp[n-1];
    cout<<res<<endl;
    return 0;
}