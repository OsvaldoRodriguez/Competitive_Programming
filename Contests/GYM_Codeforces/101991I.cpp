        #include <bits/stdc++.h>
        typedef long long ll;
        using namespace std;
        const int N = 1e5 + 5;
        vector<pair<ll,ll> > v;
		
    	int main(){
            freopen("icecream.in","r",stdin);
        	
        	int t;
        	scanf("%d",&t);
        	while(t--){
        		v.clear();
        		int n,k;
        		scanf("%d %d",&n,&k);
        		for(int i = 0; i < n; i++){
        			ll x;
        			scanf("%lld",&x);
        			v.push_back({x,0LL});
        		}
        		
        		for(int i = 0; i < n; i++){
        			ll x;
        			scanf("%lld",&x);
        			v[i].second = -x;
        		}
        		
        		
        		sort(v.begin(),v.end());
        		for(int i = 0; i < n; i++)
        			v[i].second *= -1;
        	
        		
        		ll ans = v[k - 1].first;
        		ll happy = 0;
        		vector<int> auxi;
        		auxi.clear();
        		for(int i = 0; i < k; i++){
        			auxi.push_back(v[i].second);
        			//printf("%lld adi\n",v[i].second);
        			
        		}
        		for(int i = k; i < n; i++)
        			if(ans >= v[i].first){
        				auxi.push_back(v[i].second);
        					//printf("%lld adi sigue\n",v[i].second);
        			}
        			else break;
        		sort(auxi.rbegin(),auxi.rend());
        		for(int i = 0; i < k; i++){
        			//printf("%lld ",auxi[i]);
        			
        			happy += auxi[i];
        		}
        		//printf("\n");
        		printf("%lld %lld\n",ans,happy);
        		
        		
        	}
        }
