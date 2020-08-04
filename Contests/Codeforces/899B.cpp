#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<long long,long long>
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
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int month[] = {31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int month_1[] = {31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
int month_2[] = {31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	int n;
	scanf("%d",&n);
	int v[n + 1];
	fore(i,0,n){
		scanf("%d",v + i);
	}
	bool flag = 0;
	fore(i,0,24){
		bool sw = 1,sw_1 = 1,sw_2 = 1;;
		if(v[0] == month[i] or v[0] == month_1[i] or v[0] == month_2[i]){
			int k = i;
			int l = i;
			int m = i;
			fore(j,0,n){
				if(v[j] != month[k++]){
					sw = 0;
					break;
				}
			}

			fore(j,0,n){
				if(v[j] != month_1[l++]){
					sw_1 = 0;
					break;
				}
			}

			fore(j,0,n){
				if(v[j] != month_2[m++]){
					sw_2 = 0;
					break;
				}
			}

			if(sw or sw_1 or sw_2){
				flag = 1;
				break;
			}
		}

	}
	printf(flag?"YES\n":"NO\n");
	
	return 0;
}
    
