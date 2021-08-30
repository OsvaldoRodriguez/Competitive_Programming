#include <bits/stdc++.h>
#define ii              pair<int,int>
#define F               first
#define S               second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define rall(x)         (x).rbegin(),(x).rend()
#define fore(i, a, b)   for(int i = a; i < b; i += 1)
#define forr(i, a)      for(int i = a; i >= 0; i--)
#define sz(s)           int(s.size())
#define cls(a, car)     memset(a,car,sizeof (a))
#define db(x)           cout << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
void debug(){cout << endl;}
template<typename T, typename... Args>
void debug(T a, Args... args){cout << a << " "; debug(args...);}
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e2 + 15;
const ll mod = INT_MAX;
const double E = 1e-7;
char A[60][60];
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    int mn = 100;
    for(int i = 0; i < n; i++){
        int cur = 0;
        int rzero = 0;
        int rpoint = 0;
        int czero = 0;
        int cpoint = 0;
        for(int j = 0; j < n; j++){
            rzero += (A[i][j] == 'O');
            rpoint += (A[i][j] == '.');
            czero += (A[j][i] == 'O');
            cpoint += (A[j][i] == '.');

        }
        if(rzero == 0)
            mn = min(mn, rpoint);
        if(czero == 0)
            mn = min(mn, cpoint);

    }

    set<vector<ii>> s;
    for(int i = 0; i < n; i++){
        int cur = 0;
        int rzero = 0;
        int rpoint = 0;
        int czero = 0;
        int cpoint = 0;
        for(int j = 0; j < n; j++){
            rzero += (A[i][j] == 'O');
            rpoint += (A[i][j] == '.');
            czero += (A[j][i] == 'O');
            cpoint += (A[j][i] == '.');

        }


        vector<ii> aux;
        if(rzero == 0 and rpoint == mn){
            for(int j = 0; j < n; j++)
                if(A[i][j] == '.')
                    aux.pb({i, j});
            
        }

        if(aux.size())
            s.insert(aux);


        vector<ii> aux1;
        if(czero == 0 and cpoint == mn){
            for(int j = 0; j < n; j++)
                if(A[j][i] == '.')
                    aux1.pb({j, i});
            
        }
        if(aux1.size())
            s.insert(aux1);

    }

    // for(auto u : s){
    //     auto aux = u;
    //     for(auto j : aux)
    //         cout << "(" << j.F << " " << j.S << "), ";
    //     cout << endl;
    // }

    if(mn == 100)
        cout << "Impossible\n";
    else
        cout << mn << ' ' << s.size() << "\n";
}
int main(){
    #ifdef FURY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){ 
        cout << "Case #" << i << ": "; 
        solve();
    }

    #ifdef FURY
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
