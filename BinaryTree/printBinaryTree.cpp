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

//Print binary tree in  Root1:L2,R3 formart
void PrintBinaryTree(BinaryTreeNode<int> *root){
    if(root==NULL){
       return;
    }
    cout<<root->data<<" : ";
    if(root->left!=NULL){
       cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    PrintBinaryTree(root->left);
    PrintBinaryTree(root->right);
}

int main(){
    BinaryTreeNode<int> *root=takeInput();
    PrintBinaryTree(root);
}
