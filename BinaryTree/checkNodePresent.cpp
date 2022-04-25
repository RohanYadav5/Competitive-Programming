bool isNodePresent(BinaryTreeNode<int> *root, int x) {
     if(root==NULL)
        return false;
     bool leftChild=isNodePresent(root->left,x);
     bool rightChild=isNodePresent(root->right,x);
     if(root->data==x)
        return true;
     if(leftChild==true || rightChild==true)
        return true;
     return false;
}
