  #include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define	cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 1 * 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int v[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,s;
		scanf("%d%d",&n,&s);
		int sum = 0;
		fore(i,0,n){
			scanf("%d",&v[i]);
			sum += v[i];
		}
		
		sum = 0;
		int ans = -1;
		int tmp = 0;
		bool flag = 0;
		if(n == 1 && v[0] > s)
			ans = 1;
		else{ fore(i,0,n){
			sum += v[i];
			tmp = max(tmp,v[i]);
			if(sum > s){
				flag = 1;
				break;
			}
		}
		if(flag)
		fore(i,0,n){
			if(v[i] == tmp && flag){
				ans = i + 1;
				break;
			}
		}
	}
		if(ans == -1)
			ans = 0;
		printf("%d\n",ans);
	
	}
	return 0;
}
