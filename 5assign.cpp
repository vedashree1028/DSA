#include<iostream>
using namespace std;
#define v 4
#define INF 999
class graph{

    public:

    int G[v][v];

    void readgraph(){
        cout<<"enter the adj matrix:";
        for(int i=0 ; i<v ; i++){
            for(int j=0 ; j<v ; j++){
                cin>>G[i][j];
            }
        }
    }

    void printgraph(){
        cout<<"the graph is:";
        for(int i=0 ; i<v ; i++){
            for(int j=0 ; j<v ; j++){
                cout<<G[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void dijkstra(int src){

        int dist[v];
        bool visited[v]={false};

       for(int i=0 ; i<v ;i++){
        dist[i]=INF;
       }

       dist[src]=0;

       for(int i=0 ; i<v ; i++){
             int min=INF , u;
            for(int j=0 ; j<v ; j++){
                if(!visited[j] && dist[j]<min){
                    min=dist[j];
                    u=j;
                }
            }
            visited[u]=true;

            for(int V=0 ; V<v ; V++){
                if(!visited[V] && G[u][V]!=0 && dist[u] + G[u][V] < dist[V]){
                    dist[V]=dist[u]+G[u][V];
                }
            }
       }

       cout<<"Shortest distances from source " << src << ":\n";
       int totalDistance = 0;

       for(int i = 0 ; i < v ; i++){
           cout << "To vertex " << i << " = " << dist[i] << endl;
           if(i != src && dist[i] != INF) {
               totalDistance += dist[i];
           }
       }

       cout << "Total minimum distance from source = " << totalDistance << endl;
    }
};
int main() {
    graph g;
    g.readgraph();
    g.printgraph();
    int source;
    cout << "Enter source vertex (0 to " << v-1 << "): ";
    cin >> source;
    g.dijkstra(source);
    return 0;
}
