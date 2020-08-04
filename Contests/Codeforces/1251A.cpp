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
int v[N],w[N];
int main(){
	fast;
	int t;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		bool flag = 1;
		set<char> st;
		if(s.size() == 1){
			cout << s[0] << '\n';
			continue;
		}
		for(int i = 0; i < s.size(); i++){
			int cont = 1,j = i + 1;
			while(j < s.size() && s[i] == s[j++])
				cont++,i++;
			if((cont & 1))
				st.insert(s[i]);
		}
		for(auto i = st.begin(); i != st.end(); i++)
			cout << *i;

		cout << "\n";
	}
	return 0;	
}
