#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<long long,long long>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int main(){
	ll n;
	cin >> n;
	if(n == 2){
		cout << "1\n1 1\n";
	}else if(n == 3){
		cout << "0\n1 3\n";
	}else if(n == 4){
		cout << "0\n2 1 4\n";
	}else if(n == 5){
		cout << "1\n2 3 5\n";
	}else {
	if((n * (n + 1) >> 1) & 1)
		cout << "1\n";
	else
		cout << "0\n";
	
	ll aux = n * (n + 1) / 2 / 2;
	vector<int> arr;
	arr.pb(n);
	aux -= n;
	int num = n - 1;
	while(aux > 0){
		if(aux - num >= 0){
			arr.pb(num);
			aux -= num;
		}
		num--;
	}
	cout << sz(arr) << ' ';
	for(auto i :arr)
		cout << i << ' ';
	cout << '\n';
	}
	return 0;
}
    
