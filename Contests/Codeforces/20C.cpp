#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
vector<ii> G[100001];
vi dis(100001,1000000000000000000);
ll P[100001];

void Dijkstra1(ll nodo)
{
    set<ii> q;
    dis[nodo]=0;
    q.insert(ii(0,nodo));
    while(!q.empty())
    {
        ii top=*q.begin();
        q.erase(q.begin());
        ll u=top.second;
        ll d=top.first;
        for(int i=0;i<G[u].size();i++)
        {
            ll v=G[u][i].first;
            ll cost=G[u][i].second;
            if(dis[u]+cost<dis[v])
            {
                dis[v]=dis[u]+cost;
                P[v]=u;///reconstruir el camino
                q.insert(ii(dis[v],v));

            }

        }

    }
}

int main()
{

    ll n,m,a,b,p;
    stack<ll> s;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        G[i].clear();

    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>p;
        G[a].push_back(make_pair(b,p));
        G[b].push_back(make_pair(a,p));
    }
    for(int i=0;i<100001;i++)
        P[i]=i;
    Dijkstra1(1);
    ll i=n;
    if(P[n]!=n)
    {
        s.push(n);
        while(i!=1)
        {
            s.push(P[i]);
            i=P[i];
        }

        cout<<s.top();s.pop();
        while(!s.empty())
        {
            cout<<" "<<s.top();
            s.pop();
        }
    }
    else
        cout<<-1<<'\n';

    return 0;
}
