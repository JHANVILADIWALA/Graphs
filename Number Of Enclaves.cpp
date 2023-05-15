https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves

private:
    void dfs( int row,int col, vector<vector<int>>&vis,vector<vector<int>> &mat ){
        
        vis[row][col]=1;
        int n=mat.size(),m=mat[0].size();
        //neighbours 
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] 
           && mat[nrow][ncol]==1)
            dfs(nrow,ncol,vis,mat);
        }
        
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        //first row
        for(int j=0;j<m;j++){
            if(mat[0][j]==1 &&!vis[0][j]){
                dfs(0,j,vis,mat);
            }
        }
        //last row
        for(int j=0;j<m;j++){
            if(mat[n-1][j]==1&&!vis[n-1][j]){
                dfs(n-1,j,vis,mat);
            }
        }
        //first col
        for(int i=0;i<n;i++){
            if(mat[i][0]==1&&!vis[i][0]){
                dfs(i,0,vis,mat);
            }
        }
        //last col
        for(int i=0;i<n;i++){
            if(mat[i][m-1]==1&& !vis[i][m-1]){
                dfs(i,m-1,vis,mat );
            }
        }
        int ckt=0;
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(!vis[i][j] && mat[i][j]==1){
                     ckt++;
                 }
             }
         }
         return ckt;
    }
