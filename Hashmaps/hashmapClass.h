#include<iostream>
using namespace std;

template<typename V>
class MapNode{
    V value;
    string key;
    MapNode *next;
    
    MapNode(string key,V value){
        this->value=value;
        this->key=key;
        next=NULL;
    }

    ~MapNode(){
        delete next;
    }
};  

template<typename V>
class ourmap{
    int count;
    int bucketSize;
    MapNode<V>** bucket;  // stores address of node pointer 
    
    ourmap(){
        count=0;
        bucketSize=5;
        bucket = new MapNode<V>*[bucketSize];
        // adding default value as NULL to avoid garbage value
        for(int i=0;i<bucketSize;i++){
            bucket[i]=NULL;
        }
    }
    
    //destructor
    ~ourmap(){
        //deleting all node
        for(int i=0;i<bucketSize;i++){
            delete bucket[i];
        }
    }
    
    //function returns size of hashmap
    int size(){
    }
    
    //get value of key
    V getValue(string key){
    }
    
    //insert value in hashmap
    void insert(string key,V value){
    }
    
    //remove value from hashmap
    V remove(string key){
    }
    
    
};
