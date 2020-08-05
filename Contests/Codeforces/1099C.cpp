#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
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
typedef vector<ii> vii;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    fin;
    string s;
    int n;
    cin >> s >> n;
    int cnt = 0;
    int ext1 = 0;
    int ext2 = 0;
    fore(i, 0, sz(s)){
        if(s[i] == '?')
            ext1++;
        if(s[i] == '*')
            ext2++;
    }
    int aux;
    cnt = ext1 + ext2;
    if((sz(s) - cnt) - cnt > n)
        cout << "Impossible\n";
    else{
        string ans = "";
        aux = sz(s) - cnt;
        if(aux < n && ext2 == 0)
            cout << "Impossible\n";
        else{
            string ans = "";
            if(sz(s) - cnt > n){
                fore(i, 0, sz(s)){
                    //cout << ans << " par aux " << aux << endl   ;
                    if(s[i] != '*' && s[i] != '?')
                        ans += s[i];
                    if((s[i] == '*' or s[i] == '?') && n < aux){
                        int k = sz(ans) - 1;
                        while(k >= 0 && ans[k] == '#')
                            k--;
                        if(k >= 0){
                            ans[k] = '#';
                            aux--;
                        }
                    }   
                }
                //cout << ans <<  ' ' << aux << " par\n";
                //cout << ans << " eli\n";
                if(aux != n)
                    ans = "Impossible";
                //cout << "eli\n";
            }else{
                //cout << " aug\n";
                fore(i, 0, sz(s)){
                    if(s[i] != '*' && s[i] != '?')
                        ans += s[i];
                    if(s[i] == '*' && aux < n){
                        int df = abs(sz(s) - cnt - n);
                        char auxi = ans[sz(ans) - 1];
                        fore(j, 0, df)
                            ans += auxi;
                        n -= df;
                    }
                }
                if(aux != n)
                    s = "Impossible\n";
            }
            fore(i, 0, sz(ans))
                if(ans[i] != '#')
                    cout << ans[i];cout << '\n';
        }
    } 
    return 0;
}   
