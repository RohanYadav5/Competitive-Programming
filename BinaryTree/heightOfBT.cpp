//height of binary tree
int height(BinaryTreeNode<int>* root) {
    if(root==NULL)
        return 0;
    return max(height(root->left),height(root->right))+1;
  //using max to find the max height in both child
}
