/*
[[0,1],[1,2],[2,0],[1,3]]

0 : 1, 2
1 : 0, 2, 3
2 : 1, 0
3 : 1

0 : 1, 2
1 : 0, 2
2 : 1, 0
3 :

*/

class Solution {
    vector<unordered_set<int>> graph;
    bool isCriticalConnection(int n, vector<vector<int>>& connections, int lostConnection)
    {
        bool critical = true;
        vector<bool> visited(n , false);
        queue<int> q;
        int node_a = connections[lostConnection][0];
        int node_b = connections[lostConnection][1];
        graph[node_a].erase(node_b);
        graph[node_b].erase(node_a);
        // check if node_a still connected to node_b
        q.push(node_a);
        visited[node_a] = true;
        while (critical && !q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto &i : graph[node])
            {
                if (!visited[i])
                {
                    if (i == node_b)
                    {
                        critical = false;
                        break;
                    }
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        graph[node_a].insert(node_b);
        graph[node_b].insert(node_a);
        return critical;
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> sol;
        graph.resize(n);
        for (auto &connection : connections)
        {
            graph[connection[0]].insert(connection[1]);
            graph[connection[1]].insert(connection[0]);
        }
        for (int i = 0; i < connections.size(); ++i)
        {
            if (isCriticalConnection(n, connections, i))
            {
                sol.emplace_back(connections[i]);
            }
        }
        return sol;
    }
};
