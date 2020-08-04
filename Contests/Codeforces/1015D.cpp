#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<long long,long long>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b,inc) for(int i = a;i < b; i+= inc)
#define forr(i,a) for(int i = a; i >= 0; i--)
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
int main(){
	fast;
	ll n,k,s;
	cin >> n >> k >> s;
	if((n - 1) * k < s or k > s)
		cout << "NO\n";
	else{
		cout << "YES\n";
			ll div = s / k;
			ll mod  = s % k;
			if(!mod){
				fore(i,0,k,1){
				if((i & 1))
					cout << 1; 
				else
					cout << s / k + 1;
				cout << ' ';
				}
			}else{
				ll tmp = (div + 1);
				ll diff = tmp * k - s;
				diff = abs(k - diff);
				fore(i,0,diff,1){
					if((i & 1))
						cout << 1;
					else
						cout << tmp + 1;
					cout << ' ';
				}
				ll aux;
				if((diff & 1)){
					diff = abs(k - diff);
					aux = abs(tmp + 1 - div);
					fore(i,0,diff,1){
						if(!(i & 1))
							cout << aux;
						else cout << tmp + 1;
						cout << " ";
					}
				}
				else{
					diff = abs(k - diff);
					aux = div + 1;
					fore(i,0,diff,1){
						if(!(i & 1))
							cout << div + 1;
						else cout << 1;
						cout << " ";
					}
				}
				
				
				
			}
		
	}
	return 0;	
}
