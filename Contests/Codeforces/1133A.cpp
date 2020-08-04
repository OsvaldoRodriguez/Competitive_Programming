#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
const int mod = 1e9 + 7;
const ll MAX = (1LL << 32) - 1;
int main(){
	fast;
	string a,b;
	cin >> a >> b;
	int hh1 = (a[0] - '0') * 10 + a[1] - '0';
	int mm1 = (a[3] - '0') * 10 + a[4] - '0';

	int hh2 = (b[0] - '0') * 10 + b[1] - '0';
	int mm2 = (b[3] - '0') * 10 + b[4] - '0';

	int dmn = 0;
	int cmm1 = mm1;
	int aux = 0;
	while(cmm1 != mm2){
		dmn++;
		cmm1++;
		if(cmm1 == 60){
			cmm1 = 0;
			aux++;
		}
	}
	int dh = 0;
	int chh1 = hh1;
	while(chh1 != hh2){
		dh++;
		chh1++;
		if(chh1 == 24)
			chh1 = 0;
	}
	dh -= aux;
	int mn = dh * 60 + dmn;
	mn >>= 1;
	mm1 += hh1 * 60 + mn;
	printf("%02d:%02d\n",mm1 / 60,mm1 % 60);
	return 0;	
}
