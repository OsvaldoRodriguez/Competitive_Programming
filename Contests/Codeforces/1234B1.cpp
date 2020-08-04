#include <bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long ll;
const int N = 104;
set<int> s;
queue<int> q;
stack<int> st;
int main(){
	int n,k,x;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> x;
		if(!s.count(x)){
			s.insert(x);
			if((int)q.size() + 1> k){
				s.erase(q.front());
				q.pop();
			}
			q.push(x);
		}
	}
	cout << q.size() << '\n';
	while(!q.empty()){
		st.push(q.front());
		q.pop();
	}
	while(!st.empty()){
		cout << st.top() << ' ';
		st.pop();
	}
	return 0;
}
