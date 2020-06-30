//Floyd Warshall
dp[i][i] = 0
otherwise INF
 
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}
 
/*
>> Floyd neg edge
However if there are negative weight edges in the graph, special measures have to be taken. 
Otherwise the resulting values in matrix may be of the form ∞−1, ∞−2, etc., which, of course, 
still indicates that between the respective vertices doesn't exist a path. Therefore, if the graph 
has negative weight edges, it is better to write the Floyd-Warshall algorithm in the following way, 
so that it does not perform transitions using paths that don't exist.
*/
 
dp[i][i] = 0
otherwise INF
 
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}
