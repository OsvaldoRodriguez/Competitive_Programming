#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7+10;
int v[N];
int w[N],z1[N],acc[N];
int main(){
	for(int i=0;i<N;i++)
		v[i]=i;
	for(ll i=2;i*i<N;i++)
		if(v[i]==i)
			for(ll j=i*i;j<N;j+=i)
				if(v[j]==j)
					v[j]=i;
	int n,q,a1,b1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
		int y=w[i];
		int z=v[y];
		if(z>=0)
		z1[z]++;
		while(y!=1){
			if(z!=v[y]){
				z=v[y];
				if(z>=0)
				z1[z]++;
			}
			y/=v[y];
		}
	}
	for(int i=2;i<N;i++)
		acc[i]=acc[i-1]+z1[i];
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&a1,&b1);
		if(b1>10000000)
			b1=10000000;
		if(a1>N)
			printf("0\n");
		else
		printf("%d\n",acc[b1]-acc[a1-1]);


	}

  	return 0;
}
