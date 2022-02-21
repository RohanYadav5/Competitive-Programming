// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

//selection sort
void selectionSort(int array[],int size){
    for(int i=0;i<size;i++){
        int minIndex=i , minValue=array[i];
        for(int j=i+1;j<size;j++){
            if(array[j]<minValue){
                minIndex=j;
                minValue=array[j];
            }
        }
        //swap
        int temp=array[i];
        array[i]=minValue;
        array[minIndex]=temp;
    }
}

//print array
void printArray( int array[],int n){
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }cout<<endl;
}

int main() {
    int array[]={14,33,27,10,35,19,42,44};
    cout<<"Before Sorting \n";
    printArray(array,8);
    
    selectionSort(array,8);
    
    cout<<"After Sorting \n";
    printArray(array,8);
}
