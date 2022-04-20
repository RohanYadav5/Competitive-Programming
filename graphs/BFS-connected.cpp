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


//print graph using BFS
//printing above graph output -- 0 1 2 5 3 6 4
void printGraphUsingBFS(int **edges,int n,int sv,bool *visited){
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
         int currentTop=q.front();
        q.pop();
        cout<<currentTop<<", ";
        for(int j=0;j<n;j++){
            if( currentTop == j){
                continue;
            }
            if(edges[currentTop][j] == 1 ){
                if( visited[j] == true ){
                    continue;
                }
                q.push(j);
                visited[j]=true;

            }
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

   // printGraphUsingDFS(edges,n,0,visited);

    printGraphUsingBFS(edges,n,0,visited);

    delete edges;
    delete visited;
}
