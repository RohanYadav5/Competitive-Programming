include<iostream>
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

//Print tree level wise
void printBinaryTreeLevelWise(BinaryTreeNode<int>* root){
    if(root==NULL){return;}
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* frontNode=pendingNodes.front();
        pendingNodes.pop();
        cout<<frontNode->data<<":";
        if(frontNode->left!=NULL){
            cout<<"L:"<<frontNode->left->data<<",";
            pendingNodes.push(frontNode->left);
        }else{
        cout<<"L:"<<-1<<",";
        }
        if(frontNode->right!=NULL){
            cout<<"R:"<<frontNode->right->data;
            pendingNodes.push(frontNode->right);
        }else{
             cout<<"R:"<<-1;
        }
        cout<<endl;
    }
}

//find number of nodes in a BT
int countNodes(BinaryTreeNode<int>* root){
    if(root==NULL)
        return 0;
    //int leftNodes=countNodes(root->left);
    //int rightNodes=countNodes(root->right);
    //return leftNodes+rightNodes+1;
    //more refactored way of doing this
    return 1+countNodes(root->left)+countNodes(root->right);
}


int main(){
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printBinaryTreeLevelWise(root);
    cout<<"Number of nodes in BT = "<<countNodes(root)<<endl;
    delete root;
}
