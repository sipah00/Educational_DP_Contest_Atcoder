#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> cnt(4);
vector<vector<vector<double>>> dp;

int main(){
    cin>>n;
    dp.resize(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1)));
    for(int i = 0; i < n; i++){
        int tmp; cin>>tmp;
        cnt[tmp]++;
    }
    dp[0][0][0] = 0.0;
    for(int k = 0; k <= n; k++){
        for(int j = 0; j <= n; j++){
            for(int i = 0; i <= n; i++){
                double kk = i + j + k;
                if(kk == 0 || n < kk) continue;
                dp[i][j][k] = (n/kk) + (1/kk) * ((i ? i*dp[i-1][j][k] : 0) + (j ? j*dp[i+1][j-1][k] : 0) + (k ? k*dp[i][j+1][k-1] : 0));
            }
        }
    }
    auto res = dp[cnt[1]][cnt[2]][cnt[3]];
    cout<<setprecision(20)<<res<<endl;
    return 0;
}