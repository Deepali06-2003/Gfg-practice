class Disjoint{
  public:
  
  vector<int>parent , size, rank;
  
  Disjoint(int n){
      parent.resize(n+1);
      size.resize(n+1, 1);
      rank.resize(n+1, 0);
      
      for(int i=0;i<=n;i++) parent[i]=i;
  }
  
  int findUParent(int n){
      if(n == parent[n]) return n;
      
      return parent[n] = findUParent(parent[n]);
  }
  
  void UnionByRank(int u, int v){
      int up = findUParent(u);
      int vp = findUParent(v);
      
      if(up == vp) return;
      
      if(rank[up] > rank[vp]){
          parent[vp]= up;
      }
      else if(rank[up]< rank[vp]){
          parent[up]= vp;
      }
      else{
          parent[vp]= up;
          rank[up]++;
      }
  }
  
  void UnionBySize(int u, int v){
      int up = findUParent(u);
      int vp = findUParent(v);
      
      if(up == vp) return;
      /*
      if(size[up]>= size[vp]){
          parent[vp]= up;
          size[up]+=size[vp];
      }
      
      else{
          parent[up]= vp;
          size[vp]+=size[up];
      }
      */
      parent[up] = vp;
      size[vp] += size[up];
  }
  
};

class Solution {
  public:
  
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        // code here
        Disjoint ds(n);
        
        vector<int>res;
        for(int i=0;i<queries.size();i++){
            int u = queries[i][0] , v = queries[i][1];
            
           if(u == 1){
               int z = queries[i][2];
               ds.UnionBySize(v, z);
           }
           else{
               int x = ds.findUParent(v);
               res.push_back(x);
           }
        }
        
        return res;
        
    }
};

