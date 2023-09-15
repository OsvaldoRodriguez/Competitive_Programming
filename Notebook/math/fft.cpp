#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

// MAXN must be power of 2 !!
// MOD-1 needs to be a multiple of MAXN !!
// big mod and primitive root for NTT:

//FTT
// ******************************************************************
// typedef ll tf;
// typedef vector<tf> poly;
// const tf MOD = 2305843009255636993, RT = 5, MAXN = (1 << 16);
// ******************************************************************
//NTT
// ******************************************************************
typedef int tf;
typedef vector<tf> poly;
// MAXN should be of lengh of polynomial but it should be a  power of two => 2^k >= MAXN
const tf MOD = 998244353, RT = 3, MAXN = (1 << 22);
// ******************************************************************
tf addmod(tf a, tf b){tf r = a + b; if(r >= MOD)r -= MOD; return r;}
tf submod(tf a, tf b){tf r = a - b; if(r < 0)r += MOD;return r;}
tf mulmod(ll a, ll b){return a * b % MOD;}
tf pm(ll a, ll b){
    ll r = 1;
    while(b){
        if(b & 1) r = mulmod(r, a); b >>= 1;
        a = mulmod(a, a);
    }
    return r;
}
tf inv(tf a){return pm(a, MOD - 2);}
// FFT
// **********************************************************
// struct CD {
//     double r,i;
//     CD(double r = 0, double i = 0):r(r), i(i){}
//     double real() const {return r;}
//     void operator /= (const int c){r /= c, i /= c;}
// };
// CD operator * (const CD& a, const CD& b){
//     return CD(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);}
// CD operator + (const CD& a, const CD& b){return CD(a.r + b.r, a.i + b.i);}
// CD operator - (const CD& a, const CD& b){return CD(a.r - b.r,a.i - b.i);}
// **********************************************************
// NTT
// *******************************************************
struct CD {
    tf x;
    CD(tf x) : x(x){}
    CD(){}
};
CD operator * (const CD& a, const CD& b){return CD(mulmod(a.x, b.x));}
CD operator + (const CD& a, const CD& b){return CD(addmod(a.x, b.x));}
CD operator - (const CD& a, const CD& b){return CD(submod(a.x, b.x));}
// *******************************************************

const double pi = acos(-1.0);
vector<tf> rts(MAXN + 9, -1);
CD root(int n, bool inv){
    tf r = rts[n] < 0 ? rts[n] = pm(RT, (MOD - 1) / n) : rts[n];
    return CD(inv ? pm(r, MOD - 2) : r);
}
CD cp1[MAXN + 9],cp2[MAXN + 9];

int R[MAXN + 9];
void dft(CD* a, int n, bool inv){
    for(int i = 0; i < n; i++)
        if(R[i] < i) swap(a[R[i]], a[i]);
    for(int m = 2; m <= n; m *= 2){
        // double z = 2 * pi / m * (inv ? -1 : 1); // FFT
        // CD wi = CD(cos(z), sin(z)); // FFT
        CD wi = root(m, inv); // NTT
        for(int j = 0;j < n;j += m){
            CD w(1);
            for(int k = j, k2 = j + m / 2; k2 < j + m;k++, k2++){
                CD u = a[k]; CD v = a[k2] * w; a[k] = u + v; a[k2] = u - v; w=w * wi;
            }
        }
    }
    // if(inv) for(int i = 0; i < n; i++) a[i] /= n; // FFT
    if(inv){ // NTT
        CD z(pm(n, MOD - 2)); // pm: modular exponentiation
        for(int i = 0; i < n; i++)
            a[i] = a[i] * z;
    }
}
poly multiply(poly& p1, poly& p2){
    int n = p1.size() + p2.size() + 1;
    int m = 1,cnt = 0;
    while(m <= n)m += m, cnt++;
    for(int i = 0; i < m; i++){
        R[i] = 0;
        for(int j = 0; j < cnt; j++)
            R[i] = (R[i] << 1) | ((i >> j) & 1);
    }

    for(int i = 0; i < m; i++) cp1[i] = 0, cp2[i] = 0;
    for(int i = 0; i < p1.size(); i++) cp1[i] = p1[i];
    for(int i = 0; i < p2.size(); i++) cp2[i] = p2[i];
    dft(cp1, m, false); dft(cp2, m, false);
    for(int i = 0; i < m; i++) cp1[i] = cp1[i] * cp2[i];
    dft(cp1, m, true);
    poly res;
    n -= 2;
    // for(int i = 0; i < n; i++) res.push_back((tf)floor(cp1[i].real() + 0.5)); // FFT
    for(int i = 0; i < n; i++) res.push_back(cp1[i].x); // NTT
    return res;
}

