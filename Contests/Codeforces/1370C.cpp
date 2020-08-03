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
#define FL          freopen("in", "r", stdin),freopen("out", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 400;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int main(){
    //FL;
    FIN;
    int t;
    cin >> t;
    string player_1 = "Ashishgup";
    string player_2 = "FastestFinger";
    w(t){
        ll n;
        cin >> n;
        if(n == 1)
            cout << player_2 << '\n';
        else if(n == 2)
            cout << player_1 << '\n';
        else{
            if(n & 1)
                cout << player_1 << '\n';
            else{
                bool flag = 0;
                for(ll i = 1; i * i <= n; i++){
                    if(i == 1)
                        continue;
                    if(n % i == 0){
                        if(!(i & 1)){
                            ll aux = n / i;
                            if((aux & 1) && i != 2){
                                flag = 1;
                                break;
                            }
                        }else{
                            ll aux = n / i;
                            if(!(aux & 1) && aux != 2){
                                flag = 1;
                                break;
                            }
                        }
                    }
                }
                if(flag)
                    cout << player_1 << '\n';
                else
                    cout << player_2 << '\n';
            }
        }

    }
    EjecuteTime;
    return 0;
}       
