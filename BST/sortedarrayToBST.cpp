//2 ways of doing using vector and array
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {        
          return createBST(nums,0,nums.size()-1);
    }
    
   TreeNode* createBST(vector<int>& array,int startIndex,int endIndex){
        if(startIndex>endIndex)
            return NULL;

        int mid=(startIndex+endIndex)/2;
        TreeNode* root = new TreeNode(array[mid]);
        root->left=createBST(array,startIndex,mid-1);
        root->right=createBST(array,mid+1,endIndex);
        return root;
    }

};


//returning root
BinaryTreeNode<int>* createBST(int *array,int startIndex,int endIndex){
    if(startIndex>endIndex)
        return NULL;

    int mid=(startIndex+endIndex)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(array[mid]);
    root->left=createBST(array,startIndex,mid-1);
    root->right=createBST(array,mid+1,endIndex);
    return root;
}
