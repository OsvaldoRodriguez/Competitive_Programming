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
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    string s;
    cin >> s;
    bool flag = 0;
    bool sw = 0;
    fore(i, 0, sz(s) - 1){
        if(((s[i] == 'A' && s[i + 1] == 'B')) && !flag){
            flag = 1;
            i++;
            continue;
        }
        if(((s[i] == 'B' && s[i + 1] == 'A')) && flag)
            sw = 1;
    }
    if(sw == 0){
        flag = 0;
        fore(i, 0, sz(s) - 1){
            if(((s[i] == 'B' && s[i + 1] == 'A')) && !flag){
                flag = 1;
                i++;
                continue;
            }
            if(((s[i] == 'A' && s[i + 1] == 'B')) && flag)
                sw = 1;
        }   
        cout << (sw ? "YES" : "NO") << '\n';
    }else
        cout << "YES\n";
    return 0;
}   
