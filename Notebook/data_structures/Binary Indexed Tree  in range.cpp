#include <bits/stdc++.h>
using namespace std;
struct Fenwick{
	int n;
	vector<long long> bit1, bit2;
	Fenwick(int n){
		this -> n = n;
		bit1.assign(n + 2, 0);
		bit2.assign(n + 2, 0);
	}

	int lsb(int i){return i&(-i);}

	void point_update(vector<long long> &b, int pos, int x){
		for(int i = pos; i <= n; i += lsb(i)){
			b[i] += x;
		}
	}

	void range_update(int l, int r, int x){
		point_update(bit1, l, x);
		point_update(bit1, r + 1, -x);
		point_update(bit2, l, x * (l - 1));
		point_update(bit2, r + 1, - x * r);
	}

	long long point_query(vector<long long> &b, int pos){
		long long ans = 0;
		for(int i = pos; i >= 1; i -= lsb(i))
			ans += b[i];

		return ans;
	}

	long long sum(long long pos){
		return point_query(bit1, pos) * pos - point_query(bit2, pos);
	}
	long long range_query(int l, int r){
		return sum(r) - sum(l - 1);
	}

};
int main(){


	return 0;
}
