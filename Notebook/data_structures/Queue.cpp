// test problem uva 12100

// source 
// https://github.com/OsvaldoRodriguez/Competitive_Programming/blob/master/Contests/Uva/12100%20Queue%20implemented.cpp

#include <bits/stdc++.h>

using namespace std;

struct Node{
    int first, second;
    Node* next;
    Node(): first(0), second(0), next(nullptr){}
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

int main(){

    Queue *Q = new Queue();
    Q -> push(new Node(1, 2));
    Q -> push(new Node(3, 2));
    Q -> push(new Node(4, 1));
    Q -> push(new Node(1, 10));
    Q -> push(new Node(10, 2));
    Q -> push(new Node(100, 8));
    Q -> push(new Node(121, 49));


    // cuando se crea  el nodo antes, se envia direccion

    Node cur = new Node(4, 5);
    Q -> push(&cur);

    cout << Q -> size() << '\n';
    cout << Q -> front().first << " " << Q -> back().first << '\n';
    Q -> pop();
    Q -> pop();
    
    cout << Q -> size() << '\n';
    cout << Q -> front().first << " " << Q -> back().first << '\n';
    
    Q -> print();
}
