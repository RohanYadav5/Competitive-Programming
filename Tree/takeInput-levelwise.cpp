#include<iostream>
#include<queue>
#include "TreeNode.h"

using namespace std;


//print tree like DFS not level wise
void printTree(TreeNode<int> *root){
    //base condition to check root is not null
    if(root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

//function to take input for the tree level wise

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter treenode data = ";
    cin>>rootData;
    TreeNode<int> *root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* newNode=pendingNodes.front();
        pendingNodes.pop();
        int numberOfChild;
        cout<<"Enter number of child of "<<newNode->data<<" = ";
        cin>>numberOfChild;
        for(int i=0;i<numberOfChild;i++){
            int childData;
            cout<<"Enter " <<i+1<<" child of "<<newNode->data<<" = ";
            cin>>childData;
            TreeNode<int>* children=new TreeNode<int>(childData);
            newNode->children.push_back(children);
            pendingNodes.push(children);
        }
    }
    return root;
}

int main(){
    TreeNode<int>* root = takeInput();
    printTree(root);
}
