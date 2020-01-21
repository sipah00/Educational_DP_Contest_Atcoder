#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a;
vector<int> dp;

int main(){
    cin>>n>>k;
    a.resize(n); dp.resize(k+1);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    //dp[k] -> 1 means first player wins with k
    dp[0] = 0;
    for(int i = 1; i <= k; i++){
        dp[i] = 1;
        for(int j = 0; j < n; j++){
            if(a[j] <= i){
                dp[i] = min(dp[i], dp[i - a[j]]);
            }
        }
        dp[i] = !dp[i];
    }
    int res = dp[k];
    if(res){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }
    return 0;
}