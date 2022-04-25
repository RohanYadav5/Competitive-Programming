
template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    //constructor
    BinaryTreeNode(T data){
        this->data=data;
        //to avoid garbage
        left=NULL;
        right=NULL;
    }

    //destructor
    ~BinaryTreeNode(){
        //this will automatically ignore if left or right is null
        //also it is a recursive function the end nodes are deleted first and
        //then the first root node is deleted at last
        delete left;
        delete right;
    }


};
