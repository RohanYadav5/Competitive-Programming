#include<iostream>
#include<queue>
#include "TreeNode.h"

using namespace std;


//      1
//  2   3   4
// 5 6       7
//print tree level wise
void PreOrderTraversal(TreeNode<int> *root){
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
    PreOrderTraversal(root);
    cout<<"PreOrder Traversal is same as level wise printint"<<endl;
    PreOrderTraversal(root);


}
