-   Learning
    -   Some Terms
        -   Nodes/Vertex, Edges, Cycles, Directed, Undirected, Edge Weights(if not assigned assume 1)
        -   Path (Each node can only be included once and all nodes should be reachable to each other)
        -   Degree of a Node (Number of Edges Attached to it)
        -   Total Degree of a Graph = 2 * (No.of.Edges)
            -   why ? bcoz Every Edge connected with 2 Nodes
        -   In Directed there is an indegree and outdegree
            -   Indegree : Incoming Edges
            -   OutDegree : outgoing Edges
        -   Connected Component : A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
    -   Representation
        -   given N nodes, M edges and will give an arry of M edges
            -   2,1,(1,2)
        -   Adjacency Matrix : n*n matrix and if edge exist between 2 then 1 else 0
        -   Adjacency Lists : an size of vector n where each idx represents a node and its vector will contain all other nodes which the vertex has an edge to
        -   In case of weighted graphs for adjacency matrix instead of 1 give the weight value and for adjacency lists there should be pairs of vectors where first is node that edge connects and second is weight for that Edge
    -   Traversal
        -   BFS in connected Graph
        -   BFS in Disconnected Graph
        | Aspect                           | BFS                        | DFS                        |
        | -------------------------------- | -------------------------- | -------------------------- |
        | Strategy                         | Level-order (breadth-wise) | Depth-first (backtracking) |
        | Data Structure                   | Queue (FIFO)               | Stack / Recursion          |
        | Time Complexity                  | `O(V + E)`                 | `O(V + E)`                 |
        | Space Complexity                 | `O(V + E)` (queue + adj)   | `O(V + E)` (stack + adj)   |
        | Shortest Path (Unweighted Graph) | ✅ Yes                      | ❌ No guarantee          |
-   Problems on BFS/DFS
    1.  connected Components : https://leetcode.com/problems/number-of-provinces/
    2.  Connected Components Adj Lists : https://takeuforward.org/plus/dsa/problems/connected-components
    3.  Rotten Oranges : https://leetcode.com/problems/rotting-oranges/description/
    4.  Flood Fill : https://leetcode.com/problems/flood-fill/description/
    5.  Detect Cycle BFS : https://takeuforward.org/plus/dsa/problems/detect-a-cycle-in-an-undirected-graph
    6.  Detect Cycle DFS : https://takeuforward.org/plus/dsa/problems/detect-a-cycle-in-an-undirected-graph
    7.  Nearest Cell with 0 : https://leetcode.com/problems/01-matrix/description/
    8.  Surround Capture : https://leetcode.com/problems/surrounded-regions/description/
    9.  Enclave Point : https://leetcode.com/problems/number-of-enclaves/description/
    10. Word Ladder : https://leetcode.com/problems/word-ladder/
    11. Word Ladder 2 : https://leetcode.com/problems/word-ladder-ii/
        -   BFS 
        -   BFS_DFS BackTracking optimized
    12. Distinct Island : https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
    13. Bipartite : https://leetcode.com/problems/is-graph-bipartite/description/
    14. Detect cycle in Directed Graph : https://takeuforward.org/data-structure/detect-cycle-in-a-directed-graph-using-dfs-g-19/
-   Topological sort
    -   It only Exists in DAG (Directed Acyclic Graph)
    -   Linear Ordering of Vertices such that if there is an Edge between u & v, u appears before v in that ordering (u -> v)
    1.  Topological Sort
    2.  Kahn's Algo (BFS Based topological sort)
    3.  Cycle Detection in Directed Graph using Kahn's Algo
    4.  Course Schedule 1 : https://leetcode.com/problems/course-schedule/
    5.  Course Schedule 2 : https://leetcode.com/problems/course-schedule-ii/description/
    6.  Find Eventual Safe state : https://leetcode.com/problems/find-eventual-safe-states/
    7.  Alien Dictionary : https://www.geeksforgeeks.org/problems/alien-dictionary/1
