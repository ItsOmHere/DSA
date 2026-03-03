#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int dest;
    int weight;
    Node* next;
    Node(int d, int w) {
        dest = d;
        weight = w;
        next = NULL;
    }
};

class Graph {
    int V;
    vector<string> city;
    Node* llList[50];
    vector<pair<int,int>> vecList[50];
    int m[50][50];

public:
    Graph(int V) {
        this->V = V;
        city.resize(V);
        for(int i = 0; i < V; i++) {
            llList[i] = NULL;
            for(int j = 0; j < V; j++)
                m[i][j] = 0;
        }
    }

    void setCities() {
        cout << "\nEnter city names:\n";
        for(int i = 0; i < V; i++) {
            cout << "City " << i << ": ";
            cin >> city[i];
        }
    }

    void addEdge(int u, int v, int w) {
        Node* n = new Node(v, w);
        n->next = llList[u];
        llList[u] = n;
        vecList[u].push_back({v, w});
        m[u][v] = w;
    }

    void printMatrix() {
        for(int i = 0; i < V; i++)
            cout << "   " << city[i];
        cout << endl;
        for(int i = 0; i < V; i++) {
            cout << city[i];
            for(int j = 0; j < V; j++)
                cout << "   " << m[i][j];
            cout << endl;
        }
    }

    void printLinkedList() {
        for(int i = 0; i < V; i++) {
            cout << city[i] << " -> ";
            Node* temp = llList[i];
            while(temp != NULL) {
                cout << city[temp->dest] << "(" << temp->weight << ") -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

    void printVectorList() {
        for(int i = 0; i < V; i++) {
            cout << city[i] << " -> ";
            for(auto x : vecList[i])
                cout << city[x.first] << "(" << x.second << ") ";
            cout << endl;
        }
    }

   
};

int main() {
   int V, E;
    cout << "Enter number of cities: ";
    cin >> V;

    Graph g(V);
    g.setCities();

    cout << "\nEnter number of roads: ";
    cin >> E;

    cout << "\nEnter edges (source_index destination_index weight):\n";
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int ch;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Show Adjacency Matrix\n";
        cout << "2. Show Vector List\n";
        cout << "3. Show Linked List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        if(ch == 1) g.printMatrix();
        else if(ch == 3) g.printLinkedList();
        else if(ch == 2) g.printVectorList();
    } while(ch != 0);

    return 0;
}
