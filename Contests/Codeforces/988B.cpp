#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = INT_MAX;
bool f(const string& x,const string s){
	int j = 0;
	for(int i = 0; i < s.size(); i++){
		if(x[0] == s[i]){
			int k = i;
			j = 0;
			while(x[j] == s[i] && i < s.size() && j < x.size()){
				j++;i++;
			}
			if(j == x.size())
				return 1;
			else i = k;
		}
	}
	return 0;
}
bool cmp(string a,string b){return a.size() < b.size();}
int main(){
	fast;
	int n;
	string s;
	vector<string> v;
	cin >> n;
	while(n--){
		cin >> s;
		v.pb(s);
	}
	bool flag = 1;
	sort(all(v),cmp);
	string aux  = v[0];
	for(auto i = 1; i < v.size(); i++){
		if(!f(aux,v[i])){
			flag = 0;
			break;
		}
		aux = v[i];
	}
		
	if(flag){
		cout << "YES\n";
		for(auto i : v)
			cout << i << "\n";
	}else
	cout << "NO\n";

	return 0;	
}
