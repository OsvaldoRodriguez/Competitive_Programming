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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int n, k;
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    fast;
    int a = 0,b = (1 << 10) - 1;
    int n;
    cin >> n;
    char x;
    int u;
    while(n--){
        cin >> x >> u;
        if(x == '&')
            a &= u, b &= u;
        if(x == '|')
            a |= u, b |= u;
        if(x == '^')
            a ^= u, b ^= u;
    }
    //hol
    int aux = b ^ 1023;
    cout << "2\n| " << (a ^ aux) << "\n^ " << aux << '\n';
    return 0;   
}
