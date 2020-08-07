#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
#define pl          pair<long long, long long>
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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
string v[105];
int vis[105];
int n;
bool f(){
    int cur = 0;
    for(int i = 0; i < n; i++)
        if(vis[i] == -1)
            cur++;
    return cur == 1;
}
int main(){
    //FL;
    //FIN;
    string rhyme;
    getline(cin, rhyme);
    int cur = 0;
    for(int i = 0; i < sz(rhyme); i++){
        string aux = "";
        while(i < sz(rhyme) && rhyme[i] != ' ')
            aux += rhyme[i++];
        cur++;
    }
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    vector<string> team_1, team_2;
    bool flag = 1;
    int i = -1;
    cls(vis, -1);
    while(1){
        if(f())
            break;
        int count = 0;
        int j = (i + 1) % n;
        while(vis[j % n] != -1)
            j = (j + 1) % n;
        // db("star");
        // db(j);
        // for(int k = 0; k < n; k++)
        //     cout << vis[k] << ' ';
        // cout << endl;
        while(1){
            if(vis[j % n] == -1){
                count++;
                if(count == cur){
                    if(flag)
                        team_1.pb(v[j]);
                    else
                        team_2.pb(v[j]);
                    flag ^= 1;
                    vis[j % n] = 1;
                    break;
                }
            }
            j = (j + 1) % n;
        }
        i = j;

    }
    for(int i = 0; i < n; i++){
        if(vis[i] == -1){
            if(flag)
                team_1.pb(v[i]);
            else
                team_2.pb(v[i]);
        }
    }
    cout << sz(team_1) << '\n';
    for(auto i : team_1)
        cout << i << '\n';


    cout << sz(team_2) << '\n';
    for(auto i : team_2)
        cout << i << '\n';
    EjecuteTime;
    return 0;
}       
