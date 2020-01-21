#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> edges;
vector<int> dp;

int dfs(int u){
    if(dp[u] != -1) return dp[u];
    int res = 0;
    for(auto v : edges[u]){
        res = max(res,  1 + dfs(v));
    }
    return dp[u] = res;
}

int main(){
    cin>>n>>m;
    edges.resize(n + 2);
    dp.resize(n+1, -1);
    for(int i = 0; i < m; i++){
        int x, y;
        cin>>x>>y;
        edges[x-1].push_back(y-1);
    }
    for(int i = 0; i < n; i++){
        edges[n].push_back(i);
    }
    int res = dfs(n) - 1;
    cout<<res<<endl;
    return 0;
}