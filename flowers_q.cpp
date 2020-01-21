#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, sl;
vector<ll> h, b, dp;
vector<ll> segt;

ll query(int l, int r){
    l += sl, r += sl;
    ll res = -1;
    for(; l < r; l /= 2, r /= 2){
        if(l & 1) res = max(res, segt[l++]);
        if(r & 1) res = max(res, segt[--r]);
    }
    return res;
}

void modify(int idx, ll x){
    idx += sl;
    segt[idx] = x;
    for(int p = idx; p > 1; p /= 2){
        segt[p/2] = max(segt[p], segt[p ^ 1]);
    }
}


int main(){
    cin>>n;
    h.resize(n), b.resize(n);
    for(int i = 0; i < n; i++){
        cin>>h[i];
    }
    for(int i = 0; i < n; i++){
        cin>>b[i];
    }
    // this is N^2 so TLE but correct solution
    // dp.resize(n);
    // dp[0] = b[0];
    // for(int i = 1; i < n; i++){
    //     dp[i] = 0;
    //     for(int j = 0; j < i; j++){
    //         if(h[j] < h[i]){
    //             dp[i] = max(dp[i], dp[j]);
    //         }
    //     }
    //     dp[i] += b[i];
    // }
    // ll res = *max_element(dp.begin(), dp.end());
    auto mxh = *max_element(h.begin(), h.end());
    sl = mxh + 1;
    segt.resize(2 * sl);
    for(int i = 0; i < n; i++){
        ll ph = query(0, h[i]);
        modify(h[i], ph + b[i]);
    }
    ll res = segt[1];
    cout<<res<<endl;
    return 0;
}