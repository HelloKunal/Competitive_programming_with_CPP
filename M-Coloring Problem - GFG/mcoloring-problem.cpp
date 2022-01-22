// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool res = false;
vector<int> colors;
void rec(bool graph[101][101], int m, int V, int i) {
    if(i == V) {
        res = true;
        return;
    }
    
    for(int color = 1; color <= m; color++) {
        bool pos = true;
        for(int j = 0; j < V; j++) {
            if(graph[i][j] == 1 && colors[j] == color) {
                pos = false;
                break;
            }
        }
        if(pos) {
            colors[i] = color;
            rec(graph, m, V, i+1);
            colors[i] = 0;
        }
        
        if(res) return;
    }
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    res = false;
    colors.assign(V, 0);
    rec(graph, m, V, 0);
    return res;
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends