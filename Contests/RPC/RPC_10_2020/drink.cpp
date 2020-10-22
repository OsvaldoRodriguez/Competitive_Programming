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
#define FI          freopen("input.txt", "r", stdin)
#define FO          freopen("output.txt", "w", stdout)
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e3 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-7;
const int INF = 1e2;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
//105470163083
//100000000223257 primos
//1000000000318157
typedef long double T;
struct punto{
    T x, y;
    punto(): x(0), y(0){};
    punto(T _x, T _y){x = _x, y = _y;}
    punto operator + (punto &A){return punto(x + A.x, y + A.y);}
    punto operator - (punto &A){return punto(x - A.x, y - A.y);}
    punto operator * (T k){return punto(x * k, y * k);}
    T operator * (punto &A){return x * A.x + y * A.y;}
    T operator ^ (punto &A){return x * A.y - y * A.x;}
};
ostream &operator << (ostream &COUT, punto &A){
    cout << "( " << A.x << " " << A.y << ")";
    return COUT;
}
punto v[5];
void solve(){
    for(int i = 1; i <= 4; i++)
        cin >> v[i].x >> v[i].y;
    punto p1, d1, p2, d2, ints;
    p1 = v[1];
    d1 = v[2] - v[1];
    p2 = v[3];
    d2 = v[4] - v[3];

    T alfa = ((p2 - p1) ^ d2) / (d1 ^ d2);
    T beta = ((p1 - p2) ^ d1) / (d2 ^ d1);
    
    // intersection
    punto X1 = (d1 * alfa) + p1;
    punto Y = (d2 * beta) + p2;
    if(alfa >= 0 && alfa <= 1 && beta >= 0 && beta <= 1){
        punto pt, P2, d2, d1;
        if(v[4]. y < v[2].y){
            pt = v[4];
            P2 = v[2];
            d2 = v[2] - v[1];
        }
        else{
            pt = v[2];
            P2 = v[4];
            d2 = v[4] - v[3];
        }
        //hallando el punto 3 de interseccion
        punto P1(0, pt.y);
        punto aux(1, pt.y);
        d1 = P1 - aux;
        alfa = ((P2 - P1) ^ d2) / (d1 ^ d2);
        punto X2 = (d1 * alfa) + P1;

        punto D1 = pt - X1;
        punto D2 = X2 - X1;

        T area = abs((D1 ^ D2) / 2.0);
        cout << fixed << setprecision(7) << area << '\n';

    }else
        cout << fixed << setprecision(7) << 0.0 << '\n';


}
int main(){
    FIN;
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    //EjecuteTime;
    return 0;

}