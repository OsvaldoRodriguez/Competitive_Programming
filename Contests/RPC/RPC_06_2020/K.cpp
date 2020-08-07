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
char v[3][9];
string a, b;
bool equals(){
    for(int i = 0; i < sz(a); i++)
        if(a[i] != b[i])
            return 0;
    return 1;
}
map<char, string> m;
int main(){
    //FL;
    FIN;
    char aux = 'a';
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 9; j++)
            v[i][j] = aux++;
    aux = 'a';
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 9; j++){
            string cur = "";
            for(int k = 0; k < 8; k++){
                int i1 = i + dx[k];
                int j1 = j + dy[k];
                if(i1 >= 0 && i1 < 3 && j1 >= 0 && j1 < 9 && v[i1][j1] >= 'a' && v[i1][j1] <= 'z')
                    cur += v[i1][j1];
            }
            m[aux++] = cur;
        }
    }
    int n;
    cin >> n;
    w(n){
        cin >> a >> b;
        if(sz(a) != sz(b))
            cout << 3 << '\n';
        else{
            if(equals())
                cout << 1 << '\n';
            else{
                for(int i = 0; i < sz(a); i++){
                    string cur_1 = m[a[i]];
                    for(int j = 0; j < sz(cur_1); j++)
                        if(cur_1[j] == b[i])
                            a[i] = cur_1[j];
                }
                if(equals())
                    cout << 2 << '\n';
                else
                    cout << 3 << '\n';
            }
        }

    }
    EjecuteTime;
    return 0;
}       
