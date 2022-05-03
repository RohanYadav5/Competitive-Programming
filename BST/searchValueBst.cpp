class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
            return NULL;
        if(root->val==val)
            return root;
        TreeNode* leftChild=NULL;
        TreeNode* rightChild=NULL;
        if(root->val>val)
            leftChild=searchBST(root->left,val);
        if(root->val<val)
            rightChild=searchBST(root->right,val);
        
        // TreeNode* leftChild=searchBST(root->left,val);
        // TreeNode* rightChild=searchBST(root->right,val);
        if(leftChild!=NULL)
            return leftChild;
        if(rightChild!=NULL)
            return rightChild;
        return NULL;
        
    }
};

bool searchInBST(BinaryTreeNode<int> *root , int k) {
    if(root==NULL){return NULL;}
    if(root->data==k){return root;}
    if(root->data<k){
        return searchInBST(root->right,k);
    }else{
        return searchInBST(root->left,k);
    }
    
}
