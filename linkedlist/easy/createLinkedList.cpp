#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data1,Node* next1){
            data = data1;
            next = next1;
        }

        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

int main(){
    vector<int> ans = {1,2,3,4,5};
    Node* y = new Node(ans[0]);
    y->next = new Node(ans[1]);
    cout << y << "/n";
    cout << y->data << "/n";
    cout << y->next << "/n";
    return 0;
}