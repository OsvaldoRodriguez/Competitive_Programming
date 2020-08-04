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
int v[26];
int arr[N],acc[N];
int main(){
    fast;
    int t;
    int a,b;
    cin >> t;
    string s;
    while(t--){
        int n,m;
        cin >> n >> m >> s;
        cls(v,0);
        cls(arr,0);
        fore(i,0,n)
            v[s[i] - 'a']++;
        fore(i,0,m){
            int x;
            cin >> x;
            x--;
            arr[x]++;
        }
        acc[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--){
            acc[i] = arr[i] + acc[i + 1];
        }
        fore(i,0,n){
            //cout << acc[i] << ' ';
            v[s[i] - 'a'] += acc[i];
        }
        fore(i,0,26)
            cout << v[i] << ' '; 
        cout << endl;
    }
    return 0;
}
    
