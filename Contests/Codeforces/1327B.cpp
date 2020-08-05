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
const ll mod = 1e9;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
bool us[N];
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		int aug = -1;
		int can = 0;
		cls(us,0);
		scanf("%d",&n);
		bool flag = 1;
		bool sw = 1;
		fore(i,0,n){
			int x;
			flag = 1;
			scanf("%d",&x);
			fore(j,0,x){
				int u;
				scanf("%d",&u);
				if(!flag)
					continue;
				if(us[u] == 0){
					us[u] = 1;
					flag = 0;
				}
			}
			if(flag && sw){
				can++;
				aug = i + 1;
				sw = 0;
			}
		}
		int i = 1;
		while(us[i] == 1)
			i++;
		if(can){
			printf("IMPROVE\n%d %d\n",aug,i);
		}else
			printf("OPTIMAL\n");
	}
	return 0;
}
    
