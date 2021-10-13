#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e2+10;
int GCD(int  a,int b){
	if(b==0)return a;
	return GCD(b,a%b);
}
int LCM(int a,int b){
	return a*b/GCD(a,b);
}
int mod=1000000007;
int v[51];
int main(){
	int n;
	cin>>n;
	v[0]=15;v[1]=10;v[2]=6;
	int c=2;
	for(int i=3;i<51;i++){
		v[i]=6*c;
		c++;
	}
	int ans=0;
	if(n==2){
		cout<<"-1\n";
		return 0;
	}
	for(int i=0;i<n;i++)
		cout<<v[i]<<"\n";
	return 0;
}
