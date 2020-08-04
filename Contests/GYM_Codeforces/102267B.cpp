#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N =10000001;
vector<int>pr;
int v[N];
void criba(){
  v[0]=v[1]=1;
  for(int i=2;i<N;i++)
    if(!v[i]){
      pr.push_back(i);
      for(int j=i+i;j<N;j+=i)
        v[j]=1;
    }

}
int main()
{
  criba();
  int n;
  while(cin>>n){
    int a=0,b=pr.size(),m;
    while(b-a>1){
      m=(a+b)>>1;
      if(pr[m]<=n)
        a=m;
      else
        b=m;
    }
    b=a;
    a=0;
    bool flag=0;
    while(a!=b){
      if(pr[a]+pr[b]==n){
        cout<<pr[a]<<" "<<pr[b]<<endl;
        flag=1;
        break;
      }
      else if(pr[a]+pr[b]>n)
            b--;
          else
            a++;
    }
    if(!flag)
      cout<<-1<<endl;
  }
  return 0;
}
