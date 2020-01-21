#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, w;
vector<ll> weight, value;
vector<vector<ll>> dp;



ll solve(int i, int cap){
  if(i == n) return 0;
  if(dp[i][cap] != -1) return dp[i][cap];
  ll v = -1;
  if(cap >= weight[i]){
    v = max(solve(i+1, cap), value[i] + solve(i+1, cap-weight[i]));
  }else{
    v = solve(i+1, cap);
  }
  return dp[i][cap] = v;
}


int main() {
  int tmp, tmp1;
  cin>>n>>w;
  for(int i = 0; i < n; i++){
    cin>>tmp>>tmp1;
    weight.push_back(tmp);
    value.push_back(tmp1);
  }
  dp.assign(n+1, vector<ll>(w+1, -1));
//   ll res = solve(0, w);
  ll res;
//   for(int i = 0; i <= w; i++) dp[0][i] = 0;
//   for(int i = 1; i <= n; i++){
//       for(int j = 0; j <= w; j++){
//           if(weight[i-1] <= j){
//               dp[i][j] = max(dp[i-1][j], value[i-1] + dp[i-1][j-weight[i-1]]);
//           }else{
//               dp[i][j] = dp[i-1][j];
//           }
//       }
//   }
//   res = dp[n][w];
  vector<ll> dpone(w+1, 0);
  for(int i = 1; i <= n; i++){
      auto ndp = dpone;
      for(int j = 0; j <= w; j++){
          if(weight[i-1] <= j){
              ndp[j] = max(dpone[j], value[i-1] + dpone[j-weight[i-1]]);
          }else{
              ndp[j] = dpone[j];
          }
      }
      dpone = ndp;
  }
  res = dpone[w];
  cout<<res<<endl;
  return 0;
}