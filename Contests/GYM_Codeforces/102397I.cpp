#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
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
const int mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int v[5];
int main(){
    fast;
    int n;
    string s;
    cin >> n >> s;
    fore(i,0,n)
        v[s[i] - 'a']++;
    int mx = 0;
    int mn = (1 << 30);
    fore(i,0,5){
        mx = max(mx,v[i]);
        mn = min(mn,v[i]);
    }
    cout << mn << ' ' << mx << '\n';
    return 0;
}
