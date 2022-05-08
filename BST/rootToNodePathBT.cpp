vector<int>* getRootTONodePath(BinartTree<int> *root,int value){
    if(root==NULL)
      return NULL;
    if(root->data==value){
     vector<int> *output=new vector<int>();
      output->push_back(root->data);
      return output;
    }
    
    vector<int>* leftSide=getRootTONodePath(root->left,data);
    if(leftSide!=NULL){
        leftSide->push_back(root->data);
        return leftSide;
    }
  
    vector<int>* rightSide=getRootTONodePath(root->left,data);
    if(rightSide!=NULL){
        rightSide->push_back(root->data);
        return rightSide;
    }    
    return NULL;
}
