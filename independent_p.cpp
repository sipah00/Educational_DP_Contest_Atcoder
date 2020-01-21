#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;


int n;
vector<vector<ll>> edges, dp;

ll add(ll a, ll b){
    return (a + b) % mod;
}

ll mul(ll a, ll b){
    return (a * b) % mod;
}

void dfs(int u, int p){
    ll r1 = 1, r2 = 1;
    for(auto v : edges[u]){
        if(v == p) continue;
        dfs(v, u);
        r1 = mul(r1, add(dp[v][0], dp[v][1]));
        r2 = mul(r2, dp[v][1]);
    }
    dp[u][1] = r1, dp[u][0] = r2;
}

int main(){
    cin>>n;
    edges.resize(n+1);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin>>u>>v;
        edges[u-1].push_back(v-1);
        edges[v-1].push_back(u-1);
    }
    dp.resize(n, vector<ll>(2));
    dfs(0, -1);
    ll res = add(dp[0][0], dp[0][1]);
    cout<<res<<endl;
    return 0;
}