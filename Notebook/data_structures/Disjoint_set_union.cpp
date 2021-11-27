#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
typedef vector<int> vi;
const int N = 1e5 + 50;
class UnionFind{
    private:
        vi p,rank,size;
        int numSets,maxSubSet;
    public:
        UnionFind(int N){
            //index 0
            size.assign(N, 1);//tamaño del conjunto
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
