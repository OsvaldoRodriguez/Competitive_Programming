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
const int N = 1e3 + 50;
const ll mod = 1e9 + 7;
const double E = 1e-9;
ll A[N][N], BIT[N][N];
int n, m; 
void update(int pos_i, int pos_j, int val){
    for(int i = pos_i; i <= n; i += i&(-i))
        for(int j = pos_j; j <= m; j += j&(-j))
            BIT[i][j] += val;
}

void build(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            update(i, j, A[i][j]);
}

int sum(int pos_i, int pos_j){
    int sum = 0;
    for(int i = pos_i; i > 0; i -= i&(-i))
        for(int j = pos_j; j > 0; j -= j&(-j))
            sum += BIT[i][j];
    return sum;
}

int main(){
    //FL;
    FIN;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> A[i][j];

    build();
    int a, b, c, d, op;
    int q;//query
    cin >> q;
    while(q--){ //  x1   y1   x2   y2
        cin >> op >> a >> b >> c >> d;
        if(op == 1)
            cout << sum(c, d) - (c, b - 1) - sum(a - 1, d) + sum(a - 1, b - 1) << '\n';
        else{
            update(a, b, c - A[a][b]);
            A[a][b] = c;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++)
                    cout << A[i][j] << ' ';
                cout << endl;
            }
        }
    }
    EjecuteTime;
    return 0;
}       