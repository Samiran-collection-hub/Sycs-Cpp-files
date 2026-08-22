#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data=value;
        left=right=nullptr;
    }
};

Node* insertBST(Node* root,int value){
    if(root==nullptr){
        return new Node(value);
    }
    if(value < root->data){
        root->left=insertBST(root->left,value);
    }else{
        root->right=insertBST(root->right,value);
    }
    return root;
}
void inOrderTrav(Node* root){
    if(root==nullptr) return;
    inOrderTrav(root->left);
    cout<<root->data<<" ";
    inOrderTrav(root->right);
}

int main() 
{
    int data[]={50,30,20,40,70,60,80};
    int size=sizeof(data)/sizeof(data[0]);
    Node* root=nullptr;
    for(int i=0;i<size;++i){
        root=insertBST(root,data[i]);
    }
    cout<<"inorder taravesal of the bst:";
    inOrderTrav(root);

    return 0;
}
