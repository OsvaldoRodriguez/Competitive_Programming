struct nodo{
    ll u, num, den;
    nodo(ll uu, ll fa, ll fb){
        u = uu;
        num = fa;
        den = fb;
    }
    // en este caso como es heap max (se sobrecarga al revez)
    bool operator < (const nodo f) const {
        if(u == f.u)
            return num * f.den < den * f.num;
        return u < f.u;
    }
};

struct nodoComparator{
    bool operator() (const nodo a, const nodo b) const{
        if(a.u == b.u)
            return a.num * b.den > a.den * b.num;
        return a.u > b.u;
    } 
};

void solve(){
    vector<nodo> a;
    priority_queue<nodo, vector<nodo>, nodoComparator> q;
    q.push(nodo(10, 1, 2));
    q.push(nodo(1, 1, 3));
    q.push(nodo(10, 20, 3));
    q.push(nodo(2, 3, 3));
    q.push(nodo(3, 100, 3));
    q.push(nodo(1, 1, 5));

    while(q.size()){
        nodo a = q.top(); q.pop();
        cout << a.u << " " << a.num << " " << a.den << " " << (double)a.num / (double)a.den << "\n";
    }

    
}
