#include <bits/stdc++.h>
using namespace std;
const int N = 150005;
int v[N],sol[N];
int n;
void solucion(){
  stack<int> s;
  for(int i=n-1;i>=0;i--){
    while(!s.empty() && s.top()>=v[i])
      s.pop();
    if(s.empty()){
      sol[i]=-1;
    }
    else{
      sol[i]=s.top();
    }
    s.push(v[i]);
  }
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		    scanf("%d",&v[i]);
		solucion();
		int ans=0;
		for(int i=0;i<n;i++){
		  	if(sol[i]!=-1)
		  		ans++;
		}
		printf("%d\n",ans );
	}
  return 0;
}
