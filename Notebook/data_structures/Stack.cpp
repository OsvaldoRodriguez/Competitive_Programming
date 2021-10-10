#include <bits/stdc++.h>

using namespace std;

struct Node{
    int first, second;
    Node* next;
    Node* last;
    Node(): first(0), second(0), next(nullptr), last(nullptr){}
    Node(int x, int y): second(y), first(x), next(nullptr), last(nullptr){}
    
    Node(Node *A){
        first = A -> first;
        second  = A -> second;
        next = A -> next;
        last = A -> last;
    }

    void mostrar(){
        cout << "(" << first << ", " << second << ")";
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

int main(){

    Stack *S = new Stack();
    S -> push(new Node(1, 2));
    S -> push(new Node(3, 2));
    S -> push(new Node(4, 1));
    // S -> push(new Node(1, 10));
    // S -> push(new Node(10, 2));
    // S -> push(new Node(100, 8));
    // S -> push(new Node(121, 49));


    // cuando se crea  el nodo antes, se envia direccion

    Node cur = new Node(4, 5);
    S -> push(&cur);

    cout << S -> size() << '\n';
    S -> print();
    cout << S -> top().first << "\n";

    S -> pop();
    S -> pop();
    S -> pop();
    S -> pop();
    S -> print();

    int n;
    S = new Stack();
    cin >> n;
    while(n--){
        string ope;
        int x;
        cin >> ope;
        if(ope == "top"){
            if(S -> size())
                cout << S -> top().first << " " << S -> top().second << '\n';
            else
                cout << "pila vacia\n";
        }else if(ope == "push"){
            int x, y;
            cin >> x >> y;
            S -> push(new Node(x, y));
            S -> print();
            printf("\n");
        }else if(ope == "pop"){
            if(S -> empty())
                cout << "vacia\n";
            else{
                S -> pop();
                S -> print();
                printf("\n");
            }
        }else if(ope == "size")
            cout << S -> size() << '\n';
        else if(ope == "empty")
            cout << S -> empty() << '\n';

    }
    
    return 0;
}
