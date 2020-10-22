#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
#define F           first
#define S           second
#define pb          push_back
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a)   for(int i = a; i >= 0; i--)
#define fori(i,m)   for(auto i = m.begin(); i != m.end(); i++) 
#define w(t)        while(t--)
#define sz(s)       int(s.size())
#define cls(a,car)  memset(a,car,sizeof (a))
#define db(x)       cerr << #x << " is " << x << '\n'
#define FI          freopen("input.txt", "r", stdin)
#define FO          freopen("output.txt", "w", stdout)
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e2 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int INF = 1e2;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
//105470163083
//100000000223257 primos
//1000000000318157
void solve(){
    string title, nomfile;
    getline(cin, title);
    getline(cin, nomfile);
    vector<string> judge, me;
    int ret, timelimit, limit;
    cin >> ret >> timelimit >> limit;
    int t;
    cin >> t;
    string cur;
    cin.ignore();
    fore(i, 0, t){
        getline(cin, cur);
        judge.pb(cur);
    }
    cin >> t;
    cin.ignore();
    fore(i, 0, t){
        getline(cin, cur);
        me.pb(cur);
    }
    bool CE = 0;
    int i = 0;
    string _aux = "";
    while(i < sz(nomfile) && nomfile[i] != '.')
        _aux += nomfile[i++];
    string aux = "";
    while(i < sz(nomfile))
        aux += nomfile[i++];
    if((aux == ".c" or aux == ".cpp" or aux == ".java" or aux == ".py") and _aux == title)
        CE = 1;
    if(!CE)
        cout << "Compile Error\n";
    else{
        if(ret != 0)
            cout << "Run-Time Error\n";
        else{
            if(limit > timelimit)
                cout << "Time Limit Exceeded\n";
            else{
                bool AC = 1;
                if(sz(judge) == sz(me))
                    for(int i = 0; i < sz(judge); i++){
                        AC &= (judge[i] == me[i]);
                    }
                else
                    AC = 0;

                if(AC)
                    cout << "Correct\n";
                else
                    cout << "Wrong Answer\n";
            }
        }
    }
}
int main(){
    FIN;
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    //EjecuteTime;
    return 0;

}