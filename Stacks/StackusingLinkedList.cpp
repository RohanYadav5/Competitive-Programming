// Online C++ compiler to run C++ program online
#include <iostream>
#include<climits>
using namespace std;
template<typename T>

class Node{
    public:
    Node<T> *next;
    T data;
    
    Node(T data){
        this->data=data;
        next=NULL;
    }
    ~Node(){
        delete next;
    }
};

template<typename T>
class StackUsingLinkedList{
    Node<T> *head;
    int size;
    
    public:
    StackUsingLinkedList(){
        head=NULL;
        size=0;
    }
    
    T top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        return head->data;
    }
    
    bool isEmpty(){
        return size==0;
    }
    
    int getSize(){
        return size;
    }
    
    T pop(){
        if(size==0){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        T tempData=head->data;
        head=head->next;
        size--;
        return tempData;
    }
    
    void push(T value){
        Node<T> *temp=new Node<T>(value);
        if(head==NULL){
            head=temp;
        } else{
        temp->next=head;
        head=temp;
        }
        size++;
        return;
    }
    
};

int main() {
    StackUsingLinkedList<int> st;
   
   int size,input;
   cin>>size;
   //taking input for stack
   while(size>0){
       cin>>input;
       st.push(input);
       size--;
   }
   
   //printing stack value
    cout<<"Stack list =";
    while(st.getSize()!=0){
        cout<<st.pop()<< ", ";
    }
}
