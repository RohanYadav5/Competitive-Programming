//in this approach we are calling left or right even when the value is smaller than min or
//more than max value
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	//we have to 
    if(root==NULL)
        return;

	 elementsInRangeK1K2(root->left,k1,k2);
    if(root->data >= k1 &&  root->data <=k2){
        cout<<root->data<<" ";
    }
    elementsInRangeK1K2(root->right,k1,k2);    
}


//more better approach would be to only call left part of subtree
//or right part of subtree when 
//1.Call left subtree - when value of root->data is less then max value given
//2.Call right subtree - when value of root->data is more then min value given
//Time complexity o(n) where n is number of nodes 
//Spave Complexity o(h) h is the height

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	//we have to 
    if(root==NULL)
        return;
    if(root->data <= k2 &&  root->data >=k1){
        elementsInRangeK1K2(root->left,k1,k2);   
        cout<<root->data<<" ";
        elementsInRangeK1K2(root->right,k1,k2);  
    }
    
    if (root->data<k1){
    	elementsInRangeK1K2(root->right,k1,k2);    
    }
	else if(root->data>k2){
    	elementsInRangeK1K2(root->left,k1,k2);    
    }
}
