#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
#define pl          pair<long long, long long>
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
#define FL          freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef unsigned long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int main(){
    //FL;
    FIN;
    int t;
    cin >> t;
    w(t){
        ll ans = LONG_LONG_MAX;
        vector<pair<ll, ll>> v(3);  
        for(int i = 0; i < 3; i++)
            cin >> v[i].F >> v[i].S;

        for(int i = 0; i < 8; i++){
            ll altura = 0, base = 0;
            for(int j = 0; j < 3; j++){
                if(i & (1 << j)){
                    base += v[j].S;
                    altura = max(altura, v[j].F);
                }else{
                    base += v[j].F;
                    altura = max(altura, v[j].S);
                }
            }
            ans = min(ans, base * altura);
        }
        sort(all(v));
        do{

            for(int i = 0; i < 8; i++){
                ll altura = 0, base = 0;
                ll altura_1 = 0;
                ll base_1 = 0;
                for(int j = 0; j < 3; j++){
                    if(i & (1 << j))
                        swap(v[j].F, v[j].S);
                    if(j == 0 or j == 1){
                        base_1 = max(base_1, v[j].F);
                        altura_1 += v[j].S;
                    }else{
                        altura = v[j].S;
                        base = v[j].F;
                    }
                    if(i & (1 << j))
                        swap(v[j].F, v[j].S);
                }

              
                ans = min(ans, max(altura, altura_1) * (base + base_1));

        }
        }while(next_permutation(all(v)));
        cout << ans << '\n';
    }
    EjecuteTime;
    return 0;
}       
