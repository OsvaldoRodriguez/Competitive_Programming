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
#define ff(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b) 
int v[25][25];
int arr[1010];
int main(){
    //FL;
    fin;
    int n;
    cin >> n;
    vi aux;
    fore(i, 0, n * n){
        int x;
        cin >> x;
        arr[x]++;
        aux.pb(x);
    }
    sort(all(aux));
    if(n & 1){
        bool flag = 1;
        vi four, one, two;
        fore(i, 1, 1010){
            int aux = arr[i] % 4;
            fore(j, 0, arr[i] / 4 * 4)
                four.pb(i);
            fore(j, 0, aux / 2 * 2)
                two.pb(i);
            aux %= 2;
            if(aux == 1)
                one.pb(i);
        }
        if(sz(one) == 0 or sz(one) > 1 or sz(two) / 2 > n - 1)
            flag = 0;
        if(!flag)
            cout << "NO\n";
        else{
            int idx = 0;
            v[(n + 1) / 2][(n + 1) / 2] = one[0];
            fore(i, 1, n / 2 + 1){
                fore(j, 1, n / 2 + 1){
                    v[i][j] = four[idx++]; 
                    v[i][n - j + 1] = four[idx++];
                    v[n - i + 1][j] = four[idx++];
                    v[n - i + 1][n - j + 1] = four[idx++];
                }
            }
            if(idx + 1 < sz(four))
                while(idx < sz(four))
                    two.pb(four[idx++]);
            idx = 0;
            int mid = (n + 1) / 2;
            fore(i, 1, n /2 + 1){
                v[i][mid] = two[idx++];
                v[n - i + 1][mid] = two[idx++];
                v[mid][i] = two[idx++];
                v[mid][n - i + 1] = two[idx++];
            }
            cout << "YES\n";
            fore(i, 1, n + 1){
                fore(j, 1, n + 1)
                    cout << v[i][j] << ' ';
                cout << '\n';
            }

        }
    }else{
        bool flag = 1;
        fore(i, 1, 1010)
            if(arr[i] % 4)
                flag = 0;
        if(!flag)
            cout << "NO\n";
        else{
            int idx = 0;
            fore(i, 1, n / 2 + 1){
                fore(j, 1, n / 2 + 1){
                    v[i][j] = aux[idx++]; 
                    v[i][n - j + 1] = aux[idx++];
                    v[n - i + 1][j] = aux[idx++];
                    v[n - i + 1][n - j + 1] = aux[idx++];
                }
            }
            cout << "YES\n";
            fore(i, 1, n + 1){
                fore(j, 1, n + 1)
                    cout << v[i][j] << ' ';
                cout << '\n';
            }
        }
    }
    time;
    return 0;
}   
