#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 3 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    fast;
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        bool flag = 0;
        char v[n + 5][m + 5];
        fore(i,1,n + 1){
            fore(j,1,m + 1){
                if((i + j) % 2 == 0)
                    v[i][j] = 'B';
                else
                    v[i][j] = 'W';
            }
        }
        if(n % 2 == 0 && m % 2 == 0){
            if(n < m)
                v[1][m] = 'B';
            else
                v[n][1] = 'B';

        }else if((n * m) % 2 == 0)
            v[n][m] = 'B';
        fore(i,1,n + 1){
            fore(j,1,m + 1){
                cout << v[i][j];
            }
            cout <<"\n";
        }
    }
    return 0;
}   
