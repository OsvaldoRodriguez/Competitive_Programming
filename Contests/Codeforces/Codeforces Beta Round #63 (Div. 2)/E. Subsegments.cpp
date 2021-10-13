#include <bits/stdc++.h>
#define ii              pair<int,int>
#define F               first
#define S               second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define rall(x)         (x).rbegin(),(x).rend()
#define fore(i, a, b)   for(int i = a; i < b; i += 1)
#define forr(i, a)      for(int i = a; i >= 0; i--)
#define sz(s)           int(s.size())
#define cls(a, car)     memset(a,car,sizeof (a))
#define db(x)           cout << #x << " is " << x << '\n'
#define angle(x)        double(x * acos(-1) / 180.0)
using namespace std;
void debug(){cout << endl;}
template<typename T, typename... Args>
void debug(T a, Args... args){cout << a << " "; debug(args...);}
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 2e5 + 15;
const ll mod = INT_MAX;
const double E = 1e-7;
int A[N];
void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    map<int, int> m;
    set<int> s;
    for(int i = 0; i < k; i++){
        m[A[i]]++;
    }

    for(auto i : m){
        if(i.S == 1)
            s.insert(i.F);
    }

    if(s.size() == 0)
        cout << "Nothing\n";
    else
        cout << *s.rbegin() << '\n';

    // for(auto i : m)
    //     cout << i.F << " " << i.S << endl;

    int i = 0, j = k;
    while(i < n and j < n){
        if(m[A[i]] == 1){
            s.erase(A[i]);
        }else if(m[A[i]] == 2){
            s.insert(A[i]);
        }
        m[A[i]]--;

        if(m[A[j]] == 0)
            s.insert(A[j]);
        else
            s.erase(A[j]);
        
        m[A[j]]++;
        if(s.size() == 0)
            cout << "Nothing\n";
        else
            cout << *s.rbegin() << '\n';
        i++;j++;
    }
}
int main(){
    #ifdef FURY
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){ 
        solve();
    }

    #ifdef FURY
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
