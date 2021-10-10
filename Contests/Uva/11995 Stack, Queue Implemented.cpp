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
const int N = 1e3 + 5;
const ll mod = 1e9 + 7;
const double E = 1e-9;
//int dx[] = {0, -1}, dy[] = {-1, 0};
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)

struct NodeQ{
    int first;
    NodeQ* next;
    NodeQ(): first(0), next(nullptr){}
    NodeQ(int x): first(x), next(nullptr){}
    
    NodeQ(NodeQ *A){
        first = A -> first;
        next = A -> next;
    }

    void mostrar(){
        cout << "(" << first  << ")";
    }
};

struct Queue{
    NodeQ *head;
    NodeQ *end;
    int len;
    Queue(): len(0), head(nullptr), end(nullptr){}

    bool empty(){ // O (1)
        return head == nullptr;
    }

    int size(){ // O(1)
        return len;
    }

    NodeQ front(){
        return *head;
    }

    NodeQ back(){
        return *end;
    }
    // puntero Node
    void push(NodeQ *x){ // O(1)
        if(empty()){
            head = new NodeQ(x);
            end = head;
        }else{
            NodeQ* tmp = new NodeQ(x);
            end -> next = tmp;
            end = tmp;
        }
        
        len++;
    }


    void pop(){
        if(not empty()){
            NodeQ* currentNode = head;
            head = currentNode -> next;
            len--;
        }
    }
    void print(){  // O(n)
        NodeQ* currentNode = head;
        while(currentNode != nullptr){
            NodeQ tmp = *currentNode;
            tmp.mostrar();
            currentNode = currentNode -> next;
        }
        cout << '\n';
    }

    
    
};

struct Node{
    int first;
    Node* next;
    Node* last;
    Node(): first(0), next(nullptr), last(nullptr){}
    Node(int x): first(x), next(nullptr), last(nullptr){}
    
    Node(Node *A){
        first = A -> first;
        next = A -> next;
        last = A -> last;
    }

    void mostrar(){
        cout << "(" << first  << ")";
    }
};

struct Stack{
    Node *head;
    Node *end;
    int len;
    Stack(): len(0), head(nullptr), end(nullptr){}

    bool empty(){ // O (1)
        return head == nullptr;
    }

    int size(){ // O(1)
        return len;
    }

    Node top(){
        return *end;
    }

    // puntero Node
    void push(Node *x){ // O(1)
        if(empty()){
            head = new Node(x);
            x -> last = head;
            end = head;
        }else{
            Node* tmp = new Node(x);
            end -> next = tmp;
            tmp -> last = end;
            end = tmp;
        }
        
        len++;
    }


    void pop(){
        if(not empty()){
            if(size() == 1){
                head = end = nullptr;
            }else{
                Node* toDelete = end;
                Node* currentNode = end -> last;
                currentNode -> next = nullptr;
                end = end -> last;
                delete toDelete;
            }
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
    int n;
    while(cin >> n){
        bool fq = 1, fs = 1, fpq = 1;
        Queue *Q = new Queue();
        Stack *S = new Stack();
        priority_queue<int> pq;
        int ope, val;
        while(n--){
            cin >> ope >> val;
            if(ope == 1){
                Q -> push(new NodeQ(val));
                S -> push(new Node(val));
                pq.push(val);
            }else{
                if(Q -> size()){
                    if(Q -> front().first != val)
                        fq = 0;
                    Q -> pop();
                }else fq = 0;
                
                if(S -> size()){
                    if(S -> top().first != val)
                        fs = 0;
                    S -> pop();
                }else fs = 0;

                if(sz(pq)){
                    if(pq.top() != val)
                        fpq = 0;
                    pq.pop();
                }else fpq = 0;
            }
        }
        if(!fq && !fs && !fpq)
            cout << "impossible\n";
        else if(fq && !fs && !fpq)
            cout << "queue\n";
        else if(!fq && fs && !fpq)
            cout << "stack\n";
        else if(!fq && !fs && fpq)
            cout << "priority queue\n";
        else
            cout << "not sure\n";
    }

}
int main(){
    FIN;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    EjecuteTime;
    return 0;
}       
