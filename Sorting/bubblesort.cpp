// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void bubbleSort(int *input, int size)
{
     for(int i=0;i<size-1;i++){
         for(int j=0;j<size-1-i;j++){
             if(input[j]>input[j+1]){
                  int temp=input[j];
                  input[j]=input[j+1];
                  input[j+1]=temp;
             }
         }
     }
}

void printArray( int array[],int n){
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }cout<<endl;
}

int main() {
    int array[]={14,33,27,10,35,19,42,44};
    cout<<"Before Sorting \n";
    printArray(array,8);
    
    bubbleSort(array,8);
    
    cout<<"After Sorting \n";
    printArray(array,8);
}
