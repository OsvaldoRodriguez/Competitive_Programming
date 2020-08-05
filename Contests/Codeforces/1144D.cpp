#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
#define w(t) while(t--)
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
int pre[N];
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int n;
    cin >> n;
    int v[n + 5];
    vector<pair<int, ii> > aux;
    fore(i, 1, n + 1){
        cin >> v[i];
        pre[v[i]]++;
    }
    int mx = 0;
    int val = 0;
    fore(i, 0, N){
        if(mx < pre[i]){
            mx = pre[i];
            val = i;
        }
    }
    fore(i, 1, n + 1){
        if(v[i] == val){
            // rigth
            int j = i + 1;
            while(j <= n && v[j] != val){
                if(v[j] < v[j - 1]){
                    aux.pb({1, {j, j - 1}});
                    v[j] += abs(v[j] - v[j - 1]);
                }else if(v[j] > v[j - 1]){
                    aux.pb({2, {j, j - 1}});
                    v[j] -= abs(v[j] - v[j - 1]);
                }
                j++;
            }
            j = i - 1;
            while(j >= 1 && v[j] != val){
                if(v[j] < v[j + 1]){
                    aux.pb({1, {j, j + 1}});
                    v[j] += abs(v[j] - v[j + 1]);
                }else if(v[j] > v[j + 1]){
                    aux.pb({2, {j, j + 1}});
                    v[j] -= abs(v[j] - v[j + 1]);
                }
                j--;
            }
        }

    }
    cout << sz(aux) << '\n';
    for(auto i : aux)
        cout << i.F << " " << i.S.F << " " << i.S.S << '\n';
    return 0;
}   
