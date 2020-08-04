#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  string s="10";
  while(cin>>n>>m){
  if(n>m+1){
    cout<<-1<<"\n";
    continue;
  }
  if(m-n==1){
    for(int i=0;i<n+m;i++)
      cout<<s[i%2];
    cout<<"\n";
    continue;
  }
  if(n-m==1){
    for(int i=1;i<n+m+1;i++)
      cout<<s[i%2];
      cout<<"\n";
      continue;
  }
  if(n==m){
    for(int i=1;i<=(n+m)>>1;i++)
      cout<<s;
      cout<<"\n";
      continue;
  }
  if(2*n+2>=m){
    //cout<<" CASe\n";
    int cn=n,cm=m;
    int flag=0;
    while(cn!=cm){
      if(cm>cn && !flag){
        cout<<"11";
        cm-=2;
        flag=1;
      }
      else{
        cout<<"0";
        cn--;
        flag=0;
      }
    }
    if(flag){
      for(int i=1;i<=cn+cm;i++)
        cout<<s[i%2];
    }
    else
      for(int i=0;i<cn+cm;i++)
        cout<<s[i%2];
      cout<<"\n";
      continue;
  }
  else
    cout<<-1;
  cout<<"\n";
}
  return 0;
}
