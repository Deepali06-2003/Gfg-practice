class DisjointSet {
public:
    vector<int> parent, rankv, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        rankv.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // Find with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    // Union by rank
    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (rankv[pu] < rankv[pv]) {
            parent[pu] = pv;
        }
        else if (rankv[pv] < rankv[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rankv[pu]++;
        }
    }

    // Union by size
    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};


class Solution {
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        DisjointSet ds(n);
        
        int extra =0;
        for(auto e : edges){
            int u = e[0] , v = e[1];
            if(ds.findUPar(u) == ds.findUPar(v)) extra++;
            else ds.unionBySize(u, v);
        }
        
        int component =0;
        for(int i=0;i<n;i++){
            if(i == ds.parent[i]) component++;
        }
        
        if(extra >= (component-1) ) return component-1;
        return -1;
        
    }
};