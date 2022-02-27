// Online C++ compiler to run C++ program online
#include <iostream>
#include<unordered_map>
using namespace std;


void removeDuplicates(int *arr,int n){
    unordered_map<int,int> ourmap;
    for(int i=0;i<n;i++){
        if(ourmap.count(arr[i])==0 ){
            ourmap[arr[i]]=arr[i];
        }
    }
// range based loop for c++
//auto can be int or any type of list to which we are iterating
  //Printing remomved duplicated list;
     for (auto i: ourmap)
        {
            cout<<i.second<<" ";
        }
        cout<<endl;
    for (auto i: ourmap)
        {
            cout<<i.first<<": "<<i.second<<endl;
        }
    cout<<endl;
}


int main() {

    int array[]={1,2,3,4,5,6,1,2,3,4,1,3,4,5,2,4,6};
    for(int i=0;i<sizeof(array)/sizeof(array[0]);i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    removeDuplicates(array,sizeof(array)/sizeof(array[0]));
    
}
