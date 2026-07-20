class Solution {
  public:
  
  void helper(vector<vector<int>>& image, int sr, int sc, int oldColor,int newColor, int n , int m){
            if(sr<0 || sc<0 || sr>=n || sc>=m || image[sr][sc] != oldColor) return;
                         
            image[sr][sc] = newColor;
            
            helper(image , sr+1, sc, oldColor, newColor, n, m);
            helper(image , sr, sc+1, oldColor, newColor, n, m);
            helper(image , sr-1, sc, oldColor, newColor, n, m);
            helper(image , sr, sc-1, oldColor, newColor, n, m);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // code here
        
        int n = image.size();
        int m = image[0].size();
        
        int oldColor = image[sr][sc];
        if(oldColor == newColor) return image;
        helper(image , sr, sc, oldColor , newColor, n , m);
        
        return image;
    }
};