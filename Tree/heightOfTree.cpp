
//find height of tress
int findHeight(TreeNode<int>* root) {
    int height=0;
    for(int i=0;i<root->children.size();i++){
        int childHeight=findHeight(root->children[i]);
        if(childHeight>height){
            height=childHeight
        }
    }
    return height+1;
}

