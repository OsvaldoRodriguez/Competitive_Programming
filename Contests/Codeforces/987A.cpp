#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
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
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    map<string,int> m;
    map<string,string> m1;
    m["purple"] = 1;
    m["green"] = 1;
    m["blue"] = 1;
    m["orange"] = 1;
    m["red"] = 1;
    m["yellow"] = 1;


    m1["purple"] = "Power";
    m1["green"] = "Time";
    m1["blue"] = "Space";
    m1["orange"] = "Soul";
    m1["red"] = "Reality";
    m1["yellow"] = "Mind";

    int t;
    string s;
    cin >> t;
    int tt = t;
    while(t--){
        cin >> s;
        m[s]++;
    }
    cout << 6 - tt << '\n';
    fori(i,m){
        if(i->S == 1)
            cout << m1[i->F] << '\n';   
    }
    return 0;
}   
