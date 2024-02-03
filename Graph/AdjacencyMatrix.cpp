#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n;
    cout << "Enter Number Of Node : ";
    cin >> n;

    vector<vector<int>> adj(n,vector<int>(n,0));  
    int e;
    cout << "Enter Number Of Edge : ";
    cin >> e;

    for(int i=0; i<e; i++){
        int u,v;
        cin >> u >> v;

        adj[u][v] = 1;
    }

    for(int i=0;i<n; i++){
        for(int j=0;j<n;j++){
            cout << adj[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}

// Enter Number Of Node : 4
// Enter Number Of Edge : 8
// 0 1
// 0 2
// 1 2
// 1 3
// 1 0
// 2 0
// 2 1
// 3 1
// 0  1  1  0  
// 1  0  1  1  
// 1  1  0  0  
// 0  1  0  0  