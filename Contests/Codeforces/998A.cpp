#include "bits/stdc++.h"
using namespace std;
vector<int> v1;
int main()
{
  int n,s=0;
  cin>>n;
  int v[n];
  for (int i = 0; i < n; i++) {
    cin>>v[i];
    s+=v[i];
  }
  //cout<<s<<" to\n";
  if(n==1)
    cout<<-1<<"\n";
  else
  {
    if(n==2 and v[0]==v[1])
      cout<<-1<<"\n";
    else
    {
      int ans=0;
      for(int i=1;i<(1<<n);i++)
      {
        ans=0;
        v1.clear();
        for(int j=0;j<n;j++)
        {
          if(i&(1<<j))
          {
            ans+=v[j];
            v1.push_back(j);
          }

        }
        if(ans!=s-ans)
          break;
      }
      cout<<v1.size()<<endl;
      for(int i=0;i<v1.size();i++)
        cout<<v1[i]+1<<" ";
    }


  }
  return 0;
}
