//  Definition 
    // Vertex == node
    // Edge == link
    // Undirected graph = bidirectional = (A, B)
    // Directed graph = One way = <A,B>

// Degree of Graph
    // Adjacent vertex: edges로 directly connected된 vertices
    // Degree
        // num of edges at each node
        // sum of degrees == edges *2 (양쪽 왔다갔다) == 2|E|
    // Degree of directed graph
        // In-degree : 들어오는 edge --> sum of In-degree = |E|
        // Out-degree : 나가는 edge --> sum of Out-degree = |E|

// Path of Graph 
    // Path : 예를 들어 0-1-2-3일 때, 그 길이 있으면(connected면)
    // Simple Path : edge 다시 안 밟고 path가 있음 <-> Non simple path
    // Cycle : 제자리로 (0-1-2-0)

// Connectivity of Graph
    // Connected Graph : vertex 사이에 항상 길이 있을 때
    // Tree : connected graph, but no cycles
    // Complete graph : All vertieces connected fully --> undirected complete graph (모든 edge 연결)
    // num of edges = n*(n-1)/2 (n이 vertex 개수)


// Adjacency Matrix
    // edge(i,j), M[i][j] = 1 , 아니면 0
    // undirected면 symmetric하게 1일 것.

    typedef struct GraphType {
        int n;// The number of vertices
        GraphNode *adj_mat[MAX_VERTICES][MAX_VERTICES];
        } GraphType;
    





// Adjacency List
    // each vertex에 linked list 달기.
    // 0 -> 1, 2, 3 link
    // 1-> 0, 2 link (이런 식으로..)
    // undirected면 symmetric


