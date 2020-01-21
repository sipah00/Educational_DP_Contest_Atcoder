#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a, b, c;

int main(){
    cin>>n;
    a.resize(n), b.resize(n), c.resize(n);
    for(int i = 0; i < n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    vector<int> dp(3);
    dp[0] = a[0], dp[1] = b[0], dp[2] = c[0];
    for(int i = 1; i < n; i++){
        vector<int> ndp(3);
        ndp[0] = a[i] + max(dp[1], dp[2]);
        ndp[1] = b[i] + max(dp[0], dp[2]);
        ndp[2] = c[i] + max(dp[0], dp[1]);
        dp = ndp;
    }
    int res = *max_element(dp.begin(), dp.end());
    cout<<res<<endl;
    return 0;
}