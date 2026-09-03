class Disjoint{
    
    public:
    vector<int>parent;
    vector<int>size;
    
    Disjoint(int n){
        parent.resize(n);
        size.resize(n, 1);
        
        for(int i=0;i<n;i++) parent[i]=i;
    }
    
    int FindParent(int n){
        if(n == parent[n]) return n;
        return parent[n] = FindParent(parent[n]);
    }
    
    void UnionSize(int u, int v){
        int pu = FindParent(u) , pv = FindParent(v);
        
        if(pu == pv)return;
        if(size[pu] >= size[pv]){
            parent[pv] =pu;
            size[pu] = size[pu]+size[pv];
        }
        else{
            parent[pu] =pv;
            size[pv] = size[pu]+size[pv];
        }
    }
};

class Solution {
  public:
  
    vector<vector<int>> criticalConnections(int v, vector<vector<int>>& edges) {
        // Code here
     
        vector<vector<int>>res;
        
        for(int skip=0;skip<edges.size();skip++){
            
            Disjoint ds(v);
            for(int j=0;j<edges.size();j++){
                if(j != skip){
                    ds.UnionSize(edges[j][0], edges[j][1]);
                }
            }
            
            if(ds.FindParent(edges[skip][0]) != ds.FindParent(edges[skip][1])){
                res.push_back({edges[skip][0], edges[skip][1]});
            }
        }
        
        return res;
        
    }
};