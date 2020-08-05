#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 3 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    fast;
    string s;
    cin >> s;
    vector<int> v(sz(s)),acc(sz(s));
    v[0] = 0;
    fore(i,1,sz(v))
        v[i] = (s[i] == s[i - 1]);
    acc[0] = v[0];
    fore(i,1,sz(v))
        acc[i] = acc[i - 1] + v[i];
    int q,l,r;
    cin >> q;
    while(q--){
        cin >> l >> r;
        l--;r--;
        cout << acc[r] - acc[l] << '\n';
    }
    return 0;
}   
