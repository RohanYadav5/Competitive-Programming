/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<queue>
class Solution {
queue<TreeNode*> pending;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        doDfs(root);
        TreeNode* newRoot=new TreeNode(pending.front()->val);
        TreeNode* tempRoot=newRoot;
        pending.pop();
        while(!pending.empty()){
            tempRoot->right=new TreeNode(pending.front()->val);
            pending.pop();
           // newRoot->left=NULL;
//            newRoot->right=pending.front()->val;
            tempRoot=tempRoot->right;
        }
        return newRoot;
    }
    
   TreeNode* doDfs(TreeNode* root){
        if(root==NULL)
            return NULL;
       TreeNode* left=doDfs(root->left);
       pending.push(root);
       TreeNode* right=doDfs(root->right);
       return root;
    }
};
