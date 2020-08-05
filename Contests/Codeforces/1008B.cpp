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
const int N = 3 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
bool isVowel(char x){
    return x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u';
}
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    int t;
    cin >> t;
    bool flag = 1;
    ll x,y;
    cin >> x >> y;
    ll aux = max(x,y);
    t--;
    while(t--){
        ll a,b;
        cin >> a >> b;
        ll df = max(a,b);
        if(df <= aux)
            aux = df;
        else{
            ll df1 = min(a,b);
            if(df1 > aux)
                flag = 0;
            else
                aux = df1;
        }

    }
    cout << (flag ? "YES":"NO") << '\n';
    return 0;
}   
