int V, E, dis[N];
int graph[N][3]; // src->dist weight
 
void bellmanford(int src){
 
    for (int i = 0; i < V; i++) 
        dis[i] = BINF; 
    dis[src] = 0; 
    
    for (int i = 0; i < V - 1; i++) { 
        for (int j = 0; j < E; j++) { 
            if (dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]]) 
                dis[graph[j][1]] =  dis[graph[j][0]] + graph[j][2]; 
        } 
    } 
    for (int i = 0; i < E; i++) { 
        int x = graph[i][0]; 
        int y = graph[i][1]; 
        int weight = graph[i][2]; 
        if (dis[x] != BINF and dis[x] + weight < dis[y]) 
            cout << "Graph contains negative weight cycle" << endl; 
    } 
} 
