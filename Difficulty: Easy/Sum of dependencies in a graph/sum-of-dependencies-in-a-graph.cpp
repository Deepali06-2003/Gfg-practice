//Back-end complete function Template for C++

class Solution {
  public:
    // Function to calculate the sum of dependencies.
    int sumOfDependencies(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        int sum=0;
        for(int i=0;i<V;i++){
            int c=0;
            for(auto j: adj[i]){
                c++;
            }
            sum = sum + c;
        }
        
        return sum;
    }
};