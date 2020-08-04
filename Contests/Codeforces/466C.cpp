  #include <bits/stdc++.h>
  using namespace std;
  typedef long long  ll;
  const  int N =1000020;
  ll v[N];
  ll cont[N];
  int n;
  ll  ways(){
    ll s=0;
    for(int i=0;i<n;i++)
      s+=v[i];
    if(s%3!=0)
      return 0;
    s/=3;
    ll ss=0;
    for(int i=n-1;i>=0;i--){
      ss+=v[i];
      if(ss==s)
        cont[i]=1;
    }
    for(int i=n-2;i>=0;i--)
      cont[i]+=cont[i+1];
    ss=0;
    ll ans=0;
    for(int i=0;i<n-2;i++){
      ss+=v[i];
      if(ss==s)
        ans+=cont[i+2];
    }
    return ans;
  }
  int main(){
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>v[i];
    cout<<ways()<<endl;
    return 0;
  }
