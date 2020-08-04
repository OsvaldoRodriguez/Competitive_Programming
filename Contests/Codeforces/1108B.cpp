#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i++)
#define forr(i,a) for(int i = a; i >= 0; i--)
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
int v[N],n;
void f(int x){
	fore(i,0,n){
		if(v[i] == x){
			v[i] = -1;
			return;
		}
	}
}
int main(){
	fast;
	cin >> n;
	fore(i,0,n)
		cin >> v[i];
	sort(v, v + n);
	int x = v[n - 1];
	int i = 1;
	for(; i * i < x; i++){
		if(x % i == 0){
			f(i);
			f(x / i);
		}
	}
	if(i * i == x)
		f(i);
	int y = 0;
	forr(i,n - 1){
		if(v[i] != -1){
			y = v[i];
			break;
		}
	}
	cout << x << " " << y << "\n";	
	return 0;	
}
