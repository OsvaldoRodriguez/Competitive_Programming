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
const int N = 1 * 1e5 + 50;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {1, 0}, dy[] = {0, 1};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)
bool v[N];
void f(const string &a){
    for(int i = 0; i < sz(a) / 2; i++){
        v[i] = v[sz(a) - i - 1] = (!(a[i] == a[sz(a) - i - 1]));
    }
}
int to_int(char x){return x - 'a';}
int main(){
    //FL;
    FIN;
    int n, p;
    string str;
    cin >> n >> p >> str;
    p--;
    //db(p);
    f(str);
    int count = 0;
    for(int i = 0; i < n; i++)
        if(v[i])count++;
    if(count == 0){
        cout << 0 << '\n';
        return 0;
    }

    // for(int i = 0; i < n; i++)
    //     cout << v[i];
    // cout << '\n';
    int mid = (n + 1) / 2 - 1;
    //db(mid);
    int ans = 0;
    for(int i = 0; i < n / 2; i++){
        if(v[i]){
            int cur = abs(to_int(str[i]) - to_int(str[n - i - 1]));
            ans += min(cur, 26 - cur);
        }
    }
    if(p < mid){
        bool f_1 = 0, f_2 = 0;
        for(int i = 0; i <= mid; i++){
            if(i < p && v[i])
                f_1 = 1;
            if(i > p && v[i])
                f_2 = 1;
        }
        int first = -1, last = -1;
        for(int i = 0; i <= mid; i++){
            if(v[i] && first == -1)
                first = i;
            if(v[i])
                last = i;
        }
        if(f_1 && f_2){
            if((p - first) < last - p)
                ans += 2 * (p - first) + last - p;
            else
                ans += p - first + 2 * (last - p);
        }else{
            if(f_1)
                ans += p - first;
            else if(f_2)
                ans += last - p;
        }
    }else{
        bool f_1 = 0, f_2 = 0;
        mid++;
        for(int i = mid; i < n; i++){
            if(i < p && v[i])
                f_1 = 1;
            if(i > p && v[i])
                f_2 = 1;
        }
        
        int first = -1, last = -1;
        for(int i = mid; i < n; i++){
            if(v[i] && first == -1)
                first = i;
            if(v[i])
                last = i;
        }
        if(f_1 && f_2){
            if(p - first < last - p)
                ans += 2 * (p - first) + last - p;
            else
                ans += p - first + 2 * (last - p);
        }else{
            if(f_1)
                ans += p - first;
            else if(f_2)
                ans += last - p;
        }
    }
    cout << ans << '\n';
    EjecuteTime;
    return 0;
}       
