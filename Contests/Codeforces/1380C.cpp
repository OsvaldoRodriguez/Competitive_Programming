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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
ll v[N];
int n;
ll x;
bool f(int z){
    //db(z);
    int aux = 0;
    int end = -1;
    for(int i = 0; i < n; i++){
        if(v[i] >= x){
            aux++;
            if(end == -1)
                end = i;
        }
    }
    int teams = 0;
    if(end == -1)
        end = n;
    
    //db(end);
    int end_2 = end;
    for(int i = end - 1; i >= 0; i--){
        //db(i);
        ll k = x / v[i];
        if(k * v[i] < x)
            k++;
        //db(k);
        if(end_2 - i >= k){
            //cout << "YES\n";
            teams++;
            end_2 = i;
        }
    }
    /*for(int i = 0; i < end; i++){
        db(i);
        ll k = x / v[i];
        if(k * v[i] < x)
            k++;
        db(k);
        if(i + k - 1 < end){
            teams++;
            i = i + k - 1;
        }
    }*/
    //db(teams);
    //db(aux);
    return teams + aux >= z;
}
int main(){
    //FL;
    FIN;
    int t;
    cin >> t;
    w(t){
        cin >> n >> x;
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v, v + n);
        int a = 0, b = n + 1, mid;
        while(b - a > 1){
            mid = (a + b) >> 1;
            if(f(mid))
                a = mid;
            else
                b = mid;
        }
        cout << a << '\n';
        

    }
    EjecuteTime;
    return 0;
}       
