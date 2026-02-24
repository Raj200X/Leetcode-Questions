class Solution {
public:
    void dfs(vector<vector<int>>& image,int i, int j,int OriginalColor,int ModifiedColor){
        if (i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=OriginalColor){
            return;
        }
        image[i][j] = ModifiedColor;
        dfs(image,i-1,j,OriginalColor,ModifiedColor); // top
        dfs(image,i+1,j,OriginalColor,ModifiedColor); // bottom
        dfs(image,i,j-1,OriginalColor,ModifiedColor); // left
        dfs(image,i,j+1,OriginalColor,ModifiedColor); // right

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int Originalcolor=image[sr][sc];
        if (Originalcolor == color) return image;
        dfs(image,sr,sc,Originalcolor,color);
        return image;
    
    }
};