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
const int N = 1 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int a1[N],a0[N],a2[N],acc1[N],acc0[N],acc2[N],v[N];
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    fast;
    int t;
    cin >> t;
    while(t--){ 
        int n;
        cin >> n;
        fore(i,0,n){
            int x;
            cin >> x;
            v[i] = x;
            if(x == 1)
                a1[i] = 1;
            else a1[i] = 0;
            if(x == 0)
                a0[i] = 1;
            else
                a0[i] = 0;
            if(x == -1)
                a2[i] = 1;
            else
                a2[i] = 0;
        }
        acc1[0] = a1[0];
        fore(i,1,n)
            acc1[i] = acc1[i - 1] + a1[i];

        acc0[0] = a0[0];
        fore(i,1,n)
            acc0[i] = acc0[i - 1] + a0[i];

        acc2[0] = a2[0];
        fore(i,1,n)
            acc2[i] = acc2[i - 1] + a2[i];
        bool flag = 1;

        
        int x;
        cin >> x;
        
        if(x != v[0])
            flag = 0;
        fore(i,1,n){
            cin >> x;
            if(x == v[i])
                continue;
            if(x > v[i]){
                if(!acc1[i - 1]){
                    flag = 0;
                }
            }else{
                if(!acc2[i - 1]){
                    flag = 0;
                }
            }
        }
        cout << (flag ? "YES":"NO" ) << '\n';
    }
    return 0;
}   
