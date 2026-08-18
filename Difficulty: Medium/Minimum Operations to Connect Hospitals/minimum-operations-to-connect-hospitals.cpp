class Solution {
  public:
  
  class disjoint{
      public:
      
      vector<int>parent;
      vector<int>size;
      
      disjoint(int n){
          parent.resize(n);
          size.resize(n, 1);
          
          for(int i=0;i<n;i++) parent[i]=i;
      }
      
      int findParent(int i){
          if(i == parent[i]) return i;
          
          return parent[i] = findParent(parent[i]);
      }
      
      void unionBYsize(int u , int v){
          
          int pu = parent[u], pv = parent[v];
          
          if(pu == pv)return;
          if(size[pu] >= size[pv]){
              parent[pv] = pu;
              size[pu]+= size[pv];
          }
          else{
              parent[pu] = pv;
              size[pv]+= size[pu];
          }
      }
  };
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        disjoint ds(V);
        
        int extra_edge=0;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1];
            
            if(ds.findParent(u) == ds.findParent(v)) extra_edge++;
            else ds.unionBYsize(u, v);
        }
        
        int edge_req=0;
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i) edge_req++;
        }
        int x = edge_req-1;
        if(extra_edge < x) return -1;
        
        return x;
    }
};
