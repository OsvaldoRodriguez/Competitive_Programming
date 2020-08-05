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
    int n = sz(s);
    fore(i, 0, n)
        if((s[i] - '0') % 8 == 0){
            cout << "YES\n"; 
            cout << s[i];
            return 0;
        }
    fore(i, 0, n){
        fore(j, i + 1, n){
            int num = (s[i] - '0') * 10 + (s[j] - '0');
            if(num % 8 == 0){
                cout << "YES\n";
                cout << s[i] << "" <<  s[j];
                return 0;
            }
        }
    }
    fore(i, 0, n){
        fore(j, i + 1, n)
            fore(k, j + 1, n){
                int num = ((s[i] - '0') * 10 + s[j] - '0') * 10 + (s[k] - '0');
                if(num % 8 == 0){
                    cout << "YES\n";
                    cout << s[i] << "" << s[j] << "" << s[k];
                    return 0; 
                }  
            }
    }

    cout << "NO\n";
    return 0;
}   
