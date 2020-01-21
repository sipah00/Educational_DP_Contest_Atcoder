#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int n, d;
string st;

vector<vector<ll>> dp;

ll add(ll a, ll b){
    return (a + b) % mod;
}

ll mul(ll a, ll b){
    return ((a%mod) * (b%mod)) % mod; 
}

int main(){
    cin>>st>>d;
    n = st.length();
    dp.resize(d, vector<ll>(2));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        vector<vector<ll>> ndp(d, vector<ll>(2));
        for(int s = 0; s < d; s++){
            for(int j = 0; j < 10; j++){
                // any < border
                ndp[(s + j)%d][1] = add(ndp[(s + j)%d][1], dp[s][1]);
            }
            for(int j = 0; j <= (int) (st[i] - '0'); j++){
                if(j < (int) (st[i] - '0')){
                    ndp[(s + j)%d][1] = add(ndp[(s + j)%d][1], dp[s][0]);
                }else{
                    ndp[(s + j)%d][0] = add(ndp[(s + j)%d][0], dp[s][0]);
                }
            }
        }
        dp = ndp;
    }
    ll res = (dp[0][0] + dp[0][1] - 1 + mod) % mod;
    cout<<res<<endl;
    return 0;
}