#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 150005;
ll GCD(ll a,ll b){
	if(b==0)return a;
	return GCD(b,a%b);
}
ll LCM(ll a,ll b){
	return a*(b/GCD(a,b));
}
ll MIN(ll a,ll b){
	if(a<b)return a;
	return b;
}
int main(){
	ll n,a,b,p,q;
	cin>>n>>a>>b>>p>>q;
	ll ans = 0;
	ans+= (n/a)*p;
	ans+=(n/b)*q;
	ans-= MIN(p,q)*(n/LCM(a,b));
	cout<<ans<<"\n";
  	return 0;
}
