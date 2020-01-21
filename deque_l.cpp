#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<ll> a;
vector<vector<ll>> dp;

int main(){
    cin>>n;
    a.resize(n);
    dp.resize(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int j = 0; j < n; j++){
        for(int i = j; i >= 0; i--){
            if(i == j){
                dp[i][i] = a[i];
            }else{
                dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
            }
        }
    }
    ll res = dp[0][n-1];
    cout<<res<<endl;
    return 0;
}