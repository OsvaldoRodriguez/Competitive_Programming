#include <iostream>
#define N 501
int n,m,x;
char v[N][N];int s[N][N];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
using namespace std;
int f(int a,int b)
{
    if(a<n && a>=0 && b<m && b>=0)
        return 1;
    return 0;
}
void dfs(int a,int b)
{
    if(x==0)
        return ;
    x--;
    s[a][b]=1;
    for(int i=0;i<4;i++)
    {
        int x1=a+dx[i],y1=b+dy[i];
        if(f(x1,y1))
        {
            if(v[x1][y1]=='.' && s[x1][y1]==0)
                dfs(x1,y1);
        }
    }

}
int main()
{
    cin>>n>>m>>x;
    int x1=-1,y1=-1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
            if(v[i][j]=='.')
                x1=i,y1=j,s[i][j]=0;
            else
                s[i][j]=1,x++;
        }

        x=(n*m)-x;
        dfs(x1,y1);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(s[i][j]==0)
                    cout<<"X";
                else
                    cout<<v[i][j];
            cout<<"\n";
        }

    return 0;
}
