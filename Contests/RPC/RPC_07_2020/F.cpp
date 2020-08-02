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
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int _dx[] = {0, 1}, _dy[] = {1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
pair<ii, int> A[12];
pair<ii, int> B[12];
int dis[12];
ll d(int x, int y, int x_1, int y_1){
    return (x - x_1) * (x - x_1) + (y - y_1) * (y - y_1);
}
double f(int x, int y, int x_1, int y_1){
    return sqrt((x - x_1) * (x - x_1) + (y - y_1) * (y - y_1));   
}
int main(){
    //FL;
    FIN;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i].F.F >> A[i].F.S;
        A[i].S = i;
    }
    for(int j = 0; j < n; j++){
        cin >> B[j].F.F >> B[j].F.S;
        B[j].S = j;
    }
    for(int i = 0; i < n; i++)
        dis[i] = 100;
    queue<pair<ii, int>> q;
    q.push(A[n - 1]);
    dis[n - 1] = 0;
    while(sz(q)){
        auto _A = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            auto _C = A[i]; 
            if(_A == _C)continue;
            bool flag = 1;
            for(int j = 0; j < n; j++){
                auto _B = B[j];
                if(abs(f(_A.F.F, _A.F.S, _B.F.F, _B.F.S) + f(_B.F.F, _B.F.S, _C.F.F, _C.F.S) - f(_A.F.F, _A.F.S, _C.F.F, _C.F.S)) < E && d(_A.F.F, _A.F.S, _B.F.F, _B.F.S) + d(_B.F.F, _B.F.S, _C.F.F, _C.F.S) != d(_A.F.F, _A.F.S, _C.F.F, _C.F.S)){
                    flag = 0;
                }
                _B = A[j];
                if(_B == _A or _B == _C) continue;
                if(abs(f(_A.F.F, _A.F.S, _B.F.F, _B.F.S) + f(_B.F.F, _B.F.S, _C.F.F, _C.F.S) - f(_A.F.F, _A.F.S, _C.F.F, _C.F.S)) < E && d(_A.F.F, _A.F.S, _B.F.F, _B.F.S) + d(_B.F.F, _B.F.S, _C.F.F, _C.F.S) != d(_A.F.F, _A.F.S, _C.F.F, _C.F.S)){
                    flag = 0;
                }
            }


            if(flag)
                if(dis[_A.S] + 1 < dis[_C.S]){
                    dis[_C.S] = dis[_A.S] + 1;
                    q.push(_C);
                }
        }
    }
    if(dis[0] == 100)
        dis[0] = -1;
    cout << dis[0] << '\n';
    EjecuteTime;
    return 0;
}       