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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
//freopen("","r",stdin);
//freopen("","w",stdout);
int main(){
    fast;
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v)cin >> i;
    if(n == 1){
        if(v[0] > 15)
            cout << "15\n";
        else if(v[0] + 15 <= 90)
            cout << v[0] + 15 << '\n';
        else cout << "90\n";
        return 0;
    }
    if(v[0] > 15)
        cout << "15\n";
    else{
        fore(i,1,n){
            if(v[i] - v[i - 1] > 15){
                if(v[i - 1] + 15 <= 90){
                    cout << v[i - 1] + 15 << '\n';
                    return 0;
                }
            }
        }
        if(90 - v[n - 1] > 15)
            cout << v[n - 1] + 15 << '\n';else
        cout << "90\n";
    }
	return 0;
}
