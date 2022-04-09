#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
const ll mod = 1e9 + 7;

struct Hash{
    //primos 1001265673, 1001864327, 999727999, 1070777777, 1000003967
    // 33, 331, 997
    ll B, MOD;
    int N_MAX;
    vector<ll> h1, h2, BASE;
    Hash(int N, ll Base, ll mod){
        B = Base;
        MOD = mod;
        N_MAX = N;
        h1.resize(N_MAX);
        h2.resize(N_MAX);
        BASE.resize(N_MAX);
        BASE[0] = 1;
        for(int i = 1; i < N_MAX; i++)
            BASE[i] = mul(BASE[i - 1], B);
    }

    void build(const vector<int> &v){
        ll hash = 0;
        for(int i = 0; i < N_MAX; i++){
            hash = add(mul(hash, B), v[i]);
            h1[i] = hash;
        }
        hash = 0;
        for(int i = N_MAX - 1; i >= 0; i--){
            hash = add(mul(hash, B), v[i]);
            h2[i] = hash;
        }   
    }
    ll getLR(int l, int r){
        if(l == 0)
            return h1[r];
        return sub(h1[r], mul(h1[l - 1], BASE[r - l + 1]));
    }

    ll getRL(int l, int r){
        if(r == N_MAX - 1)
            return h2[l];
        return sub(h2[l], mul(h2[r + 1], BASE[r - l + 1]));
    }

    ll add(ll a, ll b){return a + b > MOD ? a + b - MOD : a + b;}
    ll sub(ll a, ll b){return a - b < 0 ? a - b + MOD : a - b;}
    ll mul(ll a, ll b){return a * b > MOD ? a * b % MOD : a * b;}
};


int main(){
        
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    bool flag = 1;
    while(getline(cin, str)){
        if(str == "")
            break;
        Hash H((int) str.size(), 331, 1e9 + 7);
        vector<int> v;
        for(char i : str){
            if(i != ' ')
                v.push_back(i);
        }
        H.build(v);
        int n = (int) str.size();
        vector<unordered_map<int, int>> ans(n + 1);
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int len = j - i + 1;
                int hash = H.getLR(i, j);
                ans[len][hash]++;
            }
        }
        int cnt = 0;
        for(int i = 1; i < ans.size(); i++){
            int mx = 0;
            for(auto j : ans[i]){
                mx = max(mx, j.second);
            }
            if(mx == 1)
                break;
            cout << mx << '\n';
        }
        cout << "\n";   
        

    }

    
    return 0;
}
