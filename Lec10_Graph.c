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


// Graph Search
// 1. BFS(Breadth First Search) : queue
// 2. DFS(Depth First Search) : stack

// DFS : Depth first search
    // 한방향으로 가고, 더 이상 못가면 go back
    // go back을 위해 stack 사용
    // Time Complexity : O(|V| + |E|)  - vertex 개수만큼 방문, edge수 만큼 check.
void dfs_mat(GraphType *g, int v){
    int w;
    visited[v] = TRUE; //mark v as visited
    for(w =0; w<g->n; w++){  //search adjacent nodes
        if(g->adj_mat[v][w] && !visited[w]){
            dfs_mat(g, w);
        }
    }
}

void dfs_list(GraphType *g, int v){
    GraphNode *w;
    visited[v] = True;
    for(w = g->adj_list[v]; w; w = w->link]){
        if(!visited[w->vertex]){
            dfs_list(g, w->vertex);
        }
    }
}


// BFS : Breadth first search
    // using Queue, visiting all the neighbors
    // 순서 : 한개 꺼내서 모든 인접 노드 큐에 넣기
        // 이동하면서 queue에서 빼고 반복.
    //** visit로 체크하면서 큐에 넣는다.
    //** 큐에서 빼면서 이동한다.
    // Time Complexity : O(|V| + |E|)  
    //-> vertex 개수만큼 queue에 넣음, edge수 만큼 check.

void bfs_mat(GraphType *g, int v) {
    int w;
    QueueType q;
    init(&q); 
    visited[v]= TRUE;
    enqueue(&q, v); //insert v in queue
    while(!is_empty(&q)){
        v = dequeue(&q);
        for(w=0; w< g->n; w++){
            if(g->adj_mat[v][w]) && !visited[w]){
                visited[w] = TRUE;
                enqueue(&q, w);
            }
        }
    }
}

void bfs_list(GraphType *g, int v) {
    GraphNode *w;
    QueueType q;
    init(&q);
    visited[v] = TRUE;
    printf("%d ", v);
    enqueue(&q, v);
    while(!is_empty(&q)){
        v = dequeue(&q);
        for(w=g->adj_list[v]; w; w=w->link){
            if(!visited[w->vertex]){
                visited[w->vertex] = TRUE;
                enqueue(&q, w->vertex);


            }
        }
    }

//ㅊ