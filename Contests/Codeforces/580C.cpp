#include <bits/stdc++.h>
using namespace std;
vector<int> G[100001];
int cat[100001];
set<int> s;
int n,m;
int dfs(int u,int cats)
{
    s.insert(u);
    if(cats>m)
        return 0;

        int ans=0;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!s.count(v))
        {
            if(cat[v]==0)
                ans+=dfs(v,0);
            else
                ans+=dfs(v,cats+cat[v]);
        }
    }

    if(G[u].size()==1 && u!=1)
        return 1;
    return ans;
}
int main()
{
    cin>>n>>m;
    int u,v;
    s.clear();
    for(int i=1;i<=n;i++)
        cin>>cat[i];

    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cout<<dfs(1,cat[1])<<endl;





    return 0;
}
