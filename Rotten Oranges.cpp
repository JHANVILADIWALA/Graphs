https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges

public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        //{{r,c},t}
        //initially adding all rotten ones
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else vis[i][j]=0;
            }
        }
        int tm=0;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,+0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            //traverse neighbours
            for(int i=0;i<4;i++){
                
                    int nrow=r+delrow[i];
                    int ncol=c+delcol[i];
if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]==1&& vis[nrow][ncol]==0){
                     q.push({{nrow,ncol},t+1});
                     vis[nrow][ncol]=2;
                }
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2&&grid[i][j]==1)return -1;
            }
        }
        return tm;
    }
