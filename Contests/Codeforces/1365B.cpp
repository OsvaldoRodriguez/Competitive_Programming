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
#define db(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x) double(x * acos(-1) / 180.0)
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
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int arr[505];
bool v[505];
bool check(int n){
    fore(i, 1, n)
        if(arr[i] < arr[i - 1])
            return  0;
    return 1;
}
int main(){
    //FL;
    fin;
    int t;
    cin >> t;
    w(t){
        cls(v, 0);
        int n;
        cin >> n;
        fore(i, 0, n)cin >> arr[i];
        fore(i, 0, n)cin >> v[i];
        if(check(n))
            cout << "Yes\n";
        else{
            bool flag_1 = 0,flag_2 = 0;
            fore(i, 0, n){
                if(v[i])
                    flag_1 = 1;
                else
                    flag_2 = 1;
            }
            cout << (flag_2 && flag_1 ? "Yes" : "No") << '\n';
        }
    }
    time;
    return 0;
}       