//Polynomial division: O(n*log(n))
//Multi-point polynomial evaluation: O(n*log^2(n))
//Polynomial interpolation: O(n*log^2(n))

//Works with NTT. For FFT, just replace addmod,submod,mulmod,inv
poly add(poly &a, poly &b){
    int n = a.size(), m = b.size();
    poly ans(max(n, m));
    for(int i = 0; i < max(n, m); i++){
        if(i < n) ans[i] = addmod(ans[i], a[i]);
        if(i < m) ans[i] = addmod(ans[i], b[i]); 
    }
    while(ans.size() > 1 && !ans.back()) ans.pop_back();
    return ans;
}

poly invert(poly &b, int d){
    poly c = {inv(b[0])};
    while((int)c.size() <= d){
        int j = 2 * (int)c.size();
        auto bb = b; bb.resize(j);
        poly cb = multiply(c, bb);
        for(int i = 0; i < (int)cb.size(); i++) cb[i] = submod(0, cb[i]);
        cb[0] = addmod(cb[0], 2);
        c = multiply(c, cb);
        c.resize(j);
    }
    c.resize(d + 1);
    return c;
}

pair<poly,poly> divslow(poly &a, poly &b){
    poly q,r = a;
    while(r.size() >= b.size()){
        q.push_back(mulmod(r.back(), inv(b.back())));
        if(q.back()) 
            for(int i = 0; i < b.size(); i++){
                r[r.size() - i - 1] = submod(r[r.size() - i - 1], mulmod(q.back(), b[b.size() - i - 1]));
        }
        r.pop_back();
    }
    reverse(q.begin(), q.end());
    return {q, r};
}

pair<poly,poly> divide(poly &a, poly &b){   //returns {quotient,remainder}
    int m = a.size() ,n = b.size() ,MAGIC = 750;
    if(m < n) return {{0}, a};
    if(min(m - n, n) < MAGIC) return divslow(a, b);
    poly ap = a; reverse(ap.begin(), ap.end());
    poly bp = b; reverse(bp.begin(), bp.end());
    bp = invert(bp, m - n);
    poly q = multiply(ap, bp);
    q.resize(q.size() + m - n - q.size() + 1, 0);
    reverse(q.begin(), q.end());
    poly bq = multiply(b, q);
    for(int i = 0; i < bq.size(); i++) bq[i] = submod(0, bq[i]);
    poly r = add(a, bq);
    return {q, r};
}

vector<poly> tree;

void filltree(vector<tf> &x){
    int k = x.size();
    tree.resize(2 * k);
    for(int i = k; i < 2 * k; i++) tree[i] = {submod(0, x[i - k]), 1};
    for(int i = k-1; i; i--) tree[i] = multiply(tree[2 * i],tree[2 * i + 1]);
}

vector<tf> evaluate(poly &a, vector<tf> &x){
    filltree(x);
    int k = x.size();
    vector<poly> ans(2 * k);
    ans[1] = divide(a, tree[1]).second;
    for(int i = 2; i < 2 * k; i++) ans[i] = divide(ans[i >> 1], tree[i]).second;
    vector<tf> r; 
    for(int i = 0; i < k; i++) r.push_back(ans[i + k][0]);
    return r;
}

poly derivate(poly &p){
    poly ans(p.size() - 1);
    for(int i = 1; i < p.size(); i++) ans[i - 1] = mulmod(p[i], i);
    return ans;
}

poly interpolate(vector<tf> &x, vector<tf> &y){
    filltree(x);
    poly p = derivate(tree[1]);
    int k = y.size();
    vector<tf> d = evaluate(p, x);
    vector<poly> intree(2 * k);
    for(int i = k; i < 2 * k; i++) intree[i] = {mulmod(y[i - k], inv(d[i - k]))};
    for(int i = k-1; i; i--){
        poly p1 = multiply(tree[2 * i], intree[2 * i + 1]);
        poly p2 = multiply(tree[2 * i + 1], intree[2 * i]);
        intree[i] = add(p1, p2);
    }
    return intree[1];
}

int main(){
    //fast io

    int degree_a, degree_b;
    cin >> degree_a >> degree_b;
    poly A(degree_a);
    poly B(degree_b);
    for(auto &i : A) cin >> i;
    for(auto &i : B) cin >> i;
    poly answer = multiply(A, B);
    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    cout << "\n";
}
