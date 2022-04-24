#include<iostream>
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

//function to take input for the tree
//this would be like DFS not level wise input

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter treenode data = ";
    cin>>rootData;
    TreeNode<int> *root=new TreeNode<int>(rootData);

    int n;
    cout<<endl<<"Enter no of children of " << rootData<<" = ";
    cin>>n;
    for(int i=0;i<n;i++){
        //creating treenode and pushing in parent vector
        TreeNode<int> *child=takeInput();
        root->children.push_back(child);
    }
    return root;

}

int main(){
    TreeNode<int>* root = takeInput();
    printTree(root);
}
