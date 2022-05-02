BinaryTreeNode<int>* makeTree(int *preorder,int preStart,int preEnd,int *inorder,int inStart,int inEnd){
    if(preStart>preEnd||inStart>inEnd)
        return NULL;
    int rootIndex;
    for(int i=inStart;i<=inEnd;i++){
        if(inorder[i]==preorder[preStart])
            rootIndex=i;
    }
    int l1=preStart+1;
    int l3=inStart;
    int l4=rootIndex-1;
    int l2=(l4-l3)+l1;
    
    int r3=rootIndex+1;
    int r4=inEnd;
    int r2=preEnd;
    int r1=r2-(r4-r3);
    
    
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[preStart]);
    root->left=makeTree(preorder,l1,l2,inorder,l3,l4);
    root->right=makeTree(preorder,r1,r2,inorder,r3,r4);
    return root;    
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    return makeTree(preorder,0,preLength-1,inorder,0,inLength-1);
}
