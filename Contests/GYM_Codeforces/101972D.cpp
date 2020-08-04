#include <bits/stdc++.h>
using namespace std;
int main(){
    int casos; scanf("%d",&casos);
    while(casos --){
        int n,x,y; cin>>n>>x>>y;
        x>=((n/2)+1) && y>=(n/2)?cout<<"YES\n":cout<<"NO\n";
    }
	return 0;
}
