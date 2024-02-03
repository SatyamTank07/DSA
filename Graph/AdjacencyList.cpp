#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;
template <typename T>
class graph
{
public:
    unordered_map<T, list<pair<T,int>>> adjList;

    void addEdge(T u, T v,int weight, bool direction)
    {
        adjList[u].push_back({v,weight});
        if (direction == 0)
        {
            adjList[v].push_back({u,weight});
        }
    }

    void printAdjList(){
        for(auto node:adjList){
            cout << node.first << " -> ";
            for(auto naiberNode: node.second){
                cout << "(" << naiberNode.first << "," << naiberNode.second << "),  ";
            }
            cout << endl;
        }
    }
};
int main()
{
    graph<int> g;
    g.addEdge(0,1,2,0);
    g.addEdge(0,2,5,0);
    g.addEdge(0,3,6,0);
    g.addEdge(1,3,5,0);
    g.addEdge(2,3,6,0);
    cout << endl;   
    g.printAdjList();

    return 0;
}


// 3 -> (0,6),  (1,5),  (2,6),  
// 2 -> (0,5),  (3,6),
// 1 -> (0,2),  (3,5),
// 0 -> (1,2),  (2,5),  (3,6),
// ==================================================================================================
// using unordered_map but also diff vetices
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// class Graph {
// public:
//     unordered_map<int, vector<int>> adjList;

//     void addEdge(int u, int v) {
//         adjList[u].push_back(v);
//         adjList[v].push_back(u); // Add this line for an undirected graph
//     }

//     void printAdjList() {
//         for (auto& node : adjList) {
//             cout << node.first << " -> ";
//             for (size_t j = 0; j < node.second.size(); ++j) {
//                 cout << node.second[j];
//                 if (j + 1 < node.second.size()) {
//                     cout << ", ";
//                 }
//             }
//             cout << endl;
//         }
//     }
// };

// int main() {
//     Graph g;

//     g.addEdge(11, 12);
//     g.addEdge(11, 25);
//     g.addEdge(12, 36);
//     g.addEdge(12, 44);
//     g.addEdge(25, 36);
//     g.addEdge(36, 44);

//     g.printAdjList();

//     return 0;
// }
// ============================================================================================
// using array.............................
// #include <iostream>
// #include <vector>
// using namespace std;

// class Graph {
// public:
//     int n;
//     vector<int> adjList[100]; // Assuming a maximum of 100 vertices

//     Graph() : n(0) {}

//     void addEdge(int u, int v) {
//         n = max(n, max(u, v) + 1); // Update the number of vertices
//         adjList[u].push_back(v);
//         adjList[v].push_back(u); // Add this line for an undirected graph
//     }

//     void printAdjList() {
//         for (int i = 11; i < 11 + n; ++i) {
//             cout << i << " -> ";
//             for (size_t j = 0; j < adjList[i].size(); ++j) {
//                 cout << adjList[i][j];
//                 if (j + 1 < adjList[i].size()) {
//                     cout << ", ";
//                 }
//             }
//             cout << endl;
//         }
//     }
// };

// int main() {
//     Graph g;

//     g.addEdge(11, 12);
//     g.addEdge(11, 25);
//     g.addEdge(12, 36);
//     g.addEdge(12, 44);
//     g.addEdge(25, 36);
//     g.addEdge(36, 44);

//     g.printAdjList();

//     return 0;
// }
