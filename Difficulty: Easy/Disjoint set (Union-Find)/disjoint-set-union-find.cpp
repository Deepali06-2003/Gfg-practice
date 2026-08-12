class Disjoint{
  
  public:
  vector<int>parent;
  vector<int>size;
  
  Disjoint(int n){
      parent.resize(n+1);
      size.resize(n+1, 1);
      for(int i=0;i<=n;i++) parent[i]=i;
  }
  
  int FindUParent(int n){
      if(parent[n] == n) return n;
      return parent[n] = FindUParent(parent[n]);
  }
  
  void UnionBySize(int u, int v){
      int up = FindUParent(u);
      int vp  =FindUParent(v);
      
      if(up == vp) return;
      
      /*if(size[up] > size[vp]){
          parent[vp] = up;
          size[up] += size[vp];
      }
      else{
          parent[up] = vp;
          size[vp] += size[up];
      }*/
      
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
        
        for(auto i: queries){
            int x = i[0];
            
            if(x == 1){
                ds.UnionBySize(i[1], i[2]);
            }
            else{
                res.push_back(ds.FindUParent(i[1]));
            }
        }
        
        return res;
    }
};