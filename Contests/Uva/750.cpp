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
#define forir(i,m)   for(auto i = m.rend(); i != m.rbegin(); i++) 
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
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;
const double E = 1e-6;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
int v[10];
int D1[17], D2[17];
void solve(){
    int x, y;
    scanf("%d %d", &x, &y);
    iota(v + 1, v + 9, 1);
    
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    int sol = 1;
    do{
        if(v[y] != x)
           continue;
        bool flag = 1;
        cls(D1, 0);
        cls(D2, 0);
        for(int i = 1; i < 9; i++){
            D1[i + v[i]]++;
            D2[v[i] - i + 8 - 1 + 2]++;
        }
        for(int i = 2; i < 17 && flag; i++){
            if(D1[i] > 1 or D2[i] > 1)
                flag = 0;
        }
        if(flag){    
            printf("%2d      ",sol++);
            printf("%d",v[1]);
            for(int i = 2; i < 9; i++)
                printf(" %d",v[i]);
            printf("\n");
        }
    }while(next_permutation(v + 1, v + 9));
}
int main(){
    //FIN;
    int t = 1;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        if(i > 1)
            printf("\n");
        solve();
    }
    //EjecuteTime;
    return 0;
}       
