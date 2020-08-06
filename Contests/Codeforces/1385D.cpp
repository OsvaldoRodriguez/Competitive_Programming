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
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int v[26][N];
int q(int i, int j, int car){
    if(i == 0)
        return v[car][j];
    return v[car][j] - v[car][i - 1];
}
int f(int i, int j, int car){
    if(j - i == 0)return 1 - q(i, j, car);
    int ans = 0;
    int mid = (i + j) >> 1;
    ans = 1e9;
    ans = min(ans, f(i, mid, car + 1) + (j - (mid + 1) + 1) - q(mid + 1, j, car));
    ans = min(ans, f(mid + 1, j, car + 1) + (mid - i + 1) - q(i, mid, car));
    return ans;
}
int main(){
    //FL;
    FIN;
    int t;
    cin >> t;
    w(t){
        int n;
        cin >> n;
        string str;
        cin >> str;
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < n; j++)
                v[i][j] = 0;
        for(int i = 0; i < n; i++){
            v[str[i] - 'a'][i] = 1;
        }
        for(int i = 0; i < 26; i++){
            for(int j = 1; j < n; j++)
                v[i][j] += v[i][j - 1];
        }
        cout << f(0, n - 1, 0) << '\n';
    }
    EjecuteTime;
    return 0;
}       
