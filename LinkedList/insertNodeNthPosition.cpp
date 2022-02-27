// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

void printLinkedList(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
};

//returns a node type pointer
Node *takeInput(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            //tail=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}

//insert a new Node in an existing LinkedList
Node *insertLinkedList(Node *head,int i,int data){
   
   if(i==0){
        Node *newnode=new Node(data);
        newnode->next=head;
        head=newnode;
    }
    if(i==1){
        Node *newnode=new Node(data);
        newnode->next=head->next;
        head->next=newnode;
        return head;
    }
    if(head->next==NULL&&i!=1){
        return head;
    }
   head->next=insertLinkedList(head->next,i-1,data);
   return head;
}


int main() {
    Node *head=takeInput();
    printLinkedList(head);
    head=insertLinkedList(head,3,200);
    printLinkedList(head);
}
