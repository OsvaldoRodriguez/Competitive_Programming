#include <bits/stdc++.h>
#define FIN         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii          pair<int,int>
#define F           first
#define S           second
#define pb          push_back
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a)   for(int i = a; i >= 0; i--)
#define fori(i,m)   for(auto i = m.begin(); i != m.end(); i++) 
#define w(t)        while(t--)
#define sz(s)       int(s.size())
#define cls(a,car)  memset(a,car,sizeof (a))
#define db(x)       cerr << #x << " is " << x << '\n'
#define FL          freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;
const double E = 1e-9;
class UnionFind{
    private:
        vi p,rank,size;
        int numSets,maxSubSet;
    public:
        UnionFind(int N){
            //index 0
            size.assign(N,1);//tamaño del conjunto
            numSets = N;
            maxSubSet = 1;
            rank.assign(N,0);
            p.assign(N,0);
            for(int i = 0; i < N; i++)
                p[i] = i;
        }
    int findSet(int i){
        return (p[i] == i) ? i : p[i] = findSet(p[i]);
    }
    bool isSameSet(int i,int j){return findSet(i) == findSet(j);}
    void unionSet(int i,int j){
        int x = findSet(i);
        int y = findSet(j);
        if(x != y){
            numSets--;
            if(rank[x] > rank[y]){
                p[y] = x;
                size[x] += size[y];
                maxSubSet = max(size[x],maxSubSet);
            }else{
                p[x] = y;
                size[y] += size[x];
                if(rank[x] == rank[y])
                    rank[y]++;
                maxSubSet = max(size[y],maxSubSet);
            }
        }
    }
    int numDisjointSets(){
        return numSets;
    }
    int sizeOfSet(int i){
        return size[findSet(i)];
    }
    int getmaxSubSet(){
        return maxSubSet;
    }
};

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m), n && m){
        UnionFind U(n);
        while(m--){
            int u,v;
            scanf("%d %d",&u,&v);
            U.unionSet(u,v);
        }
        printf("Existen %d posibles razas\n",U.numDisjointSets());
        printf("La raza que tiene mas ovejas tiene %d\n",U.getmaxSubSet());
    }
    return 0;
}   