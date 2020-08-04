#include <bits/stdc++.h>
using namespace std;
int main(){
		int t,a,b,c,ans1,ans;
		scanf("%d",&t);
		while(t--){
			scanf("%d %d %d",&a,&b,&c);
			int par = min(b,c / 2);
			int aa = a, bb = b, cc = c;
			ans = par + par * 2;
			b -= par;
			par = min(a,b / 2);
			ans += par + par * 2;
			
			par = min(a,b / 2);
			ans1 = par + par * 2;
			b -= par * 2;
			par = min(b,c / 2);
			ans1 += par + par * 2;
			printf("%d\n",max(ans,ans1) );
		}
	return 0;
}
