#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mx = LLONG_MAX;

int n, k;
vector<ll> h, dp;

int main(){
    cin>>n>>k;
    h.resize(n); dp.resize(n, mx);
    for(int i = 0; i < n; i++){
        cin>>h[i];
    }
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        for(int j = i - 1; j >= i - k && j >= 0; j--){
            dp[i] = min(dp[i], dp[j] + abs(h[j] - h[i]));
        }
    }
    ll res = dp[n-1];
    cout<<res<<endl;
    return 0;
}