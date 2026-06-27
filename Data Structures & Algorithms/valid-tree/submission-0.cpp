class Solution {
private:
   bool cycleBfs(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){
    //create parent
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = true;

    //create queue
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //traverse through all neighbours
        for(auto neighbour: adj[frontNode]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
                q.push(neighbour);
            }else if(neighbour != parent[frontNode]){
                return true;  //cycle found
            }
        }
    }
    return false;

   }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //A tree must have exactly n-1 edges
        if(edges.size() != n-1)
        return false;

        //create adj list
        unordered_map<int, list<int>> adj;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;

        if(cycleBfs(0, visited, adj))
        return false;

        //connection
       for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }
};
