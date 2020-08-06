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
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int main(){
    //FL;
    fin;
    int t;
    cin >> t;
    w(t){
        string str;
        cin >> str;
        int n = sz(str);
        int pre[n + 1], suf[n + 1];
        cls(pre, 0);
        cls(suf, 0);
        fore(i, 0, n){
            if(str[i] == '0')
                pre[i] = 1;
        }
        forr(i, n - 1)
            if(str[i] == '1')
                suf[i] = 1;
        fore(i, 1, n)
            pre[i] += pre[i - 1];
        for(int i = n - 2; i >= 0; i--)
            suf[i] += suf[i + 1];
        int ans = 1e9;
        fore(i, 0, n){
            int l = 0, r = 0;
            if(i == 0)
                l = 0;
            else
                l = pre[i - 1];
            if(i + 1 == n)
                r = 0;
            else
                r = suf[i + 1];
            ans = min(ans, l + r + (str[i] == '0'));

        }



        cls(pre, 0);
        cls(suf, 0);
        fore(i, 0, n){
            if(str[i] == '1')
                pre[i] = 1;
        }
        forr(i, n - 1)
            if(str[i] == '0')
                suf[i] = 1;
        fore(i, 1, n)
            pre[i] += pre[i - 1];
        for(int i = n - 2; i >= 0; i--)
            suf[i] += suf[i + 1];
        
        fore(i, 0, n){
            int l = 0, r = 0;
            if(i == 0)
                l = 0;
            else
                l = pre[i - 1];
            if(i + 1 == n)
                r = 0;
            else
                r = suf[i + 1];
            ans = min(ans, l + r + (str[i] == '1'));

        }

        cout << ans << '\n';
    }
    time;
    return 0;
}       
