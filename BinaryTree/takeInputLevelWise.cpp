#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>

using namespace std;

//take input of binary tree level wise
//in level wise we always use queue
BinaryTreeNode<int>* takeInputLevelWise(){
    int data;
    cout<<"Enter tree root data = ";
    cin>>data;
    if(data==-1){return NULL;};
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* frontNode=pendingNodes.front();
        pendingNodes.pop();
        int left,right;
        cout<<"Enter left child data of parent "<<frontNode->data<<" = ";
        cin>>left;
        cout<<endl<<"Enter right child data of parent "<<frontNode->data<<" = ";
        cin>>right;
        if(left!=-1){
            BinaryTreeNode<int>* leftChild=new BinaryTreeNode<int>(left);
            frontNode->left=leftChild;
            pendingNodes.push(leftChild);
        }
        if(right!=-1){
            BinaryTreeNode<int>* rightChild=new BinaryTreeNode<int>(right);
            frontNode->right=rightChild;
            pendingNodes.push(rightChild);
        }
    }
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
    BinaryTreeNode<int>* root=takeInputLevelWise();
    PrintBinaryTree(root);
}
