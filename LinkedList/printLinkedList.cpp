// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


void printLinkedList(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
};



int main() {
    Node *head=new Node(10);
    Node *head1=new Node(30);
    head->next=head1;
    printLinkedList(head);
}
