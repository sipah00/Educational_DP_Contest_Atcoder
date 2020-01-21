#include <bits/stdc++.h>

using namespace std;

int m, n;
string s, t, res = "";

void printpath(vector<vector<pair<int, int>>>& p, pair<int, int> x){
    if(x.first == 0 || x.second == 0) return;
    auto xx = p[x.first][x.second];
    auto d = x.first + x.second - (xx.first + xx.second);
    if(d == 2){
        res += s[x.first - 1];
    }
    printpath(p, xx);
    return;
}

int main(){
    cin>>s>>t;
    m = s.length(), n = t.length();
    vector<vector<int>> dp(s.length()+ 1, vector<int>(t.length() + 1));
    vector<vector<pair<int, int>>> p(m + 1, vector<pair<int, int>>(n + 1));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;                
                p[i][j] = {i-1, j-1};
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                p[i][j] = dp[i][j] == dp[i][j-1] ? make_pair(i, j-1) : make_pair(i-1, j);
            }
        }
    }
    printpath(p, {m, n});
    reverse(res.begin(), res.end());
    cout<<res<<endl;
    return 0;
}