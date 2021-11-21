# Graph
Graph is a data structure that consists of Vertices(Node) and Edges. The number of edge that is connected to Vertex is the degree of Vertex. Graphs are used in many ways such as finding shortest path or representing connection between multiple objects. Edges may contain weight or direction.

# Representation
 ## 1.Using Adjacency Matrix
  Let's say each node was labelled as N where N is integer. Let 2D array mat[][] represents Adjcency Matrix, and mat[i][j] store 1 or 0 depending on the connection status of node i and j. mat[i][j] = 1 indicates node i and j are connected with an edge. In case of undirected graph, mat[i][j] will always be same as mate[j][i] therefore Adjacency Matrix of undirected graph is symmetric.
  For directed graph, mat[i][j] indicates there is an edge from node i to j, but it doesn't necessarily means that there is an edge from node to j to i. 
  ### Directed Graph
  
  ```
  int adj_matrix[10][10] = {};
  int v, e;
  cin >> v >> e;
  for(int i = 0; i < e; i++)
  {
    int u, v;
    cin >> u >> v;
    adj_matrix[u][v] = 1;
  }
  ```
  ### Undirected Graph
  
  ```
  int adj_matrix[10][10] = {};
  int v, e;
  cin >> v >> e;
  for(int i = 0; i < e; i++)
  {
    int u, v;
    cin >> u >> v;
    adj_matrix[u][v] = 1;
    adj_matrix[u][v] = 1;
  }
  ```
  ## 2.Using Adjacency List
  Another way of representing graphs is using Adjacency List. We can benefit a lot from this way in terms of space complexity when V is large and E is relatively small. To represent graphs with list, we basically make V lists where V is the number of vertices, and ith list contains the vertex that is connected to the vertex i.

  ### Directed graph
  ```
  vector<int> adj[10];
  int v, e;
  cin >> v >> e;
  for(int i = 0; i < e; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  ```
  ### Undirected graph
  ```
  vector<int> adj[10];
  int v, e;
  cin >> v >> e;
  for(int i = 0; i < e; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ```
||Martrix|List|
|---|---|---|
|Space complexity|O(V^2)|O(V+E)|
|Time complexity of checking whether node u and v are connected|O(1)|O(min(deg(u), deg(v)))|
|Time complexity of checking all the nodes that is connected to a specific node|O(V)|O(deg(v))|
|Effective case|1. When frequent check of connection between two nodes is required </br> 2. When E is close to V^2|1. When frequent check of all the nodes that is connected to a specific node</br> 2. When E is way smaller than V^2|

# BFS

## Process of BFS
* 1. Set the starting vertex and mark it as visited and place it in the queue.
* 2. mark top element of queue as current node and remove it from queue find all the nodes unvisited && connected to the current node.
* 3. mark them as visited and insert them in the queue.
* 4. repeat the step from 2 to 3
* when we assume all the verticies are reachable from the starting vertex, each vertex will be inserted in queue exactly once. Therefore, O(V+E) for list and O(V^2) for matrix.
## Implementation of BF traveral for connected graph
```
vector<int> adj[10];
bool vis[10];
queue<int> q;
vis[1] = true;
q.push(1);
while(!q.empty())
{
  int cur = q.top();
  q.pop();
  cout << cur;
  for(int i = 0; i < adj[cur].size(); i++)
  {
    if(vis[adj[cur][i]]) continue;
    vis[i] = true;
    q.push(adj[cur][i]);
  }
}
```
## Implementation of algorithm that finds the distance from the starting node using BFS

```
vector<int> adj[10];
int dis[10];
for(int i = 0; i < 10; i++) dis[i] = -1;
queue<int> q;
dis[1] = 0;
q.push(1);
while(!q.empty())
{
  int cur = q.top();
  q.pop();
  cout << cur;
  for(int i = 0; i < adj[cur].size(); i++)
  {
    if(dis[adj[cur][i]] != -1) continue;
    dis[i] = dis[cur]] + 1;
    q.push(adj[cur][i]);
  }
}
```

# DFS

## Process of DFS
* 1. Set the starting vertex and mark it as visited and place it in the stack.
* 2. mark top element of queue as current node and remove it from stack find all the nodes that are unvisited && connected to the current node.
* 3. mark them as visited and insert them in the stack.
* 4. repeat the step from 2 to 3
* when we assume all the verticies are reachable from the starting vertex, each vertex will be inserted in stack exactly once. Therefore, O(V+E) for list and O(V^2) for matrix.

## Implementation of BF traveral for connected graph using stack STL
```
vector<int> adj[10];
bool vis[10];
stack<int> s;
vis[1] = true;
s.push(1);
while(!s.empty())
{
  int cur = s.top();
  q.pop();
  cout << cur;
  for(int i = 0; i < adj[cur].size(); i++)
  {
    if(vis[adj[cur][i]]) continue;
    vis[i] = true;
    s.push(adj[cur][i]);
  }
}
```
## Implementation of BF traveral for connected graph using recursion
```
vector<int> adj[10];
bool vis[10];
vis[1] = true;
dfs(1);
void dfs(int a)
{
  cout << a;
  for(int i = 0; i < adj[a].size(); i++)
  {
    if(vis[adj[a][i]] == true) continue;
    vis[adj[a][i]] = true;
    dfs(adj[a][i]);
  }
}
```