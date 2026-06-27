class Solution {
private:
    void dfs(int node, vector<int> &visited, unordered_map<int, list<int>> &adj){
        visited[node] = 1;

        for(auto neighbour : adj[node]){
            if(visited[neighbour] == 0){
                dfs(neighbour, visited, adj);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //create adj list
        unordered_map<int, list<int>> adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //create visited array
        vector<int> visited(n);
        int counter = 0;

        //do dfs
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                counter++;
                dfs(i, visited, adj);
            }
        }
        return counter;
    }
};
