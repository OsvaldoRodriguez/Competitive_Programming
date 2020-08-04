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
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int occ[500];
int main(){
    fast;
    string s,t;
    cin >> s >> t;
    fore(i,0,sz(t))
        occ[t[i]]++;
    int a = 0,b = 0;
    fore(i,0,sz(s)){
        if(s[i] == '#')
            continue;
            if(occ[s[i]]){
                a++;
                occ[s[i]]--;
                s[i] = '#';
            }
    }
    fore(i,0,sz(s)){
        if(s[i] == '#')
            continue;
        if('a' <= s[i] && s[i] <= 'z'){
            if(occ[s[i] - 32]){
                b++;
                occ[s[i] - 32]--;
                s[i] = '#';
            }
        }else if(occ[s[i] + 32]){
            b++;
            occ[s[i] + 32]--;
            s[i] = '#';
        }
    }
    cout << a << " " << b << '\n';
    return 0;
}
