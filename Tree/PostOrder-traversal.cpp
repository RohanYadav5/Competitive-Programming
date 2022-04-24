#include<iostream>
#include<queue>
#include "TreeNode.h"

using namespace std;

//      1
//  2   3   4
// 5 6       7
//Postorder traversal means print child first and then we print the parent always
void PostOrderTraversal(TreeNode<int> *root){
    if(root==NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        PostOrderTraversal(root->children[i]);
    }
    cout<<root->data<<" , ";
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
    cout<<"PostOrder Traversal"<<endl;
    PostOrderTraversal(root);

}
