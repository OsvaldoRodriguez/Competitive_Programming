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
const int N = 2e5 + 15;
const ll mod = INT_MAX;
const double E = 1e-7;

void solve(){
    int x, y;
    cin >> x >> y;
    bool flag = 1;
    // 1 ciel
    bool aux = 1;
    while(aux){
        // Ciel
        if(flag){    
            if(x >= 2 and y >= 2){
                x -= 2;
                y -= 2;
                flag ^= 1;
            }else if(x >= 1 and y >= 12){
                x--;
                y -= 12;
                flag ^= 1;
            }else if(y >= 22){
                y -= 22;
                flag ^= 1;
            }else
                aux = 0;
        }else{
            if(y >= 22){
                y -= 22;
                flag ^= 1;
            }else{
                if(y >= 12 and x >= 1){
                    y -= 12;
                    x--;
                    flag ^= 1;
                }else{
                    if(y >= 2 and  x >= 2){
                        y -= 2;
                        x -= 2;
                        flag ^= 1;
                    }else
                        aux = 0;
                }
            }


        }
    }
    cout << (!flag ? "Ciel" : "Hanako") << '\n';
}
int main(){
    #ifdef FURY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){ 
        solve();
    }

    #ifdef FURY
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
