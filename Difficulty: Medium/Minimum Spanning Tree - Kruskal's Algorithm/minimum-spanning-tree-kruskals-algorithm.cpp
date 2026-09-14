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
      int up = FindParent(u);
      int vp = FindParent(v);
      
      if(up == vp) return;
      
      if(size[up]>size[vp]){
          parent[vp] = up;
          size[up] += size[vp];
      }
      
      else{
           parent[up] = vp;
          size[vp] += size[up];
      }
  }
};


class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        
        sort(edges.begin(), edges.end(),
                     [](vector<int>& a, vector<int>& b) {
                         return a[2] < b[2];
                     });

                Disjoint ds(V);

                int sum = 0;
                int count = 0;

                for (int i = 0; i < edges.size(); i++) {

                    int u = edges[i][0];
                    int v = edges[i][1];
                    int wt = edges[i][2];

                    // If they already belong to same component,
                    // this edge creates a cycle
                    if (ds.FindParent(u) == ds.FindParent(v))
                        continue;

                    ds.UnionSize(u, v);
                    sum += wt;
                    count++;

                    // MST has V-1 edges
                    if (count == V - 1)
                        break;
                }

                return sum;
    }
};