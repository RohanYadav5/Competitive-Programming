#include<iostream>
#include<queue>
using namespace std;

//connected graph
//        0
//      /   \
//     1     2
//     |     | \
//     |     |  6
//     5     3
//      \   /
//        4
//


//print graph using DFS
//printing above graph output -- 0 1 5 4 3 2 6
void printGraphUsingDFS(int **edges,int n,int sv,bool *visited){
    cout<<sv<<" , ";
    visited[sv]=true;//0 index is true not printed
    for(int i=0;i<n;i++){
        if(sv==i){
            continue;
        }
        if(edges[sv][i] == 1){
            //to avoid already visited;
            if(visited[i] == true){
                continue;
            }
            printGraphUsingDFS(edges,n,i,visited);
        }
    }

}

int main(){
    int n , e;
    cout<<"enter no of vertices and edges in graph = ";
    cin>>n>>e;

    //we will be using dynamic array

    //1.step is to make a 2d array and set all values as defaut as 0 to avoid garbage values
    //2d array of size vertices*vertices
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    //2.step is to take pair of edges that are there in graph
    for(int i=0;i<e;i++){
        int f , s;
        cout<<"enter edges pair = ";
        cin>>f>>s;
        cout<<endl;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    //3.creating a array in which we will keep track of elements printed so we don't get stuck in a loop
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    //4.step is print graph
    //2 ways of printing graph

    printGraphUsingDFS(edges,n,0,visited);

    delete edges;
    delete visited;
}
