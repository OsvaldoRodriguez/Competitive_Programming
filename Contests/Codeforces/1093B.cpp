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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    int t;
    cin >> t;
    w(t){
        string s;
        bool flag = 1;
        cin >> s;
        int v[26];
        cls(v, 0);
        fore(i, 0, sz(s))
            if(s[i] != s[sz(s) - i - 1])
                flag = 0;
        //cout << s << " " << flag << endl;
        if(flag){
            flag = 1;
            fore(i, 0, sz(s))
                v[s[i] - 'a']++;
            fore(i, 0, 26)
                if(v[i] == sz(s))
                    flag = 0;
                
            if(flag){
                sort(all(s));
                cout << s << '\n';
            }
            else
                cout << "-1\n";
        }else cout << s << '\n';
    }
    return 0;
}   
