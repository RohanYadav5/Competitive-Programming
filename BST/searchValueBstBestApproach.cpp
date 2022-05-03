class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
            return NULL;
        if(root->val==val)
            return root;
        //if value does not exsit it will automatically send send and we don't have
        //to check for right because it is a bst
        if(root->val>val)
            return searchBST(root->left,val);
        if(root->val<val)
           return searchBST(root->right,val);
        return NULL;
        
    }
};
