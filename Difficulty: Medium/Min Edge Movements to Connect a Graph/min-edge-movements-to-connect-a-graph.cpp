class Disjoint{
    public:
    
    vector<int>parent, size;
    
    Disjoint(int n){
        parent.resize(n, 0);
        size.resize(n , 1);
        
        for(int i=0;i<n;i++) parent[i] = i;
    }
    
    int FindParent(int n){
        if(parent[n] == n) return n;
        
        return parent[n] = FindParent(parent[n]);
    }
    
    void UnionBySize(int u, int v){
        int pu = parent[u], pv = parent[v];
        
        if(pu == pv) return;
        else if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] = size[pu] + size[pv];
        }
        
        else{     //if size[pv] >= size[pu] -> then ultimate parent of pu is updated
            parent[pu] = pv;
            size[pv] = size[pv] + size[pu];
        }
    }
};


class Solution {
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        
        Disjoint ds(n);
        
        int extra_e=0;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1];
            
            if(ds.FindParent(u) == ds.FindParent(v)) extra_e++;
            else ds.UnionBySize(u, v);
        }
        
        int req_e=0;
        for(int i=0;i<n;i++){
            if(i == ds.parent[i]) req_e++;
        }
        
        if(extra_e >= req_e-1) return req_e-1;
        return -1;
    }
};