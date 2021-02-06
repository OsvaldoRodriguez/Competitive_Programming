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
#define FL          freopen("in", "r", stdin),freopen("out", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
bool car(char x){
    return  ('A' <= x and x <= 'Z') or ('a' <= x and x <= 'z'); 
}
int f(char cmp){
    int ans = -1;
    if(cmp == '^')
        ans = 10;
    else if(cmp == '*' or cmp == '/')
        ans = 9;
    else if(cmp == '+' or cmp == '-')
        ans = 8;
    return ans; 
}
string solve(const string &str){
    stack<char> s;
    string ans = "";
    fore(i, 0, sz(str)){
        if(car(str[i]))
            ans += str[i];
        
        else if(str[i] == '(')
            s.push(str[i]);
        else if(str[i] == ')'){
            while(!s.empty() && s.top() != '('){
                ans += s.top();
                s.pop();
            }
            if(sz(s) && s.top() == '(')
                s.pop();
        }
        else{ // operador
            while(!s.empty() && f(str[i]) <= f(s.top())){
                ans += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    return ans;
}
int main(){
    //FL;
    FIN;
    int t;
    string str;
    cin >> t;
    w(t){
        cin >> str;
        cout << solve(str) << '\n';
    }
    EjecuteTime;
    return 0;
}       
