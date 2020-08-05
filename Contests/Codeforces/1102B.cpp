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
int occ[5050];
int color[5050];
int main(){
    fast;
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    fore(i,0,n){
        cin >> v[i];
        occ[v[i]]++;
    }
    fore(i,0,5050){
        if(occ[i] > k or k > n){
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";
    vector<ii> aux;
    fore(i,0,n){
        aux.pb({v[i],i});
    }
    sort(all(aux));
    int col = 0;
    fore(i,0,sz(aux)){

        int c = col++ % (k);
        color[aux[i].S] = c;
    }

    fore(i,0,sz(aux))
        cout << color[i] + 1 << ' ';
        cout << '\n';
	return 0;
}
