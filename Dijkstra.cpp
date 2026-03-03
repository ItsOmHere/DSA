#include<iostream>
#include<climits>

using namespace std;

#define Max 100

class Graph{
    int V;
    int graph[Max][Max];

    public:
        Graph(int V){
            this->V = V;
            for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                graph[i][j] = 0;
        }

            

        void addEdge(int u, int v, int w){
            graph[u][v] = w;
            graph[v][u] = w;
        }

        int minKey(int key[], bool visit[]){
            int min = INT_MAX;
            int min_index;
            for(int i = 0; i < V; i++) {
                if(!visit[i] && key[i] < min) {
                    min = key[i];
                    min_index = i;
                }
            }
            return min_index;
        }

        void Dijkstra() {
            int Dist[Max];
            int parent[Max];
            bool visit[Max];
            int u,source;
            cout<<"Enter the Source To Calculate from:";
            cin>>source;
           

            for(int i = 1; i < V; i++){
             Dist[i] = INT_MAX;
                visit[i] = false;
            }

            Dist[source] = 0;
            parent[source] = -1;

            for(int count = 0; count < V -1; count++){

                int u = minKey (Dist, visit);
                visit[u] = true;

                for(int v = 0; v <  V; v++){
                    if(graph[u][v] && !visit[v] && Dist[u] + graph[u][v] < Dist[v]){
                        parent[v] = u;
                        Dist[v] = Dist[u] + graph[u][v];
                    }
                }
                

            }

            cout << "Edges in The Path\n";
            for(int i = 1; i < V; i++)
                cout << parent[i] << " is Parent of " << i << endl;

            cout<<"Minimum Distance From Source "<<u<<" :";
            for(int i = 0; i < V ; i++ )
            {
                cout<<source<<" to "<<i<<" = "<<Dist[i]<<"\n";
            } 
        }
};

int main(){
    int V,E;
    cout <<"Enter Number Of vertices\n";
    cin>>V;
    Graph g(V);
    cout<<"Enter number of Edges\n";
    cin>>E;
    cout<<"Edges in (u v w) Format\n";
    for(int i = 0; i < E; i++){
        int u,v,w;
      
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }

    g.Dijkstra();

    return 0;
}