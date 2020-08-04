#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, char> pc;
typedef vector<pc> vic;
int t, n;
string a, b;
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a>>b;
        vic dates;
        if(a!=b){
            for(int i=0; i<n; i++){
                if(a[i]!=b[i]) dates.push_back(make_pair(i, b[i]));
            }
            string aux=b;
            for(int i=1; i<dates.size(); i++){
                aux[dates[i].first]=dates[i-1].second;
                //cout<<dates[i].first<<" "<<dates[i].second<<endl;
            }
            aux[dates[0].first]=dates[dates.size()-1].second;
            if(aux==a) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }

    return 0;
}
