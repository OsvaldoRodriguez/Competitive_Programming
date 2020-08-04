#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long ll;
const int N = 1e2 + 5;
int v[N];
int main(){
	int t,n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d",&v[i]);
		sort(v,v + n);
		v[n] = 0;
		n++;
		bool flag = 0;
		int s = 0, i = 0, j = 0;
		while(1){
			//printf("%d s %d %d\n",s,i,j);
			if(s == 2048){
				flag = 1;
				break;
			}
			if(i > n - 1 or j > n - 1 or i > j)
				break;
			if(s < 2048)
				if(j < n)
					s += v[j++];
			if(s == 2048){
				flag = 1;
				break;
			}
			if(s > 2048)
				if(i < n)
					s -= v[i++];
		}
		printf(flag?"YES\n":"NO\n");
	}
	return 0;
}
    
