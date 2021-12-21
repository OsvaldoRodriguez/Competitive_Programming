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
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
int dx[] = {1, 0}, dy[] = {0, 1};
int f(char x){
    return x - '0';
}
int main(){
    //FL;
    FIN;
    string str;
    cin >> str;
    int HH = 0.0 + f(str[0]) * 10 + f(str[1]);
    HH %= 12;
    double H = HH;
    double M = 0.0 + f(str[3]) * 10 + f(str[4]);
    double fact = M / 60.0;
    double aux = fact * 30.0;
    double ang = H * 30.0 + aux;
    if(H == 12)
        ang = 0;
    cout << fixed << setprecision(9) << ang << ' ' << M * 6.0 << endl;
    EjecuteTime;
    return 0;
}       
