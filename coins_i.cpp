#include <bits/stdc++.h>

using namespace std;

int n;
vector<double> p;
vector<vector<double>> dp;

int main(){
    cin>>n;
    p.resize(n + 1);
    dp.resize(n + 1, vector<double>(n + 1));
    for(int i = 1; i <= n; i++){
        cin>>p[i];
    }
    vector<double> pp(n + 1);
    pp[0] = 1.0;
    for(int i = 1; i <= n; i++){
        pp[i] = pp[i-1] * (1 - p[i]);
    }
    dp[0][0] = 1.0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){
                dp[i][0] = pp[i];
            }else{
                dp[i][j] = p[i] * dp[i-1][j-1] + (1 - p[i]) * dp[i-1][j];
            }
        }
    }
    auto res = 0.0;
    for(int i = n/2 + 1; i <= n; i++){
        res += dp[n][i];
    }
    cout<<setprecision(15)<<endl;
    cout<<res<<endl;
    return 0;
}