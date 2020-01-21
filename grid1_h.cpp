#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int h, w;
vector<vector<int>> arr, dp;

int main(){
    cin>>h>>w;
    arr.resize(h+1, vector<int>(w+1)), dp.resize(h+1, vector<int>(w+1));
    dp[1][1] = 1;
    string tmp;
    for(int i = 1; i <= h; i++){
        cin>>tmp;
        for(int j = 0; j < w; j++){
            if(tmp[j] == '.'){
                arr[i][j+1] = 0;
            }else{
                arr[i][j+1] = 1;
            }
        }
    }
    // for(int i = 1; i <= h; i++){
    //     for(int j = 1; j <= w; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(arr[i][j] || (i == 1 && j == 1)) continue;
            dp[i][j] = ( (ll) dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }
    int res = dp[h][w];
    cout<<res<<endl;
    return 0;
}