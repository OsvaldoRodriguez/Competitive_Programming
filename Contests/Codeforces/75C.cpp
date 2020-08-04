#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int GCD(int a,int b){
	if(b==0)return a;
	return GCD(b,a%b);
}
vector<int> v;
int main(){
	int a,b,q,x,y;
	scanf("%d%d%d",&a,&b,&q);
	int gcd=GCD(a,b);
	int i=1;
	for(;i*i < gcd; i++){
		if(gcd%i==0){
			v.push_back(i);
			v.push_back(gcd/i);
		}
	}
	if(i*i==gcd)
		v.push_back(i);
	sort(v.begin(),v.end());
	while(q--){
		bool flag = 0;
		scanf("%d%d",&x,&y);
		for(int i = v.size()-1; i >= 0; i--){
			if(v[i]>=x && v[i]<=y){
				printf("%d\n",v[i] );
				flag=1;
				break;
			}
		}
		if(!flag)printf("-1\n");

	}
	return 0;
}
