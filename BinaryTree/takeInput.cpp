#include<iostream>
#include "BinaryTreeNode.h"

using namespace std;

BinaryTreeNode<int>* takeInput(){
    int data;
    cout<<"Enter Data = ";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    BinaryTreeNode<int>* leftChild=takeInput();
    BinaryTreeNode<int>* rightChild=takeInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}

int main(){
    BinaryTreeNode<int> *root=takeInput();
}
