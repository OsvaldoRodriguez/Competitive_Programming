#include <bits/stdc++.h>

using namespace std;

struct Node{
    int value;
    Node* next;
    Node(): value(0), next(nullptr){}
    Node(int x): value(x), next(nullptr){}
    
    Node(Node *A){
        value = A -> value;
        next = A -> next;
    }

    void mostrar(){
        cout << "(" << value << ")";
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


    void pop_front(){
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


int main(){
    // create list

    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);

    Queue *Q = new Queue();


    Q -> push(new Node(1));
    Q -> push(new Node(3));
    Q -> push(new Node(4));
    Q -> push(new Node(1));
    Q -> push(new Node(10));
    Q -> push(new Node(100));
    Q -> push(new Node(121));


    cout << Q -> size() << '\n';
    cout << Q -> front().value << " " << Q -> back().value << '\n';
    Q -> pop_front();
    Q -> pop_front();
    
    cout << Q -> size() << '\n';
    cout << Q -> front().value << " " << Q -> back().value << '\n';
    
    Q -> print();
    return 0;


}
