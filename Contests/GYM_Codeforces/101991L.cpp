        #include <bits/stdc++.h>
        typedef long long ll;
        using namespace std;
        const int N = 1e5 + 5;
        ll v[N];
		
    	int main(){
            freopen("looking.in","r",stdin);
        	
        	int t;
        	scanf("%d",&t);
        	while(t--){
        		int n,k;
        		scanf("%d %d",&n,&k);
        		for(int i = 0; i < n; i++){
	        		scanf("%lld",v + i);
        		}
        		ll ans = 0;
        		int c = 0;
        		for(ll i = 0; i < 21; i++){
        			for(int j = 0; j < n; j++){
        				if((v[j] & (1LL << i))){
        					ans |= (1LL << i);
        					c++;
        				}
        			
        			}
        		}
        		printf("%lld\n",ans);
        	
        	}
        }
