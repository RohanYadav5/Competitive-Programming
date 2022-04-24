#include <vector>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data=data;
    }
    
    //destructor or deleting tree nodes child first and then parent
     ~TreeNode(){
        for(int i=0;i<children.size();i++)
            delete children[i];
    }
};
