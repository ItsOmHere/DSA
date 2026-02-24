#include <iostream>
#include <vector>
using namespace std;


class Node {
public:
    int destination;
    int distance;
    Node* next;

    Node(int dest, int dist) {
        destination = dest;
        distance = dist;
        next = NULL;
    }
};

class Graph {
private:
    int totalCities;
    vector<string> cityNames;

    Node* linkedList[50];                 
    vector<pair<int,int>> vectorList[50]; 
    int adjMatrix[50][50];               
public:
    Graph(int cities) {
        totalCities = cities;
        cityNames.resize(cities);

        for (int i = 0; i < cities; i++) {
            linkedList[i] = NULL;
            for (int j = 0; j < cities; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void inputCityNames() {
        cout << "\nEnter city names:\n";
        for (int i = 0; i < totalCities; i++) {
            cout << "City " << i << ": ";
            cin >> cityNames[i];
        }
    }
    void addRoad(int source, int destination, int distance) {
       
        Node* newNode = new Node(destination, distance);
        newNode->next = linkedList[source];
        linkedList[source] = newNode;

       
        vectorList[source].push_back({destination, distance});


        adjMatrix[source][destination] = distance;
    }

   
    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n   ";
        for (int i = 0; i < totalCities; i++)
            cout << cityNames[i] << "   ";
        cout << endl;

        for (int i = 0; i < totalCities; i++) {
            cout << cityNames[i] << " ";
            for (int j = 0; j < totalCities; j++)
                cout << "  " << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

   
    void displayLinkedList() {
        cout << "\nLinked List Representation:\n";
        for (int i = 0; i < totalCities; i++) {
            cout << cityNames[i] << " -> ";
            Node* temp = linkedList[i];
            while (temp != NULL) {
                cout << cityNames[temp->destination]
                     << "(" << temp->distance << ") -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

  
    void displayVectorList() {
        cout << "\nVector List Representation:\n";
        for (int i = 0; i < totalCities; i++) {
            cout << cityNames[i] << " -> ";
            for (auto edge : vectorList[i]) {
                cout << cityNames[edge.first]
                     << "(" << edge.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    int cities, roads;

    cout << "Enter number of cities: ";
    cin >> cities;

    Graph graph(cities);
    graph.inputCityNames();

    cout << "\nEnter number of roads: ";
    cin >> roads;

    cout << "\nEnter roads (source_index destination_index distance):\n";
    for (int i = 0; i < roads; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph.addRoad(u, v, d);
    }

    int choice;
    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Display Adjacency Matrix\n";
        cout << "2. Display Vector List\n";
        cout << "3. Display Linked List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            graph.displayMatrix();
            break;
        case 2:
            graph.displayVectorList();
            break;
        case 3:
            graph.displayLinkedList();
            break;
        }
    } while (choice != 0);

    return 0;
}