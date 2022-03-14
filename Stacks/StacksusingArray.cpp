// Online C++ compiler to run C++ program online
#include <iostream>
#include<climits>
using namespace std;
class StackUsingArray{
    
    int *data;
    int nextIndex;
    int capacity;
    
    
    public:
    StackUsingArray(){
        data=new int[4];  //dynamic array
        nextIndex=0;
        capacity=4;
    }
    
    int size(){
        return nextIndex;
    }
    
    bool isEmpty(){
        return nextIndex==0;
    }
    
    int pop(){
        if(nextIndex==0){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    
  //is size full then creating new and then pushing
    void push(int value){
        if(nextIndex==capacity){
            int *newArray=new int[capacity*2];
            for(int i=0;i<capacity;i++){
                newArray[i]=data[i];
            }
            delete [] data;
            capacity*=2;
            data=newArray;
        }
        data[nextIndex]=value;
        nextIndex++;
    }
    
    int top(){
        if(isEmpty()==1){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
    
    
};



int main() {
    StackUsingArray s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout<<"Top element = "<<s1.top()<<endl;
    cout<<"Is Empty = "<<s1.isEmpty()<<endl;
    cout<<s1.size()<<endl;
    while(s1.size()>0){
         cout<<"pop element = "<<s1.pop()<<endl;
    }
     cout<<"Is Empty = "<<s1.isEmpty()<<endl;
}