-   Shortest Path Problem
    1.  Min Distance in Undirected Graph with Unit Distance : https://takeuforward.org/data-structure/shortest-path-in-undirected-graph-with-unit-distance-g-28/
    2.  DAG with weighted edges : https://takeuforward.org/data-structure/shortest-path-in-directed-acyclic-graph-topological-sort-g-27/
    3.  Dijkstra Algorithm : https://takeuforward.org/data-structure/dijkstras-algorithm-using-set-g-33/
        -   pq approach or set approach (In Implementation)
        -   Do Not work on Negative Weights or Negative Cycles
        -   ElogV
        -   Why Not queue? -> it will give answers but it will follow unnecessary paths also and will Increase time complexity
    4.  Print shortest Path in Dijkstra : https://www.youtube.com/watch?v=rp1SMw7HSO8&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=36
    5.  Binary Maze : https://leetcode.com/problems/shortest-path-in-binary-matrix/
    6.  Path Min Effort : https://leetcode.com/problems/path-with-minimum-effort/
    7.  Cheapest Flight : https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
        1.  Dijkstra Way: In this dijkstra we still want to relax even if the dist is more but steps is less so we carry a stops Array
        2.  BFS Way : In this we find all possible way to relax the node under k stops through tracking cost in stack (Imp). bcoz in bfs will reach a node with min number of steps so only relaxation check here if if cost is lesser
    8.  Network Delay : https://leetcode.com/problems/network-delay-time/description/
    9.  Number of shortest Path : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
    10. Minimum steps to reach end from source : https://takeuforward.org/graph/g-39-minimum-multiplications-to-reach-end/
    11. Bellman Ford -  shortest path from src to all edges
        -   Advantage over Dijkstra is that it will work on -ve edge and -ve cycle
        -   Only work on Directed Graph
        -   In Undirected Graph, undirected edge converted to Directed like (1-2) === (1->2,2->1)
        -   Relax Edges n-1 times in any order, if in nth time the edge still relaxes then it have -ve cycle
    12. Floyd Warshall : It is a Multisource Shortest Path Alfo
        -   Also detect negative cycle in Graph
        -   Same for undirected convert to directed graph
    13. City Neighbours : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
-   Minimum Spanning Tree
    -   Spanning Tree : A tree in which we have N nodes and N-1 Edges where all nodes are reachable from Each Other.
    -   When we convert a Graph to a spanning Tree we can remove any Edges which can result in many different Spanning Trees
    -   the spanning Tree which we got from graph after removing edges which has the lowest cost among all other trees is Minmum Spanning tree (cost is the sum of weights of remaining Edges)
    1.  Prims Algorithm : start from src : 0 and select minimum edges from there
    2.  Disjoint Set by Rank and Size(Size preffered as more intuitive)
        -   time complexity for both union and parent is O(4alpha) which is near to constant - highly mathematical
    3.  Kruskal Algo : use dsu and pick minimum weighted Edges only make sure there parent is not same
    4.  Number of Disconnected Components using DSU
    5.  Connections : https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
        -   we can also do this by visited and bfs/dfs
    6.  Remove Stones : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
    7.  Accounts Merge : https://leetcode.com/problems/accounts-merge/
    8.  Island 2 : https://takeuforward.org/plus/dsa/problems/number-of-islands-ii
    9.  Large Island : https://leetcode.com/problems/making-a-large-island/
    10. Swim in Water : https://leetcode.com/problems/swim-in-rising-water/
-   Other Algorithms
    -   Bridges in Graph : An edge is called a bridge if removing it increases the number of connected components of the graph.
    1.  Tarjan's Algorithm for Bridges : https://leetcode.com/problems/critical-connections-in-a-network/description/
    2.  Articulation Point : If removing a vertex disconnects the graph, it is an articulation point.
        -   Algorith is same as tarjans but some thing changes
            -   instead of (low[it] > tin[node]) ===> (low[it] >= tin[node])
                why? because even if they are equal there cannot be path as we are removing vertex rather than Edge
            -   Also root node condn is diff (low[it] >= tin[node] && parent != -1), (parent == -1 && child > 1)
                why? because root can only be AP if it has more than 1 children node
            -   Why we use a separate boolean array isAP
                -   Avoid duplicates: A node might satisfy the condition for multiple children. We only want to mark it once.
                -   Root node special case: The root is an AP only if it has more than 1 child. Using a separate array allows checking this after DFS.
    -   Strongly Connected Components : A maximal subset of vertices such that every vertex in the subset is reachable from every other vertex in the subset.
        -   It is only Available in Directed Graphs 
    3.  Kosaraju Algo for SCC 
        -   sort the Edges in terms of finishing time
        -   reverse the edges
        -    do dfs and store the scc