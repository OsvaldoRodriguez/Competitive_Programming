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
#define what_is(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 3 * 1e6 + 5;
const ll mod = 998244353;
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
    map<pair<int, string> , pair < int, ii > > m;
    int times = 0;
    w(t){
        int n;
        string s;
        cin >> n >> s;
        times++;
        m[{times, s}].F = 0;
        m[{times, s}].S.F = 0;
        m[{times, s}].S.S = 0;
        w(n){
            string str;
            cin >> str;
            set<char> st;
            string aux = "";
            fore(i, 0, sz(str)){
                if(str[i] != '-'){
                    st.insert(str[i]);
                    aux += str[i];
                }
            }
            if(sz(st) == 1)
                m[{times, s}].F++;
            else{
                bool flag = 1;
                fore(i, 1, sz(aux)){
                    if(aux[i] - '0' >= aux[i - 1] - '0'){
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                    m[{times, s}].S.F++;
                else
                    m[{times, s}].S.S++;
            }
        }
    }
    int mx_1 = 0, mx_2 = 0, mx_3 = 0;
    fori(i, m){
            mx_1 = max(mx_1, (i->S).F);
            mx_2 = max(mx_2, (i->S).S.F);
            mx_3 = max(mx_3, (i->S).S.S);
        }
    vector<string> a, b, c;
    fori(i, m){
        if((i->S).F == mx_1)
            a.pb((i->F).S);
        if((i->S).S.F == mx_2)
            b.pb((i->F).S);
        if((i->S).S.S == mx_3)
            c.pb((i->F).S);
    }
    cout << "If you want to call a taxi, you should call: ";
    if(sz(a))
    cout << a[0];
    fore(i, 1, sz(a))
        cout << ", " << a[i];
    cout << ".\n";

    cout << "If you want to order a pizza, you should call: ";
    if(sz(b))
    cout << b[0];
    fore(i, 1, sz(b))
        cout << ", " << b[i];
    cout << ".\n";

    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    if(sz(c))
    cout << c[0];
    fore(i, 1, sz(c))
        cout << ", " << c[i];
    cout << ".\n";
    time;
    return 0;
}   
