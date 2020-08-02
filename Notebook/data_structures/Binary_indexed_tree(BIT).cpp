#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
#define F           first
#define S           second
#define pb          push_back
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a)   for(int i = a; i >= 0; i--)
#define fori(i,m)   for(auto i = m.begin(); i != m.end(); i++) 
#define w(t)        while(t--)
#define sz(s)       int(s.size())
#define cls(a,car)  memset(a,car,sizeof (a))
#define db(x)       cerr << #x << " is " << x << '\n'
#define FL          freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;
const double E = 1e-9;
ll A[N], BIT[N];
int n;
// n len array
void update(int pos, int val){ // O(log n)
    for(int i = pos; i <= n; i += i&(-i))
        BIT[i] += val;
}

void build(){ // O(n)
    for(int i = 1; i <= n; i++)
        update(i, A[i]);
}

ll getSum(int pos){ // O(log n)
    ll ans = 0;
    for(int i = pos; i > 0; i -= i&(-i))
        ans += BIT[i];
    return ans;
}
int main(){
    //FL;
    FIN;
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    build();
    int op, l, r;
    while(q--){
        cin >> op >> l >> r;
        l++;
        if(op == 1){
            update(l, r - A[l]);
            A[l] = r;   
        }
        else
            cout << getSum(r) - getSum(l - 1) << '\n';
        
    }
    EjecuteTime;
    return 0;
}       
