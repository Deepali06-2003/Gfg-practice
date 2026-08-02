class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<long long> dist(V, LLONG_MAX);

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if (dist[u] != LLONG_MAX && dist[u] + wt < dist[v]) {

                dist[v] = dist[u] + wt;
            }
        }
    }

    // Negative cycle check
    for (auto &e : edges) {

        int u = e[0];
        int v = e[1];
        int wt = e[2];

        if (dist[u] != LLONG_MAX && dist[u] + wt < dist[v]) {

            return {-1};
        }
    }

    vector<int> ans(V);

    for (int i = 0; i < V; i++) {

        if (dist[i] == LLONG_MAX)
            ans[i] = 100000000;   // or any value required by the problem
        else
            ans[i] = (int)dist[i];
    }

    return ans;
    }
};
