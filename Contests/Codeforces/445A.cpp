#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char  b[n+1][m+1];
    char  a[n+1][m+1];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>b[i][j];

    bool sw=true;
      for(int i=1;i<=n;i++)
      {
          if(m%2==0 &&i%2==0)
          {
             for(int j=m;j>=1;j--)
            {
                if(sw)
                {
                    a[i][j]='B';
                    sw=false;
                }
                else
                {
                    a[i][j]='W';
                    sw=true;
                }
            }
          }
          else
          {
              for(int j=1;j<=m;j++)
                {
                    if(sw)
                    {
                        a[i][j]='B';
                        sw=false;
                    }
                    else
                    {
                        a[i][j]='W';
                        sw=true;
                    }
                }
          }

      }

      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
                {
                    if(b[i][j]=='-')
                        cout<<'-';
                    else
                        cout<<a[i][j];
                }
            cout<<endl;
      }



return 0;
}
