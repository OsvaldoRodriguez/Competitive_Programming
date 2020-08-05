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
//freopen("","r",stdin);
//freopen("","w",stdout);
bool isUpper(char x){
    return 'A' <= x && x <= 'Z';
}
int main(){
    string s;
    cin >> s;
    int n = sz(s);
    vector<int> upper(n),lower(n);
    upper[n - 1] = isUpper(s[n - 1]);
    lower[0] = ! isUpper(s[0]);
    fore(i,1,n)
        lower[i] = lower[i - 1] + !isUpper(s[i]);
    for(int i = n - 2; i >= 0; i--)
        upper[i] = upper[i + 1] + isUpper(s[i]);
    int mn = n;
    fore(i,0,n)
        mn = min(mn,upper[i] - isUpper(s[i]) + lower[i] -  ! isUpper(s[i]));
    cout << mn << '\n';
    return 0;

}
