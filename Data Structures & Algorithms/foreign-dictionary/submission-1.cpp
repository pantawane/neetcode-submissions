class Solution {
private:
    vector<int> topologicalSort(vector<vector<int>> &adj, vector<int> &present) {

        vector<int> indegree(26, 0);

        // Calculate indegree
        for (int i = 0; i < 26; i++) {
            for (auto neighbour : adj[i]) {
                indegree[neighbour]++;
            }
        }

        queue<int> q;

        // Push only present characters having indegree 0
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            topo.push_back(front);

            for (auto neighbour : adj[front]) {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return topo;
    }

public:
    string foreignDictionary(vector<string>& words) {

        vector<vector<int>> adj(26);
        vector<int> present(26, 0);

        // Mark all characters present
        for (auto word : words) {
            for (char ch : word) {
                present[ch - 'a'] = 1;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            int ptr = 0;
            while (ptr < len && s1[ptr] == s2[ptr])
                ptr++;

            // Invalid prefix case
            if (ptr == len && s1.size() > s2.size())
                return "";

            // First different character
            if (ptr < len) {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
            }
        }

        vector<int> topo = topologicalSort(adj, present);

        // Count total unique characters
        int cnt = 0;
        for (int x : present)
            if (x)
                cnt++;

        // Cycle exists
        if (topo.size() != cnt)
            return "";

        string ans = "";

        for (auto node : topo) {
            ans += char(node + 'a');
        }

        return ans;
    }
};