#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<long long,long long>
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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){
    fast;
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> v(n);
    fore(i,0,n)
        cin >> v[i];
    if(x > y)
        cout << n << '\n';
    else{
        sort(all(v));
        int i = 0;
        int a = -1,b = n + 1,mid;
        while(b - a > 1){
            mid = (a + b) >> 1;
            if(v[mid] <= x)
                a = mid;
            else
                b = mid;
        }
        a++;
        cout << (a + 1) / 2 << '\n';
    }
	return 0;
}
