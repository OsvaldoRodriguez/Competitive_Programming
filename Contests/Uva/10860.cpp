#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 100;
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

vector<pair<string, ll>> tmp, _tmp;
int n, q;
int dp[N];
int f(int i, Hash &h){
    if(i == n){
        return 0;
    }
    int &ans = dp[i];
    if(ans == -1){
        ans = 1e7;
        for(int j = 0; j < q; j++){
            int cur = i + (tmp[j].first).size() - 1;
            if(cur < n){
                if(h.getLR(i, cur) == tmp[j].second)
                    ans = min(ans, f(i + (tmp[j].first).size(), h) + 1);
            }
            int _cur = i + (_tmp[j].first).size() - 1;
            if(_cur < n){
                if(h.getLR(i, _cur) == _tmp[j].second)
                    ans = min(ans, f(i + (_tmp[j].first).size(), h) + 1);
            }
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    string s;
    cin >> t;

    for(int yy = 1; yy <= t; yy++){
        cin >> s >> q;
        n = s.size();
        for(int i = 0; i < n + 1; i++)
            dp[i] = -1;
        vector<int> cur;
        for(char c : s)
            cur.push_back(c);
        Hash H(cur.size(), 331, 1e9 + 7);

        H.build(cur);

        
        tmp.clear();
        _tmp.clear();
        for(int xx = 0; xx < q; xx++){
            cin >> s;
            string _s = s;
            reverse(_s.begin(), _s.end());
            Hash H1(s.size(), 331, 1e9 + 7);
            cur.clear();
            for(char c : s)
                cur.push_back(c);
            H1.build(cur);
            tmp.push_back({s, H1.getLR(0, s.size() - 1)});
            cur.clear();
            for(char c : _s)
                cur.push_back(c);

            H1.build(cur);
            _tmp.push_back({_s, H1.getLR(0, s.size() - 1)});
        }
        
        int ans = f(0, H);
        cout << "Set " << yy << ": ";
        if(ans == 1e7)
            cout << "Not possible.\n";
        else
            cout << ans << ".\n";

    }
    return 0;
}
