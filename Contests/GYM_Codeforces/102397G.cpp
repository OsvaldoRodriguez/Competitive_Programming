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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int acc[N],acc1[N];
int main(){
    fast;
    int n,k;
    cin >> n >> k;
    fore(i,0,n){
        int x;
        cin >> x;
        acc[x]++;
    }

    fore(i,0,n){
        int x;
        cin >> x;
        acc1[x]++;
    }

    ll ans1 = 0;
    ll ans2 = ans1;
    for(int i = 0; i <= k; i++){
        if(acc[i] && acc[k - i])
            ans1 += (acc[i] * acc[k - i]);
        if(acc1[i] && acc1[k - i])
            ans2 += (acc1[i] * acc1[k - i]);
    }
    if(ans2 == ans1)
        cout << "DRAW\n";
    else if(ans1 > ans2)
        cout << "MAHMOUD\n";
    else cout << "BASHAR\n";
    return 0;
}
