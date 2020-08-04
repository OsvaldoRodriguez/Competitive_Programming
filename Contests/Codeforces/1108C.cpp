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
int main(){
	fast;
	int n;
	set<string> cmp;
	cmp.insert("BGR");
	cmp.insert("BRG");
	cmp.insert("GRB");
	cmp.insert("GBR");
	cmp.insert("RGB");
	cmp.insert("RBG");
	string  s,aux = "";
	cin >> n >> s;
	int men = (1<<30);
	string ans = "";
	for(auto i = cmp.begin(); i != cmp.end(); i++){
		string  aux = *i;
		int cont = 0;
		fore(j,0,s.size())
			if(aux[j % 3] != s[j])
				cont++;
		if(men > cont){
			men = cont;
			ans = aux;
		}
	}
	cout << men << "\n";
	fore(i,0,n)
	cout << ans[i % 3];
	return 0;	
}
