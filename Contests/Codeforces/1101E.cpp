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
ii v[N];
int arr[N];
int main(){
    fast;
    int t;
    cin >> t;
    char s;
    int a,b;
    int rec_x = -1, rec_y = -1;
    while(t--){
        cin >> s >> a >> b;
        if(a > b)
            swap(a,b);
        if(s == '+')
            rec_x = max(rec_x,a),rec_y = max(rec_y,b);
        else{
            if(rec_x <= a && rec_y <= b)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
    
