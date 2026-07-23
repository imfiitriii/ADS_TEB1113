#include <iostream>
#include <climits>
using namespace std;

// Node for adjacency linked list
struct Node
{
    int vertex;
    int weight;
    Node *next;

    Node(int v, int w)
    {
        vertex = v;
        weight = w;
        next = NULL;
    }
};

class GraphLinkedList
{
private:
    int V;
    Node **head;

public:
    // Constructor
    GraphLinkedList(int vertices)
    {
        V = vertices;
        head = new Node *[V];

        for (int i = 0; i < V; i++)
            head[i] = NULL;
    }

    // Add an edge (undirected)
    void addEdge(int u, int vertex, int weight)
    {
        // u -> vertex
        Node *newNode = new Node(vertex, weight);
        newNode->next = head[u];
        head[u] = newNode;

        // vertex -> u
        newNode = new Node(u, weight);
        newNode->next = head[vertex];
        head[vertex] = newNode;
    }

    // Find vertex with minimum distance
    int findMinDistance(int dist[], bool visited[])
    {
        int min = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

    // Dijkstra Algorithm
    void dijkstra(int source)
    {
        int dist[V];
        bool visited[V];

        for (int i = 0; i < V; i++)
        {
            dist[i] = INT_MAX;
            visited[i] = false;
        }

        dist[source] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            int u = findMinDistance(dist, visited);

            if (u == -1)
                break;

            visited[u] = true;

            Node *temp = head[u];

            while (temp != NULL)
            {
                int v = temp->vertex;
                int weight = temp->weight;

                if (!visited[v] &&
                    dist[u] != INT_MAX &&
                    dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                }

                temp = temp->next;
            }
        }

        cout << "Vertex\tDistance from Source\n";
        for (int i = 0; i < V; i++)
        {
            cout << i << "\t" << dist[i] << endl;
        }
    }

    // Display adjacency list
    void display()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";

            Node *temp = head[i];
            while (temp != NULL)
            {
                cout << "(" << temp->vertex << ", " << temp->weight << ") ";
                temp = temp->next;
            }

            cout << endl;
        }
    }
};

int main()
{
    GraphLinkedList graph(6);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 10);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 6);
    graph.addEdge(4, 5, 3);

    cout << "Adjacency List:\n";
    graph.display();

    cout << "\nDijkstra (Source = 0)\n";
    graph.dijkstra(0);

    return 0;
}