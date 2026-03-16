#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    char data;
    int terlihat;
    vector<Node*> temp;
};

void DFS(Node* node){
    if(node->terlihat == 1)
        return;

    node-> terlihat = 1;
    cout << node->data << " ";

    for(Node* next : node->temp){
        DFS(next);
    }
}

void BFS(Node* start){
    queue<Node*> qn;

    start -> terlihat =1;
    qn.push(start);

    while(!qn.empty()){
        Node* current = qn.front();
        qn.pop();

        cout << current->data << " ";

        for(Node* next : current->temp){
            if(next->terlihat == 0){
                next-> terlihat = 1;
                qn.push(next);
            }
        }
    }
}

int main(){
    Node A{'A',0};
    Node B{'B',0}; 
    Node C{'C',0};
    Node D{'D',0}; 
    Node E{'E',0}; 
    Node F{'F',0};

    A.temp.push_back(&B);
    A.temp.push_back(&C);
    B.temp.push_back(&D);
    B.temp.push_back(&E);
    C.temp.push_back(&F);
    cout << "DFS Traversal : ";
    DFS(&A);

    cout << endl;

    A.terlihat = 0; 
    B.terlihat = 0; 
    C.terlihat = 0;
    D.terlihat = 0; 
    E.terlihat = 0; 
    F.terlihat = 0;
    cout << "BFS Traversal : ";
    BFS(&A);

    return 0;
}



