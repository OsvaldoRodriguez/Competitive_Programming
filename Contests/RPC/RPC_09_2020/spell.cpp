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
const ll mod = 1e8 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
string v[110];
int n;
vector<string> auxii;
bool is(string &s){
    for(int i = 0; i < n; i++)
        if(s == v[i])
            return 1;
    return 0;
}
bool flag = 0;
void omited(string &s, int k){
        for(int j = 0; j < sz(v[k]); j++){
            string aux = v[k].substr(0, j) + v[k].substr(j + 1, sz(v[k]));
            if(aux == s){
                string aaa = "ONE LETTER OMITTED FROM " + v[k];
                auxii.pb(aaa);
                flag = 1;
                return;
            }
        }
      
}

void added(string &s, int k){
        for(int j = 0; j < sz(s); j++){
            string aux = s.substr(0, j) + s.substr(j + 1, sz(s));
            //cout << aux << " " << v[i] << endl;
            if(aux == v[k]){
                string aaa = "ONE LETTER ADDED TO " + v[k];
                auxii.pb(aaa);
                flag = 1;
                return ;
            }
        }
      
}

void diferent(string &s, int k){
        if(sz(s) == sz(v[k])){
            int cnt = 0;
            for(int j = 0; j < sz(s); j++){
                if(s[j] != v[k][j])
                    cnt++;
            }
            if(cnt == 1){
                string aaa = "ONE LETTER DIFFERENT FROM " + v[k];
                auxii.pb(aaa);
                flag = 1;
                return ;
            }
        }
    
}
void traspouse(string &s, int k){
        string aux = v[k];
        for(int j = 1; j < sz(aux); j++){
            aux = v[k];
            swap(aux[j - 1], aux[j]);
            if(s == aux){
                string aaa = "TWO LETTERS TRANSPOSED IN " + v[k];
                auxii.pb(aaa);
                flag = 1;
                return ;
            }
        }
}
void solve(){
    string str;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> v[i];
    int t;
    cin >> t;
    for(int x = 0; x < t; x++){
        auxii.clear();
        flag = 0;
        cin >> str;
        cout << str << '\n';
        if(is(str)){
            cout << "CORRECT";
            if(x + 1 < t)
                cout << '\n';
        }
        else{
            auxii.clear();
            for(int k = 0; k < n; k++){
                omited(str, k);
                added(str, k);
                diferent(str, k);
                traspouse(str, k);
                
            }
            if(!flag){
                cout << "UNKNOWN";
                if(x + 1 < t)
                    cout << '\n';
            }else{
                cout << auxii[0];
                for(int i = 1; i < sz(auxii); i++)
                    cout << '\n' << auxii[i];
                if(x + 1 < t)
                    cout << '\n';
            }
        }
        cout << '\n';
    }
    cout << '\n';
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