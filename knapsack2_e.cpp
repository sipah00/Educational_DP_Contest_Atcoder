#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mxs = 1e18 + 10;


int N, W;
vector<int> w, v;

int main(){
    cin>>N>>W;
    w.resize(N), v.resize(N);
    for(int i = 0; i < N; i++){
        cin>>w[i]>>v[i];
    }
    int V = 0;
    for(auto x : v){
        V += x;
    }
    //dp[i] is min weight to get i value
    vector<ll> dp(V + 1);
    for(int i = 1; i < (int) dp.size(); i++) dp[i] = mxs;
    for(int i = 0; i < N; i++){
        vector<ll> ndp(V + 1);
        for(int j = 0; j <= V; j++){
            if(j >= v[i]){
                ndp[j] = min(dp[j], (ll) w[i] + dp[j - v[i]]);
            }else{
                ndp[j] = dp[j];
            }
        }
        dp = ndp;
    }
    int res = 0;
    for(int i = V; i >= 0; i--){
        if(dp[i] <= W){
            res = i;
            break;
        }
    }
    cout<<res<<endl;
    return 0;
}