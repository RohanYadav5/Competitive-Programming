#include<iostream>
#include<queue>
#include "TreeNode.h"

using namespace std;


//      1
//  2   3   4
// 5 6       7
//print tree level wise
void printTree(TreeNode<int> *root){
   queue<TreeNode<int>*> pendingNode;
   pendingNode.push(root);
   while(!pendingNode.empty()){
    TreeNode<int>* frontNode = pendingNode.front();
    pendingNode.pop();
    cout<<frontNode->data<<":";
    for(int i=0;i<frontNode->children.size();i++){
        cout<<frontNode->children[i]->data<<",";
        pendingNode.push(frontNode->children[i]);
    }
    cout<<endl;
   }
}

//      1           -level || depth = 0
//  2   3   4       -level || depth = 1
// 5 6       7      -level || depth = 2
//depth of a node==level of node
//depth is how far a node is from the root same like level
//print all node at depth 0 ,1 ,2 or at any depth
//same could be asked to print nodes at level 1,2 or nth level
void printAtLevel(TreeNode<int> *root , int level){
    if(root==NULL){
        return;
    }
    if(level==0){
        cout<<root->data;
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printAtLevel(root->children[i],level-1);
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
    cout<<"Elements present at L0 = ";
    printAtLevel(root,0);
    cout<<endl<<"Elements present at L1 = ";
    printAtLevel(root,1);
    cout<<endl<<"Elements present at L2 = ";
    printAtLevel(root,2);

}
