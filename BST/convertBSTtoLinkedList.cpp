/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/
Node<int> *head;
Node<int> *temp;

void convertToLL(BinaryTreeNode<int>* root){
    	if(root==NULL)
            return ;
    	convertToLL(root->left);
    	Node<int>* newNode=new Node<int>(root->data);
    	temp->next=newNode;
    	temp=newNode;
    	convertToLL(root->right);
}



Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root==NULL){
        return head;
    }
    head=new Node<int>(NULL);
    temp=head;
    convertToLL(root);    
    head=head->next;
    return head;
