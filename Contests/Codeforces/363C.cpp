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
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
vi aux;
vector<char> car;
int dp[N][2];
vi idx;
int f(int i, bool flag){
    if(i == sz(aux))
        return 0;
    int &ans = dp[i][flag];
    if(ans == -1){
        ans = 1e9;
        if(i == 0){
            ans = min(ans, f(i + 1, 1) + aux[i] - 1);
            if(aux[i] > 1)
                ans = min(ans, f(i + 1, 0) + aux[i] - 2);
        }
        if(flag){
            ans = min(ans, f(i + 1, 1) + aux[i] - 1);
            if(aux[i] > 1)
                ans = min(ans, f(i + 1, 0) + aux[i] - 2);
        }else
            ans = min(ans, f(i + 1, 1) + aux[i] - 1);
    }
    return ans;
}

void g(int pos, int lim){
    idx.pb(lim);
}
void r(int i, bool flag){
    if(i == sz(aux))
        return ;
    int ans = f(i, flag);
    if(i == 0){
        if(ans == f(i + 1, 1) + aux[i] - 1){
            g(i, aux[i] - 1);
            r(i + 1, 1);
            return ;
        }
        if(aux[i] > 1 && ans == f(i + 1, 0) + aux[i] - 2){
            g(i, aux[i] - 2);
            r(i + 1, 0);
            return ;
        }
    }
    if(flag){
        if(ans == f(i + 1, 1) + aux[i] - 1){
            g(i, aux[i] - 1);
            r(i + 1, 1);
            return ;
        }
        if(aux[i] > 1 && ans == f(i + 1, 0) + aux[i] - 2){
            g(i, aux[i] - 2);
            r(i + 1, 0);
            return;
        }
    }else{
        if(ans == f(i + 1, 1) + aux[i] - 1){
            g(i, aux[i] - 1);
            r(i + 1, 1);
            return ;
        }
    }
}



void solve(){
    string str;
    cin >> str;
    char last = str[0];
    int cnt = 0;
    bool flag = 1;
    for(int i = 0; i < sz(str); i++){
        if(last != str[i]){
            aux.pb(cnt);
            car.pb(last);
            cnt = 1;
            last = str[i];
        }
        else cnt++;
    }
    if(cnt){
        aux.pb(cnt);
        car.pb(last);
    }
    cls(dp, -1);
    
    r(0, (aux[0] == 1));
    int i = 0;
    for(int i = 0; i < sz(aux); i++){
        for(int j = 0; j < aux[i] - idx[i]; j++)
            cout << car[i];
    }
    cout << '\n';
    
}
int main(){
    FIN;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    EjecuteTime;
    return 0;
}       
