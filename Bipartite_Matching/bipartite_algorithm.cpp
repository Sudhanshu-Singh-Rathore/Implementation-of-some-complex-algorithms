// C++ program for implementation of bipartite algorithm usign Ford Fulkerson algorithm as a black box.
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
 
// Number of vertices in given graph
#define U 12
#define V 14
 
/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}
 
// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
 
    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    int rGraph[V][V]; // Residual graph where rGraph[i][j] indicates 
                     // residual capacity of edge from i to j (if there
                     // is an edge. If rGraph[i][j] is 0, then there is not)  
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
 
    int parent[V];  // This array is filled by BFS and to store path
 
    int max_flow = 0;  // There is no flow initially
 
    // Augment the flow while tere is path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 
        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
    }
 
    // Return the overall flow
    return max_flow;
}
 
// Driver program to test above functions
int main()
{
    // Let us create a graph shown in the above example
    int pgraph[U][U] = { {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                      };
   
    int ngraph[V][V];
    for(int u=0;u<V;u++){
    for(int v=0;v<V;v++){
     if(v==0 or u==13){
     ngraph[u][v]=0;
}
     else if(u==0 and v<=U/2 and v>u){
     ngraph[u][v]=1;
}
   else if(v==13 and u>U/2 and u<V-1){
     ngraph[u][v]=1;
}
    else if(u>0 and v>0 and u<=U and v<=U){
    ngraph[u][v]=pgraph[u-1][v-1]; }  
   else{
    ngraph[u][v]=0;


}
}
}
    /*for(int v=0;v<U;v++){
    for(int u=0;u<U;u++){
    if(pgraph[u][v]==0){
    flag1=1;
     
    }
    else{flag1=0;}
    if(pgraph[u][v]==1){
    if(u==v or pgraph[v][u]==1){
    flag1=1;
    
 }
    else{flag1=0;}
   
    }
    }
     if(flag1==1){ngraph[0][v+1]=1;}
    }
 
     for(int u=0;u<U;u++){
    for(int v=0;v<U;v++){
    if(pgraph[u][v]==0){
    
     flag2=1;
}
   else{flag2=0;}
    if(pgraph[u][v]==1){
    if(u==v or pgraph[v][u]==1){
    
    flag2=1;
}
else{flag2=0;}
}
}
  if(flag2==1){ngraph[u+1][7]=1;}
}*/
  

 
    cout << "The maximum possible flow is " << fordFulkerson(ngraph, 0, 13);
 
    return 0;
}
