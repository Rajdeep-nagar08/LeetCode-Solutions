class Solution {
public:
    int visited[100][100]; 
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(visited[sr][sc]==0){
        visited[sr][sc]=1;
        int parent=image[sr][sc];
        image[sr][sc]=newColor;
        if(sc>0 && image[sr][sc-1]==parent){
            floodFill(image,sr,sc-1,newColor);
        }
         if(sc+1<image[0].size() && image[sr][sc+1]==parent){
            floodFill(image,sr,sc+1,newColor);
        }
         if(sr-1>=0 && image[sr-1][sc]==parent){
            floodFill(image,sr-1,sc,newColor);
        }
         if(sr+1<image.size() && image[sr+1][sc]==parent){
            floodFill(image,sr+1,sc,newColor);
        }
        }
        return image;
    }
};