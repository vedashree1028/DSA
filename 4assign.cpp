#include<iostream>
using namespace std;
#define INF 99999
#define V 5
class graph{
    public:

    int G[V][V];

    void readgraph(){
        cout<<"enter adj matrix:";
        for(int i=0 ; i<V ; i++){
            for(int j=0 ; j<V ; j++){
                cin>>G[i][j];
            }
        }
    }

    void printgraph(){
        cout<<"displaying the graph of college campus:"<<endl;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                cout<<G[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void primsgraph(){
        int no_edge;
        int i,j;
        int totalcost=0;

        int visited[V]={false};
        no_edge=0;

        visited[0]=true;
        int row,col;

        cout<<"Minimum selected edge  "<< ":" <<"weight";
        cout<<endl;

        while(no_edge < V-1){
            int min=INF;
            row=0;
            col=0;

            for(i=0;i<V;i++){
                if(visited[i]){
                    for(j=0;j<V;j++){
                        if(G[i][j] && !visited[j]){
                            if(min > G[i][j]){
                                min=G[i][j];
                                row=i;
                                col=j;
                            }
                        }
                    }
                }
            }
            cout<<row<<"-"<<col<<" : "<<G[row][col];
            cout<<endl;
            visited[col]=true;
            no_edge++;

            totalcost=totalcost + G[row][col];
        }
        cout<<"total cost of MST:"<<totalcost;
    }
};
int main(){

    graph g;
    g.readgraph();
    cout<<endl;
    g.printgraph();
    cout<<endl;
    g.primsgraph();

    return 0;
}
