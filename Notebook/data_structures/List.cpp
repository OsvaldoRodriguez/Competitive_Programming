// implementado con punteros

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

struct List{
    Node *head;
    Node *end;
    int len;
    List(): len(0), head(nullptr), end(nullptr){}

    bool empty(){ // O (1)
        return head == nullptr;
    }

    int length(){ // O(1)
        return len;
    }

    void push(int x){ // O(1)
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

    void print(){  // O(n)
        Node* currentNode = head;
        while(currentNode != nullptr){
            Node tmp = *currentNode;
            tmp.mostrar();
            currentNode = currentNode -> next;
        }
        cout << '\n';
    }
    // elimina la primera aparicion de x
    void erase(int x){ // O (n)
        Node* toDelete;
        Node* currentNode = head;
        Node* ant = head;
        while(currentNode != nullptr){
            Node tmp = *currentNode;
            if(tmp.value == x){
                if(currentNode == head){
                    toDelete = currentNode;
                    head = currentNode -> next;
                }else{
                    ant -> next = currentNode -> next;
                    toDelete = currentNode;
                }
                len--;
                delete toDelete;
                break;
            }
            ant = currentNode;
            currentNode = currentNode -> next;
        }
        
    }
};

int main(){
    // create list
    List *A = new List();

    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        A -> push(x);
    }

    int q;
    cin >> q;
    A -> print();
    // 1 push
    // 2 erase

    while(q--){
        int ope, y;
        cin >> ope >> y;
        if(ope == 1)
            A -> push(y);
        if(ope == 2)
            A -> erase(y);

        cout << A -> length() << '\n';

        A -> print();
    }


}
