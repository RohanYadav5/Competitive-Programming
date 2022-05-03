#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>
#include<vector>

using namespace std;
 vector<int> data;
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




 vector<int> inorderTraversal(BinaryTreeNode<int>* root) {
        //inorder(root);
        return data;
       /* if(root==NULL){
            data.push_back(-1);
            return data;
        }
        vector<int> leftChild=inorderTraversal(root->left);
        for(int i=0;i<leftChild.size();i++){
           if(leftChild[i]!=-1)
                data.push_back(leftChild[i]);
        }
        data.push_back(root->data);
        vector<int> rightChild=inorderTraversal(root->right);
        for(int i=0;i<rightChild.size();i++){
           if(rightChild[i]!=-1)
                data.push_back(rightChild[i]);
        }
        return data;*/
}

void inorder(BinaryTreeNode<int>* root){
    if(root==NULL)
        return;
    inorder(root->left);
    data.push_back(root->data);
    inorder(root->right);
}

pair<int ,int> findHeightDiameter(BinaryTreeNode<int> *root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int,int> left=findHeightDiameter(root->left);
    pair<int,int> right=findHeightDiameter(root->right);

    pair<int,int>result;
    result.first = 1+max(left.first,right.first);
    result.second = max(left.first+right.first,max(left.second,right.second));
    return result;
}


int main(){
    BinaryTreeNode<int>* root=takeInputLevelWise();
    pair<int ,int> p1=findHeightDiameter(root);
    cout<<"height of tree= "<<p1.first<<endl;
    cout<<"Diameter of tree= "<<p1.second<<endl;
    delete root;
}
