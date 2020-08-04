#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
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
int v[26],v1[26],v2[26];
int main(){ 
    fast;
    int t;
    cin >> t;
    string a,b,c;
    bool flag = 0;
    while(t--){
        flag = 0;
        cin >> a >> b >> c;
        fore(i,0,sz(c)){
            if(a[i] == b[i] && (a[i] != c[i])){
                flag = 1;
                break;
            }
            if(b[i] == c[i])
                swap(a[i],c[i]);
            if(a[i] == c[i])
                swap(b[i],c[i]);
        }
        if(flag)
            cout << "NO\n";
        else if(a == b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
    
