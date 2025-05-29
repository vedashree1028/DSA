#include<iostream>
using namespace std;
#define max_nodes 100
class graph{

   public:
   int vertices;
   int adj[max_nodes][max_nodes];

   graph(int v){
    vertices=v;
    for(int i=0 ; i<v ; i++){
        for(int j=0 ; j<v ; j++){
            adj[i][j]=0;
        }
    }
   }

   void addedge(int s , int d){
        adj[s][d]=1;
        adj[d][s]=1;
   }

   void display(){
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
   }

   void BFS(int start){
     int visited[max_nodes] = {0};
     int queue[max_nodes];
     int front =0;
     int rear =0;

     visited[start]=1;
     queue[rear]=start;
     rear++;

     while(front < rear){
        int node = queue[front];
        front++;
        cout<<node<<" ";
        
        for(int i=0 ; i<vertices; i++){
            if(adj[node][i] == 1 && visited[i]==0){
                queue[rear]=i;
                visited[i]=1;
                rear++;
            }
        }
     }
     cout<<endl;
     for(int i=0 ; i<vertices ; i++){
        cout<<visited[i]<<" ";
     }
   }

   void DFS(int start){
    int visited[max_nodes] ={0};
    int stack[max_nodes];
    int top=-1;

    stack[++top]=start;
    while(top>=0){
        int node=stack[top--];
        if(visited[node]==0){
            cout<<node<<" ";
        }
        visited[node]=1;
        for(int i = vertices - 1; i >= 0; i--) { 
            if(adj[node][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
            }
        }
        }
    }
   

};
int main() {
    
    graph g(5); 

    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(4, 0);

    cout << "Adjacency Matrix:" << endl;
    g.display();

    cout<<endl;

    cout<<"BFS display:"<<" ";
    g.BFS(0);

    cout<<endl;

    cout<<"DFS display:"<<" ";
    g.DFS(0);
    
    return 0;
}
