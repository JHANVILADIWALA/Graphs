https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs

private:
    void dfs( int row,int col, vector<vector<int>>&vis,vector<vector<char>> &mat ){
        //traverse for 0 ka pura component and mark as never possible
        //visited---->never possible
        // therefore just visit
        vis[row][col]=1;
        int n=mat.size(),m=mat[0].size();
        //neighbours 
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] 
           && mat[nrow][ncol]=='O')
            dfs(nrow,ncol,vis,mat);
        }
        
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {   //IF ANY ZERO OF THAT COMPONENT IS ON BOUNDARY
        //THEN IT CAN'T BE CONVERTED
        //n row
        //m col
        //start from boundary zeroes and mark they will not be converted
        // convert remaining zeroes
        //dfs, can use bfs too
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        //first row
        for(int j=0;j<m;j++){
            if(mat[0][j]=='O' &&!vis[0][j]){
                dfs(0,j,vis,mat);
            }
        }
        //last row
        for(int j=0;j<m;j++){
            if(mat[n-1][j]=='O'&&!vis[n-1][j]){
                dfs(n-1,j,vis,mat);
            }
        }
        //first col
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O'&&!vis[i][0]){
                dfs(i,0,vis,mat);
            }
        }
        //last col
        for(int i=0;i<n;i++){
            if(mat[i][m-1]=='O'&& !vis[i][m-1]){
                dfs(i,m-1,vis,mat );
            }
        }
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(!vis[i][j] && mat[i][j]=='O'){
                     mat[i][j]='X';
                 }
             }
         }
         return mat;
        
    }
