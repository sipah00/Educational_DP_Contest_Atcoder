#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

ll n, k;

struct matrix{
    vector<vector<ll>> mt;
};

matrix operator* (const matrix& a, const matrix& b){
    matrix tmp;
    tmp.mt.resize(a.mt.size(), vector<ll>(b.mt[0].size()));
    for(int i = 0; i < (int) a.mt.size(); i++){
        for(int j = 0; j < (int) b.mt[0].size(); j++){
            tmp.mt[i][j] = 0;
            for(int kk = 0; kk < (int) b.mt.size(); kk++){
                tmp.mt[i][j] += ((a.mt[i][kk]%mod) * (b.mt[kk][j]%mod)) % mod;
            }
        }
    }
    return tmp;
}

matrix operator^ (matrix a, ll p){
    matrix tmp;
    tmp.mt.resize(a.mt.size(), vector<ll>(a.mt[0].size()));
    for(int i = 0; i < (int) a.mt.size(); i++) tmp.mt[i][i] = 1;
    while(p){
        if(p & 1){
            tmp = tmp * a;
        }
        a = a * a;
        p /= 2;
    }
    return tmp;
}

int main(){
    cin>>n>>k;
    matrix mat;
    mat.mt.resize(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>mat.mt[i][j];
        }
    }
    mat = mat ^ k;
    ll res = 0;
    for(auto x : mat.mt){
        for(auto y : x){
            res = (res + y) % mod;
        }
    }
    cout<<res<<endl;
    return 0;
}