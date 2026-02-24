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

        int minKey(int key[], bool mst[]){
            int min = INT_MAX;
            int minidx;
            for(int i = 0; i < V; i++) {
                if(!mst[i] && key[i] < min) {
                    min = key[i];
                    minidx = i;
                }
            }
            return minidx;
        }

        void PrimMST() {
            int key[Max];
            int parent[Max];
            bool visit[Max];

            for(int i = 0; i < V; i++){
                key[i] = INT_MAX;
                visit[i] = false;
            }

            key[0] = 0;
            parent[0] = -1;

            for(int count = 0; count < V -1; count++){
                int u = minKey(key, visit);
                visit[u] = true;

                for(int v = 0; v <  V; v++){
                    if(graph[u][v] && !visit[v] && graph[u][v] < key[v]){
                        parent[v] = u;
                        key[v] = graph[u][v];
                    }
                }
            }

            cout << "Edges in MST\n";
            for(int i = 1; i < V; i++)
                cout << parent[i] << " is Parent of " << i << endl;

            int sum = 0;
            cout<<endl;
            cout<<"Total Weight of MST: ";
            for(int i = 0; i < V; i++)
                sum += key[i];
            cout<<sum;
        }
};

int main(){
    int V,E;
    cout <<"Enter Number Of vertices\n";
    cin>>V;
    Graph g(V);
    cout<<"Enter number of Edges\n";
    cin>>E;

    for(int i = 0; i < E; i++){
        int u,v,w;
        cout<<"Edges in (u v w) Format\n";
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }

    g.PrimMST();

    return 0;
}