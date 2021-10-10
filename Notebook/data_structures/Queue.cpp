#include <bits/stdc++.h>

using namespace std;

struct Node{
    int value;
    Node* next;
    Node(): value(0), next(nullptr){}
    Node(int x): value(x), next(nullptr){}

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

    void push_back(int x){ // O(1)
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

    Q -> push_back(1);
    Q -> push_back(2);
    Q -> push_back(3);
    Q -> push_back(4);
    Q -> push_back(10);

    cout << Q -> size() << '\n';
    cout << Q -> front().value << " " << Q -> back().value << '\n';
    Q -> pop_front();
    Q -> pop_front();
    
    cout << Q -> size() << '\n';
    cout << Q -> front().value << " " << Q -> back().value << '\n';
    return 0;


}
