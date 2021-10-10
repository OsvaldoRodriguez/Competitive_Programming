// test problem uva 12100

// source 
// https://github.com/OsvaldoRodriguez/Competitive_Programming/blob/master/Contests/Uva/12100%20Queue%20implemented.cpp


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
#define FI          freopen("input.txt", "r", stdin)
#define FO          freopen("output.txt", "w", stdout)
#define EjecuteTime cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define angle(x)    double(x * acos(-1) / 180.0)
using namespace std;
typedef unsigned long long   ll;
typedef vector<int> vi;
typedef vector<ii>  vii;
const int N = 1e2 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)

struct Node{
    int first, second;
    Node* next;
    // Node(): value(0), next(nullptr){}
    Node(int x, int y): second(y), first(x), next(nullptr){}
    
    Node(Node *A){
        first = A -> first;
        second  = A -> second;
        next = A -> next;
    }

    void mostrar(){
        cout << "(" << first << ", " << second << ")";
    }
};

struct Queue{
    Node *head;
    Node *end;
    int len;
    Queue(): len(0), head(nullptr), end(nullptr){}

    bool empty(){ // O (1)
        return head == nullptr;
    }

    int size(){ // O(1)
        return len;
    }

    Node front(){
        return *head;
    }

    Node back(){
        return *end;
    }
    // puntero Node
    void push(Node *x){ // O(1)
        if(empty()){
            head = new Node(x);
            end = head;
        }else{
            Node* tmp = new Node(x);
            end -> next = tmp;
            end = tmp;
        }
        
        len++;
    }


    void pop(){
        if(not empty()){
            Node* currentNode = head;
            head = currentNode -> next;
            len--;
        }
    }
    void print(){  // O(n)
        Node* currentNode = head;
        while(currentNode != nullptr){
            Node tmp = *currentNode;
            tmp.mostrar();
            currentNode = currentNode -> next;
        }
        cout << '\n';
    }

    
    
};
void solve(){
    int n, pos;
    cin >> n >> pos;
    Queue *Q = new  Queue();
    priority_queue<int> p;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        Q -> push(new Node(x, (i == pos)));
        p.push(x);
    }
    int time = 0;
    while(Q -> size() > 0){
        Node aux = Q -> front();
        int mx = p.top();
        if(aux.F < mx){
            Q -> pop();
            Q -> push(&aux);
        }else{
            time++;
            if(aux.S == 1){
                break;
            }
            Q -> pop();
            p.pop();
        }
    }
    cout << time << '\n';

}
int main(){
    FIN;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    EjecuteTime;
    return 0;
}       
