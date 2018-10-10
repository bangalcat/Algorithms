#include<iostream>
#include<vector>
using namespace std;

struct Node{
    string name;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(string name): name(name) {}
};

bool operator>(Node &a, Node &b){
    return a.name > b.name;
}

struct Tree{
    Node *root;
    Tree(){root = nullptr;}
    void deleteNode(string name){
        Node *ptr = root;
    }
    void insert(string name){
        Node *ptr = root;
        Node *newNode = new Node(name);
        if(root == nullptr) root = newNode;
        while(true){
            if(ptr > newNode){
                if(ptr->left == nullptr) {ptr->left = newNode;break;}
                else ptr = ptr->left;
            }else{
                if(ptr->right == nullptr) {ptr->right = newNode;break;}
                else ptr = ptr->right;
            }
        }
    }
};

int main(){
    int n; cin >> n;
    string name, enter;
    while(n--){
        cin >> name >> enter;
    }

    return 0;
}